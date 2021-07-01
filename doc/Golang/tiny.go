package main

import (
	"bytes"
	"errors"
	"fmt"
	json "github.com/pquerna/ffjson/ffjson"
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
	"heyong/ecommerce/test/heyong/qt/model"
	"io"
	"io/ioutil"
	"net/http"
	"net/url"
	"os"
	"path/filepath"
	"runtime"
	"sync"
	"time"
)

type Setting struct {
	Email  string
	ApiKey string
}

type LocalResourceItem struct {
	Root  string
	Path  string
	Row   int
	Url   string
	Ssize int64
	Nsize int64
}

type compressResultMsg struct {
	err  error
	item *LocalResourceItem
}

type Tinypng struct {
	waiter         *sync.WaitGroup
	console        *widgets.QTextBrowser
	compressingUrl string
	curNode        int
	resultChans    chan compressResultMsg
	tableview      *MyTableView
	Tinykey        *model.Key
	outputMode int
}

func RunTiny(console *widgets.QTextBrowser, Tinykey *model.Key, tableview *MyTableView) {

	if MODEL.RowCount(core.NewQModelIndex()) == 0 {
		console.Append("<font color=\"#FF0000\">没有可压缩的文件</font>")
		return
	}

	var ch = make(chan *LocalResourceItem, 1)
	CPU := runtime.NumCPU()
	runtime.GOMAXPROCS(CPU)
	var wait = &sync.WaitGroup{}
	wait.Add(CPU)

	curSetting := Tinykey.Get()
	fmt.Println(curSetting)
	Email := curSetting.Mail
	ApiKey := curSetting.Key


	var transport *http.Transport
	if len(curSetting.Proxy)>0 {
		Proxy_url,err := url.Parse(curSetting.Proxy)
		if err!=nil {
			widgets.QMessageBox_Warning(nil,"提 示","代理路径解析失败,"+err.Error(),widgets.QMessageBox__Ok,0)
			return
		}
		transport = &http.Transport{Proxy: http.ProxyURL(Proxy_url)}
	}



	tiny := Tinypng{
		waiter:         wait,
		console:        console,
		compressingUrl: "https://api.tinify.com/shrink",
		curNode:        0,
		tableview:      tableview,
		resultChans:    make(chan compressResultMsg, 1),
		Tinykey:        Tinykey,
		outputMode:curSetting.OutputMode,
	}

	go tiny.result(MODEL.RowCount(core.NewQModelIndex()))
	for i := 0; i < CPU; i++ {
		go tiny.work(ch, Email, ApiKey,transport)
	}
	if curSetting.OutputMode==0{
		console.Append("\n开始压缩\n输出目录：" + MODEL.Item(0, 0).Text() + "_tiny/")
	}else{
		console.Append("\n开始压缩")
	}


	for row := 0; row < MODEL.RowCount(core.NewQModelIndex()); row++ {

		item := &LocalResourceItem{
			Row:  row,
			Path: MODEL.Item(row, 1).Text(),
			Root: MODEL.Item(row, 0).Text(),
		}
		MODEL.Item(item.Row, 3).SetText("压缩中")
		tableview.Update(MODEL.Index(row, 3, core.NewQModelIndex()))
		ch <- item
	}

	for i := 0; i < CPU; i++ {
		ch <- nil
	}

	wait.Wait()
	close(ch)
	tiny.resultChans <- compressResultMsg{item: nil}
	time.Sleep(time.Millisecond * 100)
	console.SetTextColor(gui.NewQColor3(23, 168, 26, 255))
	console.Append("压缩完成~!")
	//fmt.Println(fmt.Sprintf("压缩结束，成功：%d 失败：%d", successNumber, len(failBox)))
	//if len(failBox) > 0 {
	//	fmt.Println("以下为压缩失败图片路径")
	//	for _, path := range failBox{
	//		fmt.Println(path)
	//	}
	//}
}

