// +build !
package main

import (
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
)

type MyTableView struct {
	widgets.QTableView
}

func newTableView(overlay *widgets.QWidget) *MyTableView {

	//var tableview *MyTableView
	//tableview = widgets.NewQTableView(nil)
	tableview := NewMyTableView(nil)
	tableview.SetEnabled(true)
	tableview.SetStyleSheet(`QTableView { 
		selection-background-color: #8EDE21;
		color: black}`)
	//tableview.VerticalHeader().SetSelectionMode(0x0020)
	tableview.SetSelectionBehavior(widgets.QAbstractItemView__SelectRows)
	tableview.HorizontalHeader().SetSectionResizeMode(widgets.QHeaderView__Fixed)

	tableview.SetColumnWidth(3, 100)
	tableview.SetColumnWidth(2, 100)
	tableview.ConnectResizeEvent(func(event *gui.QResizeEvent) {
		tableview.SetColumnWidth(1, event.Size().Width()-200)
		tableview.SetColumnHidden(0, true)
	})
	tableview.SetEditTriggers(widgets.QAbstractItemView__NoEditTriggers)
	tableview.SetColumnHidden(0, true)
	tableview.SetAcceptDrops(true)

	tableview.ConnectDragEnterEvent(func(event *gui.QDragEnterEvent) {
		minedata := event.MimeData()
		if !minedata.HasUrls() {
			return
		}
		if len(minedata.Urls()) > 1 {
			return
		}

		if !core.NewQDir2(minedata.Urls()[0].ToLocalFile()).Exists2() {
			return
		}
		overlay.Show()

		event.AcceptProposedAction()
		//image := gui.NewQImage2(tableview.Size(),gui.QImage__Format_Alpha8)
		//tableview.Render()
		//color := gui.QColor_FromRgba64(0,0,0,0)
		//tableview.SetMask(gui.QBitmap_FromImage(image.CreateMaskFromColor(color,core.Qt__mask)))
	})

	tableview.ConnectDragMoveEvent(func(event *gui.QDragMoveEvent) {
		minedata := event.MimeData()
		if !minedata.HasUrls() {
			return
		}
		if len(minedata.Urls()) > 1 {
			return
		}

		if !core.NewQDir2(minedata.Urls()[0].ToLocalFile()).Exists2() {
			return
		}

		event.AcceptProposedAction()
	})

	tableview.ConnectDragLeaveEvent(func(event *gui.QDragLeaveEvent) {
		overlay.Hide()
	})

	tableview.ConnectDropEvent(func(event *gui.QDropEvent) {
		minedata := event.MimeData()
		if !minedata.HasUrls() {
			return
		}
		urls := minedata.Urls()
		path := urls[0].ToLocalFile()
		overlay.Hide()
		getFileList(path)
	})
	tableview.ConnectDoubleClicked(func(index *core.QModelIndex){

			path := MODEL.Item(index.Row(),0).Text()+MODEL.Item(index.Row(),1).Text()
			gui.QDesktopServices_OpenUrl(core.QUrl_FromLocalFile(path))
	})

	addContextMenu(tableview)

	return tableview
}

func addContextMenu(table *MyTableView) {
	table.SetContextMenuPolicy(core.Qt__CustomContextMenu)

	table.ConnectCustomContextMenuRequested(func(pos *core.QPoint) {

		selectedRows := table.SelectionModel().SelectedRows(0)
		if len(selectedRows) == 0 {
			return
		}
		indexs := []*core.QPersistentModelIndex{}
		for _, item := range selectedRows {
			indexs = append(indexs, core.NewQPersistentModelIndex2(item.QModelIndex_PTR()))
		}

		//index := table.IndexAt(pos)
		menu := widgets.NewQMenu(table)
		//menu.AddAction("删 除")

		//menu.MapToGlobal(pos)
		action := widgets.NewQAction2("删 除", menu)
		action.ConnectTriggered(func(bool) {

			for _, item := range indexs {
				//MODEL.BeginRemoveRows(core.NewQModelIndex(),item.Row(),item.Row())
				MODEL.RemoveRow(item.Row(), core.NewQModelIndex())
			}
			//MODEL.EndRemoveRows()
		})

		menu.AddActions([]*widgets.QAction{action})
		menu.Popup(table.Viewport().MapToGlobal(pos), nil)
		//menu.MapToParent(table)
		//menu.Move(pos)
		//menu.MapFromParent(pos)
		//menu.Show()
		//menu.Show()
	})
}
