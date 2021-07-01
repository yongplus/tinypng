package main

import (
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
	"heyong/ecommerce/test/heyong/qt/model"
	"heyong/ecommerce/test/heyong/qt/mywidgets"
	"heyong/ecommerce/test/heyong/qt/setting"
	"os"
)

var (
	MODEL *gui.QStandardItemModel
)

type MyMainWindow struct {
	app       *widgets.QApplication
	window    *widgets.QMainWindow
	tableview *MyTableView
	console   *widgets.QTextBrowser
	Tinykey   *model.Key
}

func InitMyMainWindow() *MyMainWindow {
	mymw := &MyMainWindow{}
	mymw.init()
	return mymw
}
func (m *MyMainWindow) init() {
	m.app = widgets.NewQApplication(len(os.Args), os.Args)
	m.app.SetAttribute(core.Qt__AA_DisableWindowContextHelpButton, false)
	gui.QGuiApplication_SetWindowIcon(gui.NewQIcon5(":/icon.ico"))
	m.window = widgets.NewQMainWindow(nil, 0)
	//window.SetMinimumSize2(850, 580)

	m.window.SetWindowTitle("图片压缩")

	widget := widgets.NewQWidget(nil, 0)
	layout := widgets.NewQVBoxLayout()
	widget.SetLayout(layout)
	m.window.SetCentralWidget(widget)

	layout.AddLayout(m._buidlTopBtns(), 0)
	m._buildBody()
	go m.InitKey()
	m.window.ShowMaximized()
	m.window.Show()
}

func (m *MyMainWindow) _buidlTopBtns() *widgets.QHBoxLayout {

	edit := widgets.NewQPushButton2("添加路径", nil)
	edit.SetFixedSize(core.NewQSize2(90, 45))
	edit.ConnectClicked(func(bool) {
		//New
		dialog := widgets.NewQFileDialog(m.window, core.Qt__Dialog)
		dialog.SetWindowTitle("选择目录")
		dialog.SetFileMode(widgets.QFileDialog__DirectoryOnly)
		if dialog.Exec() == 1 {
			getFileList(dialog.SelectedFiles()[0])
		}
	})
	//widget.Layout().AddWidget(edit)

	start := widgets.NewQPushButton2("开始压缩", nil)
	start.SetFixedSize(core.NewQSize2(90, 45))
	//widget.Layout().AddWidget(start)

	topbtns := widgets.NewQHBoxLayout()

	edit.SetSizePolicy2(widgets.QSizePolicy__Fixed, widgets.QSizePolicy__Fixed)
	start.SetSizePolicy2(widgets.QSizePolicy__Fixed, widgets.QSizePolicy__Fixed)
	start.ConnectClicked(func(bool) {
		go RunTiny(m.console, m.Tinykey, m.tableview)
	})

	config := widgets.NewQPushButton2("配置KEY", nil)
	config.SetFixedSize(core.NewQSize2(90, 45))
	config.ConnectClicked(func(bool) {
		setting.OpenSettingWindow(m.Tinykey, m.window)
	})

	topbtns.AddWidget(edit, 0, core.Qt__AlignLeft)
	topbtns.AddWidget(start, 0, core.Qt__AlignLeft)
	topbtns.AddWidget(config, 0, core.Qt__AlignLeft)

	topbtns.AddStretch(1)
	return topbtns
}

func (m *MyMainWindow) _buildBody() {
	overlay := mywidgets.NewDragOverlay()
	m.tableview = newTableView(overlay)
	MODEL = NewCustomTableModel(nil)

	m.tableview.SetModel(MODEL)
	m.tableview.SetSizePolicy2(widgets.QSizePolicy__Expanding, widgets.QSizePolicy__Expanding)
	splittter := widgets.NewQSplitter2(core.Qt__Vertical, m.window.CentralWidget())
	splittter.AddWidget(m.tableview)
	m.console = newConsole()
	splittter.AddWidget(m.console)
	splittter.SetStretchFactor(0, 6)
	splittter.SetStretchFactor(1, 2)
	splittter.SetSizePolicy2(widgets.QSizePolicy__Expanding, widgets.QSizePolicy__Expanding)

	//layout.AddLayout(topbtns,1)
	//layout.AddLayout(bodyHLayout,1)
	//layout.SetSizeConstraint(widgets.QLayout__SetMaximumSize)

	//layout.AddWidget(splittter,1,core.Qt__AlignLeft)

	m.window.CentralWidget().Layout().AddWidget(splittter)

	overlay.SetParent(m.window.CentralWidget())
	overlay.Hide()
	//overlay.SetGeometry2(0,0,tableview.Size().Width(),tableview.Size().Height())

	//overlay.SetGeometry2(0,0,0,0,)
	//widget.Layout().AddWidget(overlay)
	//widget.Layout().AddWidget()
	//layout.AddWidget(splittter,1,core.Qt__AlignLeft)
	//layout.SetContentsMargins(0,0,0,0)

	m.window.CentralWidget().ConnectResizeEvent(func(event *gui.QResizeEvent) {
		pos := m.tableview.MapTo(m.window, core.NewQPoint())
		overlay.SetGeometry2(pos.X(), pos.Y(), m.tableview.Size().Width(), m.tableview.Size().Height())
	})

}

func (m *MyMainWindow) InitKey() {
	m.Tinykey = model.InitKey(m.window)
}

func NewCustomTableModel(parent *widgets.QTableView) *gui.QStandardItemModel {
	model := gui.NewQStandardItemModel(nil)
	model.SetHorizontalHeaderLabels([]string{"ROOT", "路径", "大小", "状态"})
	return model
}

func main() {
	InitMyMainWindow().app.Exec()
}


Severity	Code	Description	Project	File	Line	Suppression State
Error	C3861	'NewModel'	tinypng	D:\workspace\qt\tinypng\tinypng\MainWindow.cpp	56