func (m *Tinypng) work(ch chan *LocalResourceItem, Email, ApiKey string,transport *http.Transport) {
	// 创建Request
	req, err := http.NewRequest(http.MethodPost, m.compressingUrl, nil)

	if err != nil {
		return
	}

	// 将鉴权信息写入Request
	req.SetBasicAuth(Email, ApiKey)


	for {
		item := <-ch
		if item == nil {
			break
		}

		// 将图片以二进制的形式写入Request
		data, err := ioutil.ReadFile(item.Root + item.Path)
		if err != nil {
			m.resultChans <- compressResultMsg{item: item, err: errors.New("读取文件失败:" + err.Error())}
			continue
		}
		item.Ssize = int64(len(data))

		req.Body = ioutil.NopCloser(bytes.NewReader(data))


		// 发起请求
		var netClient *http.Client
		if transport!=nil {
			netClient = &http.Client{
				Timeout:   time.Second * 10,
				Transport: transport,
			}
		}else{
			netClient = &http.Client{
				Timeout:   time.Second * 10,
			}
		}
		response, err := netClient.Do(req)

		if err != nil {
			m.resultChans <- compressResultMsg{item: item, err: errors.New("请求失败:" + err.Error())}

			continue
		}


		// 解析请求
		data, err = ioutil.ReadAll(response.Body)
		if err != nil {
			m.resultChans <- compressResultMsg{item: item, err: errors.New("读取body失败:" + err.Error())}
			continue
		}

		rps := map[string]interface{}{}
		json.Unmarshal(data, &rps)

		if _, ok := rps["output"]; !ok {
			//failMsg(errors.New(string(data)), path)
			m.resultChans <- compressResultMsg{item: item, err: errors.New("接口返回错误，" + string(data))}
			//widgets.QMessageBox_Information(nil,"提示","It miss the output data:"+string(data),widgets.QMessageBox__Default,widgets.QMessageBox__Default)
			continue
		}

		if _, ok := rps["output"].(map[string]interface{})["url"]; !ok {
			//failMsg(errors.New(string(data)), path)
			m.resultChans <- compressResultMsg{item: item, err: errors.New("接口返回数据没有url字段")}
			//widgets.QMessageBox_Information(nil,"提示","No the url field in the rps struct:"+string(data),widgets.QMessageBox__Default,widgets.QMessageBox__Default)
			continue
		}
		item.Url = rps["output"].(map[string]interface{})["url"].(string)
		m.SaveToLocal(item)
	}

	m.waiter.Done()
}

func (m *Tinypng) SaveToLocal(item *LocalResourceItem) {
	if item.Url == "" {
		return
	}

	isExist := func(path string) bool {
		_, err := os.Stat(path) //os.Stat获取文件信息
		if err != nil {
			if os.IsExist(err) {
				return true
			}
			return false
		}
		return true
	}
	var path string
	if m.outputMode==0{
		path = fmt.Sprintf("%s_tiny%s", item.Root, item.Path)
	}else{
		path = fmt.Sprintf("%s%s", item.Root, item.Path)
	}

	dir := filepath.Dir(path)
	if !isExist(dir) {
		os.MkdirAll(dir, os.ModePerm)
	}

	// 保存图片
	resp, err := http.Get(item.Url)
	if err != nil {
		m.resultChans <- compressResultMsg{item: item, err: err}
		return
	}

	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		//failMsg(err, oldPath)
		m.resultChans <- compressResultMsg{item: item, err: err}
		return
	}

	item.Nsize = int64(len(body))

	out, err := os.Create(path)
	if err != nil {
		m.resultChans <- compressResultMsg{item: item, err: err}
		return
	}

	_, err = io.Copy(out, bytes.NewReader(body))
	if err != nil {
		m.resultChans <- compressResultMsg{item: item, err: err}
		return
	}
	out.Close()

	m.resultChans <- compressResultMsg{item: item, err: err}
	//fmt.Println(fmt.Sprintf("进度： %d/%d", successNumber, totalNumber))
}

func (m *Tinypng) result(count int) {
	//fmt.Println(err.Error())
	//failBox = append(failBox, path)
	doneNum := 0
	sucNum := 0
	total_tiny := int64(0)
	total_size := int64(0)
	start_time := time.Now()
	for {
		result := <-m.resultChans
		if result.item == nil {
			//m.waiter.Done()
			m.console.SetTextColor(gui.NewQColor3(23, 168, 26, 255))
			total_crate := float64(total_tiny)/float64(total_size)*100
			fmt.Println(total_tiny,total_size)
			m.console.Append(fmt.Sprintf("共压缩%d文件，总压缩大小：%s,压缩比例：%.2f%%,耗时：%v", sucNum, ByteCountDecimal(total_tiny), total_crate, time.Now().Sub(start_time)))
			break
		}
		doneNum += 1
		if result.err != nil {
			MODEL.Item(result.item.Row, 3).SetText("错误")
			m.console.SetTextColor(gui.NewQColor3(255, 0, 0, 255))
			m.console.Append(fmt.Sprintf("%d/%d压缩失败：%s,%s", doneNum, count, result.item.Path, result.err.Error()))
		} else {
			sucNum += 1
			MODEL.Item(result.item.Row, 3).SetText("已完成")
			brush := gui.NewQBrush()
			brush.SetColor(gui.NewQColor3(23, 168, 26, 255))
			MODEL.SetData(MODEL.Index(result.item.Row, 3, core.NewQModelIndex()), brush.ToVariant(), 9)

			csd_percent := float64(result.item.Ssize-result.item.Nsize) / float64(result.item.Ssize) * 100
			total_tiny += (result.item.Ssize - result.item.Nsize)
			total_size += result.item.Ssize
			m.console.SetTextColor(gui.NewQColor3(23, 168, 26, 255))
			m.console.Append(fmt.Sprintf("%d/%d压缩成功：%s(%s),%.2f%%", doneNum, count, result.item.Path, ByteCountDecimal(result.item.Nsize), csd_percent))
		}
		m.tableview.Update(MODEL.Index(result.item.Row, 3, core.NewQModelIndex()))

	}
}
