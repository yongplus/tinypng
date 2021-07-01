package main

import (
	"fmt"
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
	"io/ioutil"
	"path/filepath"
	"strings"
)

type FileItem struct {
	Child string
	Name  string
	Size  int64
}

func getFileList(path string) {
	// 遍了所有文件
	files := []FileItem{}
	files, err := _getAllFile(path, files, "")
	if err != nil {

		widgets.QMessageBox_Warning(nil, "提示", err.Error(), widgets.QMessageBox__Default, widgets.QMessageBox__Default)
		return
	}
	var exists = map[string]int{}
	/*
		for _,one := range model.TakeColumn(1){
			exists[one.Text()] = 1
		}
	*/

	count := MODEL.RowCount(core.NewQModelIndex())
	MODEL.RemoveRows(0, count-1, core.NewQModelIndex())
	////model.BeginRemoveRows(core.NewQModelIndex(),1,count-1)
	//model.EndRemoveRows()

	for _, item := range files {
		full_path := item.Child + "/" + item.Name
		if _, ok := exists[full_path]; ok {
			continue
		}
		row := []*gui.QStandardItem{gui.NewQStandardItem2(path), gui.NewQStandardItem2(full_path), gui.NewQStandardItem2(ByteCountDecimal(item.Size)), gui.NewQStandardItem2("待压缩")}
		MODEL.AppendRow(row)
	}
}

func _getAllFile(pathname string, s []FileItem, child string) ([]FileItem, error) {
	rd, err := ioutil.ReadDir(pathname)
	if err != nil {
		fmt.Println("read dir fail:", err)
		return s, err
	}

	for _, fi := range rd {
		if fi.IsDir() {
			fullDir := pathname + "/" + fi.Name()
			s, err = _getAllFile(fullDir, s, fmt.Sprintf("%s/%s", child, fi.Name()))
			if err != nil {
				fmt.Println("read dir fail:", err)
				return s, err
			}
		} else {
			ext := strings.ToLower(filepath.Ext(pathname + "/" + fi.Name())[1:])
			if ext != "png" && ext != "jpg" && ext != "jpeg" {
				continue
			}
			s = append(s, FileItem{Child: child, Name: fi.Name(), Size: fi.Size()})
		}
	}
	return s, nil
}
