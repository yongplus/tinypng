package main

//#include <stdint.h>
//#include <stdlib.h>
//#include <string.h>
//#include "moc.h"
import "C"
import (
	"strings"
	"unsafe"

	"github.com/therecipe/qt"
	std_core "github.com/therecipe/qt/core"
	std_gui "github.com/therecipe/qt/gui"
	std_widgets "github.com/therecipe/qt/widgets"
)

func cGoFreePacked(ptr unsafe.Pointer) { std_core.NewQByteArrayFromPointer(ptr).DestroyQByteArray() }
func cGoUnpackString(s C.struct_Moc_PackedString) string {
	defer cGoFreePacked(s.ptr)
	if int(s.len) == -1 {
		return C.GoString(s.data)
	}
	return C.GoStringN(s.data, C.int(s.len))
}
func cGoUnpackBytes(s C.struct_Moc_PackedString) []byte {
	defer cGoFreePacked(s.ptr)
	if int(s.len) == -1 {
		gs := C.GoString(s.data)
		return []byte(gs)
	}
	return C.GoBytes(unsafe.Pointer(s.data), C.int(s.len))
}
func unpackStringList(s string) []string {
	if len(s) == 0 {
		return make([]string, 0)
	}
	return strings.Split(s, "¡¦!")
}

type MyTableView_ITF interface {
	std_widgets.QTableView_ITF
	MyTableView_PTR() *MyTableView
}

func (ptr *MyTableView) MyTableView_PTR() *MyTableView {
	return ptr
}

func (ptr *MyTableView) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.QTableView_PTR().Pointer()
	}
	return nil
}

func (ptr *MyTableView) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.QTableView_PTR().SetPointer(p)
	}
}

func PointerFromMyTableView(ptr MyTableView_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.MyTableView_PTR().Pointer()
	}
	return nil
}

func NewMyTableViewFromPointer(ptr unsafe.Pointer) (n *MyTableView) {
	if gPtr, ok := qt.Receive(ptr); !ok {
		n = new(MyTableView)
		n.SetPointer(ptr)
	} else {
		switch deduced := gPtr.(type) {
		case *MyTableView:
			n = deduced

		case *std_widgets.QTableView:
			n = &MyTableView{QTableView: *deduced}

		default:
			n = new(MyTableView)
			n.SetPointer(ptr)
		}
	}
	return
}

//export callbackMyTableView871826_Constructor
func callbackMyTableView871826_Constructor(ptr unsafe.Pointer) {
	this := NewMyTableViewFromPointer(ptr)
	qt.Register(ptr, this)
}

func MyTableView_QRegisterMetaType() int {
	return int(int32(C.MyTableView871826_MyTableView871826_QRegisterMetaType()))
}

func (ptr *MyTableView) QRegisterMetaType() int {
	return int(int32(C.MyTableView871826_MyTableView871826_QRegisterMetaType()))
}

func MyTableView_QRegisterMetaType2(typeName string) int {
	var typeNameC *C.char
	if typeName != "" {
		typeNameC = C.CString(typeName)
		defer C.free(unsafe.Pointer(typeNameC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QRegisterMetaType2(typeNameC)))
}

func (ptr *MyTableView) QRegisterMetaType2(typeName string) int {
	var typeNameC *C.char
	if typeName != "" {
		typeNameC = C.CString(typeName)
		defer C.free(unsafe.Pointer(typeNameC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QRegisterMetaType2(typeNameC)))
}

func MyTableView_QmlRegisterType() int {
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterType()))
}

func (ptr *MyTableView) QmlRegisterType() int {
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterType()))
}

func MyTableView_QmlRegisterType2(uri string, versionMajor int, versionMinor int, qmlName string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterType2(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC)))
}

func (ptr *MyTableView) QmlRegisterType2(uri string, versionMajor int, versionMinor int, qmlName string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterType2(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC)))
}

func MyTableView_QmlRegisterUncreatableType(uri string, versionMajor int, versionMinor int, qmlName string, message string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	var messageC *C.char
	if message != "" {
		messageC = C.CString(message)
		defer C.free(unsafe.Pointer(messageC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterUncreatableType(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC, C.struct_Moc_PackedString{data: messageC, len: C.longlong(len(message))})))
}

func (ptr *MyTableView) QmlRegisterUncreatableType(uri string, versionMajor int, versionMinor int, qmlName string, message string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	var messageC *C.char
	if message != "" {
		messageC = C.CString(message)
		defer C.free(unsafe.Pointer(messageC))
	}
	return int(int32(C.MyTableView871826_MyTableView871826_QmlRegisterUncreatableType(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC, C.struct_Moc_PackedString{data: messageC, len: C.longlong(len(message))})))
}

func (ptr *MyTableView) __selectedIndexes_atList(i int) *std_core.QModelIndex {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQModelIndexFromPointer(C.MyTableView871826___selectedIndexes_atList(ptr.Pointer(), C.int(int32(i))))
		qt.SetFinalizer(tmpValue, (*std_core.QModelIndex).DestroyQModelIndex)
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __selectedIndexes_setList(i std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___selectedIndexes_setList(ptr.Pointer(), std_core.PointerFromQModelIndex(i))
	}
}

func (ptr *MyTableView) __selectedIndexes_newList() unsafe.Pointer {
	return C.MyTableView871826___selectedIndexes_newList(ptr.Pointer())
}

func (ptr *MyTableView) __dataChanged_roles_atList(i int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826___dataChanged_roles_atList(ptr.Pointer(), C.int(int32(i)))))
	}
	return 0
}

func (ptr *MyTableView) __dataChanged_roles_setList(i int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___dataChanged_roles_setList(ptr.Pointer(), C.int(int32(i)))
	}
}

func (ptr *MyTableView) __dataChanged_roles_newList() unsafe.Pointer {
	return C.MyTableView871826___dataChanged_roles_newList(ptr.Pointer())
}

func (ptr *MyTableView) __scrollBarWidgets_atList(i int) *std_widgets.QWidget {
	if ptr.Pointer() != nil {
		tmpValue := std_widgets.NewQWidgetFromPointer(C.MyTableView871826___scrollBarWidgets_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __scrollBarWidgets_setList(i std_widgets.QWidget_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___scrollBarWidgets_setList(ptr.Pointer(), std_widgets.PointerFromQWidget(i))
	}
}

func (ptr *MyTableView) __scrollBarWidgets_newList() unsafe.Pointer {
	return C.MyTableView871826___scrollBarWidgets_newList(ptr.Pointer())
}

func (ptr *MyTableView) __actions_atList(i int) *std_widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := std_widgets.NewQActionFromPointer(C.MyTableView871826___actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __actions_setList(i std_widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___actions_setList(ptr.Pointer(), std_widgets.PointerFromQAction(i))
	}
}

func (ptr *MyTableView) __actions_newList() unsafe.Pointer {
	return C.MyTableView871826___actions_newList(ptr.Pointer())
}

func (ptr *MyTableView) __addActions_actions_atList(i int) *std_widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := std_widgets.NewQActionFromPointer(C.MyTableView871826___addActions_actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __addActions_actions_setList(i std_widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___addActions_actions_setList(ptr.Pointer(), std_widgets.PointerFromQAction(i))
	}
}

func (ptr *MyTableView) __addActions_actions_newList() unsafe.Pointer {
	return C.MyTableView871826___addActions_actions_newList(ptr.Pointer())
}

func (ptr *MyTableView) __insertActions_actions_atList(i int) *std_widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := std_widgets.NewQActionFromPointer(C.MyTableView871826___insertActions_actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __insertActions_actions_setList(i std_widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___insertActions_actions_setList(ptr.Pointer(), std_widgets.PointerFromQAction(i))
	}
}

func (ptr *MyTableView) __insertActions_actions_newList() unsafe.Pointer {
	return C.MyTableView871826___insertActions_actions_newList(ptr.Pointer())
}

func (ptr *MyTableView) __children_atList(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.MyTableView871826___children_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __children_setList(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___children_setList(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *MyTableView) __children_newList() unsafe.Pointer {
	return C.MyTableView871826___children_newList(ptr.Pointer())
}

func (ptr *MyTableView) __dynamicPropertyNames_atList(i int) *std_core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQByteArrayFromPointer(C.MyTableView871826___dynamicPropertyNames_atList(ptr.Pointer(), C.int(int32(i))))
		qt.SetFinalizer(tmpValue, (*std_core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __dynamicPropertyNames_setList(i std_core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___dynamicPropertyNames_setList(ptr.Pointer(), std_core.PointerFromQByteArray(i))
	}
}

func (ptr *MyTableView) __dynamicPropertyNames_newList() unsafe.Pointer {
	return C.MyTableView871826___dynamicPropertyNames_newList(ptr.Pointer())
}

func (ptr *MyTableView) __findChildren_atList(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.MyTableView871826___findChildren_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __findChildren_setList(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___findChildren_setList(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *MyTableView) __findChildren_newList() unsafe.Pointer {
	return C.MyTableView871826___findChildren_newList(ptr.Pointer())
}

func (ptr *MyTableView) __findChildren_atList3(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.MyTableView871826___findChildren_atList3(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *MyTableView) __findChildren_setList3(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826___findChildren_setList3(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *MyTableView) __findChildren_newList3() unsafe.Pointer {
	return C.MyTableView871826___findChildren_newList3(ptr.Pointer())
}

func NewMyTableView(parent std_widgets.QWidget_ITF) *MyTableView {
	MyTableView_QRegisterMetaType()
	tmpValue := NewMyTableViewFromPointer(C.MyTableView871826_NewMyTableView(std_widgets.PointerFromQWidget(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

//export callbackMyTableView871826_DestroyMyTableView
func callbackMyTableView871826_DestroyMyTableView(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "~MyTableView"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).DestroyMyTableViewDefault()
	}
}

func (ptr *MyTableView) ConnectDestroyMyTableView(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "~MyTableView"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "~MyTableView", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "~MyTableView", unsafe.Pointer(&f))
		}
	}
}

func (ptr *MyTableView) DisconnectDestroyMyTableView() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "~MyTableView")
	}
}

func (ptr *MyTableView) DestroyMyTableView() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.MyTableView871826_DestroyMyTableView(ptr.Pointer())
		ptr.SetPointer(nil)
	}
}

func (ptr *MyTableView) DestroyMyTableViewDefault() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.MyTableView871826_DestroyMyTableViewDefault(ptr.Pointer())
		ptr.SetPointer(nil)
	}
}

//export callbackMyTableView871826_ColumnCountChanged
func callbackMyTableView871826_ColumnCountChanged(ptr unsafe.Pointer, oldCount C.int, newCount C.int) {
	if signal := qt.GetSignal(ptr, "columnCountChanged"); signal != nil {
		(*(*func(int, int))(signal))(int(int32(oldCount)), int(int32(newCount)))
	} else {
		NewMyTableViewFromPointer(ptr).ColumnCountChangedDefault(int(int32(oldCount)), int(int32(newCount)))
	}
}

func (ptr *MyTableView) ColumnCountChangedDefault(oldCount int, newCount int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ColumnCountChangedDefault(ptr.Pointer(), C.int(int32(oldCount)), C.int(int32(newCount)))
	}
}

//export callbackMyTableView871826_ColumnMoved
func callbackMyTableView871826_ColumnMoved(ptr unsafe.Pointer, column C.int, oldIndex C.int, newIndex C.int) {
	if signal := qt.GetSignal(ptr, "columnMoved"); signal != nil {
		(*(*func(int, int, int))(signal))(int(int32(column)), int(int32(oldIndex)), int(int32(newIndex)))
	} else {
		NewMyTableViewFromPointer(ptr).ColumnMovedDefault(int(int32(column)), int(int32(oldIndex)), int(int32(newIndex)))
	}
}

func (ptr *MyTableView) ColumnMovedDefault(column int, oldIndex int, newIndex int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ColumnMovedDefault(ptr.Pointer(), C.int(int32(column)), C.int(int32(oldIndex)), C.int(int32(newIndex)))
	}
}

//export callbackMyTableView871826_ColumnResized
func callbackMyTableView871826_ColumnResized(ptr unsafe.Pointer, column C.int, oldWidth C.int, newWidth C.int) {
	if signal := qt.GetSignal(ptr, "columnResized"); signal != nil {
		(*(*func(int, int, int))(signal))(int(int32(column)), int(int32(oldWidth)), int(int32(newWidth)))
	} else {
		NewMyTableViewFromPointer(ptr).ColumnResizedDefault(int(int32(column)), int(int32(oldWidth)), int(int32(newWidth)))
	}
}

func (ptr *MyTableView) ColumnResizedDefault(column int, oldWidth int, newWidth int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ColumnResizedDefault(ptr.Pointer(), C.int(int32(column)), C.int(int32(oldWidth)), C.int(int32(newWidth)))
	}
}

//export callbackMyTableView871826_CurrentChanged
func callbackMyTableView871826_CurrentChanged(ptr unsafe.Pointer, current unsafe.Pointer, previous unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "currentChanged"); signal != nil {
		(*(*func(*std_core.QModelIndex, *std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(current), std_core.NewQModelIndexFromPointer(previous))
	} else {
		NewMyTableViewFromPointer(ptr).CurrentChangedDefault(std_core.NewQModelIndexFromPointer(current), std_core.NewQModelIndexFromPointer(previous))
	}
}

func (ptr *MyTableView) CurrentChangedDefault(current std_core.QModelIndex_ITF, previous std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_CurrentChangedDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(current), std_core.PointerFromQModelIndex(previous))
	}
}

//export callbackMyTableView871826_HideColumn
func callbackMyTableView871826_HideColumn(ptr unsafe.Pointer, column C.int) {
	if signal := qt.GetSignal(ptr, "hideColumn"); signal != nil {
		(*(*func(int))(signal))(int(int32(column)))
	} else {
		NewMyTableViewFromPointer(ptr).HideColumnDefault(int(int32(column)))
	}
}

func (ptr *MyTableView) HideColumnDefault(column int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_HideColumnDefault(ptr.Pointer(), C.int(int32(column)))
	}
}

//export callbackMyTableView871826_HideRow
func callbackMyTableView871826_HideRow(ptr unsafe.Pointer, row C.int) {
	if signal := qt.GetSignal(ptr, "hideRow"); signal != nil {
		(*(*func(int))(signal))(int(int32(row)))
	} else {
		NewMyTableViewFromPointer(ptr).HideRowDefault(int(int32(row)))
	}
}

func (ptr *MyTableView) HideRowDefault(row int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_HideRowDefault(ptr.Pointer(), C.int(int32(row)))
	}
}

//export callbackMyTableView871826_HorizontalOffset
func callbackMyTableView871826_HorizontalOffset(ptr unsafe.Pointer) C.int {
	if signal := qt.GetSignal(ptr, "horizontalOffset"); signal != nil {
		return C.int(int32((*(*func() int)(signal))()))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).HorizontalOffsetDefault()))
}

func (ptr *MyTableView) HorizontalOffsetDefault() int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_HorizontalOffsetDefault(ptr.Pointer())))
	}
	return 0
}

//export callbackMyTableView871826_IndexAt
func callbackMyTableView871826_IndexAt(ptr unsafe.Pointer, pos unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "indexAt"); signal != nil {
		return std_core.PointerFromQModelIndex((*(*func(*std_core.QPoint) *std_core.QModelIndex)(signal))(std_core.NewQPointFromPointer(pos)))
	}

	return std_core.PointerFromQModelIndex(NewMyTableViewFromPointer(ptr).IndexAtDefault(std_core.NewQPointFromPointer(pos)))
}

func (ptr *MyTableView) IndexAtDefault(pos std_core.QPoint_ITF) *std_core.QModelIndex {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQModelIndexFromPointer(C.MyTableView871826_IndexAtDefault(ptr.Pointer(), std_core.PointerFromQPoint(pos)))
		qt.SetFinalizer(tmpValue, (*std_core.QModelIndex).DestroyQModelIndex)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_IsIndexHidden
func callbackMyTableView871826_IsIndexHidden(ptr unsafe.Pointer, index unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "isIndexHidden"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QModelIndex) bool)(signal))(std_core.NewQModelIndexFromPointer(index)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).IsIndexHiddenDefault(std_core.NewQModelIndexFromPointer(index)))))
}

func (ptr *MyTableView) IsIndexHiddenDefault(index std_core.QModelIndex_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_IsIndexHiddenDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index))) != 0
	}
	return false
}

//export callbackMyTableView871826_MoveCursor
func callbackMyTableView871826_MoveCursor(ptr unsafe.Pointer, cursorAction C.longlong, modifiers C.longlong) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "moveCursor"); signal != nil {
		return std_core.PointerFromQModelIndex((*(*func(std_widgets.QAbstractItemView__CursorAction, std_core.Qt__KeyboardModifier) *std_core.QModelIndex)(signal))(std_widgets.QAbstractItemView__CursorAction(cursorAction), std_core.Qt__KeyboardModifier(modifiers)))
	}

	return std_core.PointerFromQModelIndex(NewMyTableViewFromPointer(ptr).MoveCursorDefault(std_widgets.QAbstractItemView__CursorAction(cursorAction), std_core.Qt__KeyboardModifier(modifiers)))
}

func (ptr *MyTableView) MoveCursorDefault(cursorAction std_widgets.QAbstractItemView__CursorAction, modifiers std_core.Qt__KeyboardModifier) *std_core.QModelIndex {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQModelIndexFromPointer(C.MyTableView871826_MoveCursorDefault(ptr.Pointer(), C.longlong(cursorAction), C.longlong(modifiers)))
		qt.SetFinalizer(tmpValue, (*std_core.QModelIndex).DestroyQModelIndex)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_PaintEvent
func callbackMyTableView871826_PaintEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "paintEvent"); signal != nil {
		(*(*func(*std_gui.QPaintEvent))(signal))(std_gui.NewQPaintEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).PaintEventDefault(std_gui.NewQPaintEventFromPointer(event))
	}
}

func (ptr *MyTableView) PaintEventDefault(event std_gui.QPaintEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_PaintEventDefault(ptr.Pointer(), std_gui.PointerFromQPaintEvent(event))
	}
}

//export callbackMyTableView871826_ResizeColumnToContents
func callbackMyTableView871826_ResizeColumnToContents(ptr unsafe.Pointer, column C.int) {
	if signal := qt.GetSignal(ptr, "resizeColumnToContents"); signal != nil {
		(*(*func(int))(signal))(int(int32(column)))
	} else {
		NewMyTableViewFromPointer(ptr).ResizeColumnToContentsDefault(int(int32(column)))
	}
}

func (ptr *MyTableView) ResizeColumnToContentsDefault(column int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResizeColumnToContentsDefault(ptr.Pointer(), C.int(int32(column)))
	}
}

//export callbackMyTableView871826_ResizeColumnsToContents
func callbackMyTableView871826_ResizeColumnsToContents(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "resizeColumnsToContents"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ResizeColumnsToContentsDefault()
	}
}

func (ptr *MyTableView) ResizeColumnsToContentsDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResizeColumnsToContentsDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ResizeRowToContents
func callbackMyTableView871826_ResizeRowToContents(ptr unsafe.Pointer, row C.int) {
	if signal := qt.GetSignal(ptr, "resizeRowToContents"); signal != nil {
		(*(*func(int))(signal))(int(int32(row)))
	} else {
		NewMyTableViewFromPointer(ptr).ResizeRowToContentsDefault(int(int32(row)))
	}
}

func (ptr *MyTableView) ResizeRowToContentsDefault(row int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResizeRowToContentsDefault(ptr.Pointer(), C.int(int32(row)))
	}
}

//export callbackMyTableView871826_ResizeRowsToContents
func callbackMyTableView871826_ResizeRowsToContents(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "resizeRowsToContents"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ResizeRowsToContentsDefault()
	}
}

func (ptr *MyTableView) ResizeRowsToContentsDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResizeRowsToContentsDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_RowCountChanged
func callbackMyTableView871826_RowCountChanged(ptr unsafe.Pointer, oldCount C.int, newCount C.int) {
	if signal := qt.GetSignal(ptr, "rowCountChanged"); signal != nil {
		(*(*func(int, int))(signal))(int(int32(oldCount)), int(int32(newCount)))
	} else {
		NewMyTableViewFromPointer(ptr).RowCountChangedDefault(int(int32(oldCount)), int(int32(newCount)))
	}
}

func (ptr *MyTableView) RowCountChangedDefault(oldCount int, newCount int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RowCountChangedDefault(ptr.Pointer(), C.int(int32(oldCount)), C.int(int32(newCount)))
	}
}

//export callbackMyTableView871826_RowMoved
func callbackMyTableView871826_RowMoved(ptr unsafe.Pointer, row C.int, oldIndex C.int, newIndex C.int) {
	if signal := qt.GetSignal(ptr, "rowMoved"); signal != nil {
		(*(*func(int, int, int))(signal))(int(int32(row)), int(int32(oldIndex)), int(int32(newIndex)))
	} else {
		NewMyTableViewFromPointer(ptr).RowMovedDefault(int(int32(row)), int(int32(oldIndex)), int(int32(newIndex)))
	}
}

func (ptr *MyTableView) RowMovedDefault(row int, oldIndex int, newIndex int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RowMovedDefault(ptr.Pointer(), C.int(int32(row)), C.int(int32(oldIndex)), C.int(int32(newIndex)))
	}
}

//export callbackMyTableView871826_RowResized
func callbackMyTableView871826_RowResized(ptr unsafe.Pointer, row C.int, oldHeight C.int, newHeight C.int) {
	if signal := qt.GetSignal(ptr, "rowResized"); signal != nil {
		(*(*func(int, int, int))(signal))(int(int32(row)), int(int32(oldHeight)), int(int32(newHeight)))
	} else {
		NewMyTableViewFromPointer(ptr).RowResizedDefault(int(int32(row)), int(int32(oldHeight)), int(int32(newHeight)))
	}
}

func (ptr *MyTableView) RowResizedDefault(row int, oldHeight int, newHeight int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RowResizedDefault(ptr.Pointer(), C.int(int32(row)), C.int(int32(oldHeight)), C.int(int32(newHeight)))
	}
}

//export callbackMyTableView871826_SelectColumn
func callbackMyTableView871826_SelectColumn(ptr unsafe.Pointer, column C.int) {
	if signal := qt.GetSignal(ptr, "selectColumn"); signal != nil {
		(*(*func(int))(signal))(int(int32(column)))
	} else {
		NewMyTableViewFromPointer(ptr).SelectColumnDefault(int(int32(column)))
	}
}

func (ptr *MyTableView) SelectColumnDefault(column int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SelectColumnDefault(ptr.Pointer(), C.int(int32(column)))
	}
}

//export callbackMyTableView871826_SelectRow
func callbackMyTableView871826_SelectRow(ptr unsafe.Pointer, row C.int) {
	if signal := qt.GetSignal(ptr, "selectRow"); signal != nil {
		(*(*func(int))(signal))(int(int32(row)))
	} else {
		NewMyTableViewFromPointer(ptr).SelectRowDefault(int(int32(row)))
	}
}

func (ptr *MyTableView) SelectRowDefault(row int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SelectRowDefault(ptr.Pointer(), C.int(int32(row)))
	}
}

//export callbackMyTableView871826_SelectedIndexes
func callbackMyTableView871826_SelectedIndexes(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "selectedIndexes"); signal != nil {
		return func() unsafe.Pointer {
			tmpList := NewMyTableViewFromPointer(NewMyTableViewFromPointer(nil).__selectedIndexes_newList())
			for _, v := range (*(*func() []*std_core.QModelIndex)(signal))() {
				tmpList.__selectedIndexes_setList(v)
			}
			return tmpList.Pointer()
		}()
	}

	return func() unsafe.Pointer {
		tmpList := NewMyTableViewFromPointer(NewMyTableViewFromPointer(nil).__selectedIndexes_newList())
		for _, v := range NewMyTableViewFromPointer(ptr).SelectedIndexesDefault() {
			tmpList.__selectedIndexes_setList(v)
		}
		return tmpList.Pointer()
	}()
}

func (ptr *MyTableView) SelectedIndexesDefault() []*std_core.QModelIndex {
	if ptr.Pointer() != nil {
		return func(l C.struct_Moc_PackedList) []*std_core.QModelIndex {
			out := make([]*std_core.QModelIndex, int(l.len))
			tmpList := NewMyTableViewFromPointer(l.data)
			for i := 0; i < len(out); i++ {
				out[i] = tmpList.__selectedIndexes_atList(i)
			}
			return out
		}(C.MyTableView871826_SelectedIndexesDefault(ptr.Pointer()))
	}
	return make([]*std_core.QModelIndex, 0)
}

//export callbackMyTableView871826_SelectionChanged
func callbackMyTableView871826_SelectionChanged(ptr unsafe.Pointer, selected unsafe.Pointer, deselected unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "selectionChanged"); signal != nil {
		(*(*func(*std_core.QItemSelection, *std_core.QItemSelection))(signal))(std_core.NewQItemSelectionFromPointer(selected), std_core.NewQItemSelectionFromPointer(deselected))
	} else {
		NewMyTableViewFromPointer(ptr).SelectionChangedDefault(std_core.NewQItemSelectionFromPointer(selected), std_core.NewQItemSelectionFromPointer(deselected))
	}
}

func (ptr *MyTableView) SelectionChangedDefault(selected std_core.QItemSelection_ITF, deselected std_core.QItemSelection_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SelectionChangedDefault(ptr.Pointer(), std_core.PointerFromQItemSelection(selected), std_core.PointerFromQItemSelection(deselected))
	}
}

//export callbackMyTableView871826_SetModel
func callbackMyTableView871826_SetModel(ptr unsafe.Pointer, model unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setModel"); signal != nil {
		(*(*func(*std_core.QAbstractItemModel))(signal))(std_core.NewQAbstractItemModelFromPointer(model))
	} else {
		NewMyTableViewFromPointer(ptr).SetModelDefault(std_core.NewQAbstractItemModelFromPointer(model))
	}
}

func (ptr *MyTableView) SetModelDefault(model std_core.QAbstractItemModel_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetModelDefault(ptr.Pointer(), std_core.PointerFromQAbstractItemModel(model))
	}
}

//export callbackMyTableView871826_SetRootIndex
func callbackMyTableView871826_SetRootIndex(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setRootIndex"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	} else {
		NewMyTableViewFromPointer(ptr).SetRootIndexDefault(std_core.NewQModelIndexFromPointer(index))
	}
}

func (ptr *MyTableView) SetRootIndexDefault(index std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetRootIndexDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index))
	}
}

//export callbackMyTableView871826_SetSelection
func callbackMyTableView871826_SetSelection(ptr unsafe.Pointer, rect unsafe.Pointer, flags C.longlong) {
	if signal := qt.GetSignal(ptr, "setSelection"); signal != nil {
		(*(*func(*std_core.QRect, std_core.QItemSelectionModel__SelectionFlag))(signal))(std_core.NewQRectFromPointer(rect), std_core.QItemSelectionModel__SelectionFlag(flags))
	} else {
		NewMyTableViewFromPointer(ptr).SetSelectionDefault(std_core.NewQRectFromPointer(rect), std_core.QItemSelectionModel__SelectionFlag(flags))
	}
}

func (ptr *MyTableView) SetSelectionDefault(rect std_core.QRect_ITF, flags std_core.QItemSelectionModel__SelectionFlag) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetSelectionDefault(ptr.Pointer(), std_core.PointerFromQRect(rect), C.longlong(flags))
	}
}

//export callbackMyTableView871826_SetSelectionModel
func callbackMyTableView871826_SetSelectionModel(ptr unsafe.Pointer, selectionModel unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setSelectionModel"); signal != nil {
		(*(*func(*std_core.QItemSelectionModel))(signal))(std_core.NewQItemSelectionModelFromPointer(selectionModel))
	} else {
		NewMyTableViewFromPointer(ptr).SetSelectionModelDefault(std_core.NewQItemSelectionModelFromPointer(selectionModel))
	}
}

func (ptr *MyTableView) SetSelectionModelDefault(selectionModel std_core.QItemSelectionModel_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetSelectionModelDefault(ptr.Pointer(), std_core.PointerFromQItemSelectionModel(selectionModel))
	}
}

//export callbackMyTableView871826_SetShowGrid
func callbackMyTableView871826_SetShowGrid(ptr unsafe.Pointer, show C.char) {
	if signal := qt.GetSignal(ptr, "setShowGrid"); signal != nil {
		(*(*func(bool))(signal))(int8(show) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetShowGridDefault(int8(show) != 0)
	}
}

func (ptr *MyTableView) SetShowGridDefault(show bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetShowGridDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(show))))
	}
}

//export callbackMyTableView871826_ShowColumn
func callbackMyTableView871826_ShowColumn(ptr unsafe.Pointer, column C.int) {
	if signal := qt.GetSignal(ptr, "showColumn"); signal != nil {
		(*(*func(int))(signal))(int(int32(column)))
	} else {
		NewMyTableViewFromPointer(ptr).ShowColumnDefault(int(int32(column)))
	}
}

func (ptr *MyTableView) ShowColumnDefault(column int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowColumnDefault(ptr.Pointer(), C.int(int32(column)))
	}
}

//export callbackMyTableView871826_ShowRow
func callbackMyTableView871826_ShowRow(ptr unsafe.Pointer, row C.int) {
	if signal := qt.GetSignal(ptr, "showRow"); signal != nil {
		(*(*func(int))(signal))(int(int32(row)))
	} else {
		NewMyTableViewFromPointer(ptr).ShowRowDefault(int(int32(row)))
	}
}

func (ptr *MyTableView) ShowRowDefault(row int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowRowDefault(ptr.Pointer(), C.int(int32(row)))
	}
}

//export callbackMyTableView871826_SizeHintForColumn
func callbackMyTableView871826_SizeHintForColumn(ptr unsafe.Pointer, column C.int) C.int {
	if signal := qt.GetSignal(ptr, "sizeHintForColumn"); signal != nil {
		return C.int(int32((*(*func(int) int)(signal))(int(int32(column)))))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).SizeHintForColumnDefault(int(int32(column)))))
}

func (ptr *MyTableView) SizeHintForColumnDefault(column int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_SizeHintForColumnDefault(ptr.Pointer(), C.int(int32(column)))))
	}
	return 0
}

//export callbackMyTableView871826_SizeHintForRow
func callbackMyTableView871826_SizeHintForRow(ptr unsafe.Pointer, row C.int) C.int {
	if signal := qt.GetSignal(ptr, "sizeHintForRow"); signal != nil {
		return C.int(int32((*(*func(int) int)(signal))(int(int32(row)))))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).SizeHintForRowDefault(int(int32(row)))))
}

func (ptr *MyTableView) SizeHintForRowDefault(row int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_SizeHintForRowDefault(ptr.Pointer(), C.int(int32(row)))))
	}
	return 0
}

//export callbackMyTableView871826_SortByColumn
func callbackMyTableView871826_SortByColumn(ptr unsafe.Pointer, column C.int, order C.longlong) {
	if signal := qt.GetSignal(ptr, "sortByColumn"); signal != nil {
		(*(*func(int, std_core.Qt__SortOrder))(signal))(int(int32(column)), std_core.Qt__SortOrder(order))
	} else {
		NewMyTableViewFromPointer(ptr).SortByColumnDefault(int(int32(column)), std_core.Qt__SortOrder(order))
	}
}

func (ptr *MyTableView) SortByColumnDefault(column int, order std_core.Qt__SortOrder) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SortByColumnDefault(ptr.Pointer(), C.int(int32(column)), C.longlong(order))
	}
}

//export callbackMyTableView871826_TimerEvent
func callbackMyTableView871826_TimerEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "timerEvent"); signal != nil {
		(*(*func(*std_core.QTimerEvent))(signal))(std_core.NewQTimerEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).TimerEventDefault(std_core.NewQTimerEventFromPointer(event))
	}
}

func (ptr *MyTableView) TimerEventDefault(event std_core.QTimerEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_TimerEventDefault(ptr.Pointer(), std_core.PointerFromQTimerEvent(event))
	}
}

//export callbackMyTableView871826_UpdateGeometries
func callbackMyTableView871826_UpdateGeometries(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "updateGeometries"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).UpdateGeometriesDefault()
	}
}

func (ptr *MyTableView) UpdateGeometriesDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_UpdateGeometriesDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_VerticalOffset
func callbackMyTableView871826_VerticalOffset(ptr unsafe.Pointer) C.int {
	if signal := qt.GetSignal(ptr, "verticalOffset"); signal != nil {
		return C.int(int32((*(*func() int)(signal))()))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).VerticalOffsetDefault()))
}

func (ptr *MyTableView) VerticalOffsetDefault() int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_VerticalOffsetDefault(ptr.Pointer())))
	}
	return 0
}

//export callbackMyTableView871826_ViewOptions
func callbackMyTableView871826_ViewOptions(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "viewOptions"); signal != nil {
		return std_widgets.PointerFromQStyleOptionViewItem((*(*func() *std_widgets.QStyleOptionViewItem)(signal))())
	}

	return std_widgets.PointerFromQStyleOptionViewItem(NewMyTableViewFromPointer(ptr).ViewOptionsDefault())
}

func (ptr *MyTableView) ViewOptionsDefault() *std_widgets.QStyleOptionViewItem {
	if ptr.Pointer() != nil {
		tmpValue := std_widgets.NewQStyleOptionViewItemFromPointer(C.MyTableView871826_ViewOptionsDefault(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_widgets.QStyleOptionViewItem).DestroyQStyleOptionViewItem)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_ViewportSizeHint
func callbackMyTableView871826_ViewportSizeHint(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "viewportSizeHint"); signal != nil {
		return std_core.PointerFromQSize((*(*func() *std_core.QSize)(signal))())
	}

	return std_core.PointerFromQSize(NewMyTableViewFromPointer(ptr).ViewportSizeHintDefault())
}

func (ptr *MyTableView) ViewportSizeHintDefault() *std_core.QSize {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQSizeFromPointer(C.MyTableView871826_ViewportSizeHintDefault(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_core.QSize).DestroyQSize)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_Activated
func callbackMyTableView871826_Activated(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "activated"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	}

}

//export callbackMyTableView871826_ClearSelection
func callbackMyTableView871826_ClearSelection(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "clearSelection"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ClearSelectionDefault()
	}
}

func (ptr *MyTableView) ClearSelectionDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ClearSelectionDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_Clicked
func callbackMyTableView871826_Clicked(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "clicked"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	}

}

//export callbackMyTableView871826_CloseEditor
func callbackMyTableView871826_CloseEditor(ptr unsafe.Pointer, editor unsafe.Pointer, hint C.longlong) {
	if signal := qt.GetSignal(ptr, "closeEditor"); signal != nil {
		(*(*func(*std_widgets.QWidget, std_widgets.QAbstractItemDelegate__EndEditHint))(signal))(std_widgets.NewQWidgetFromPointer(editor), std_widgets.QAbstractItemDelegate__EndEditHint(hint))
	} else {
		NewMyTableViewFromPointer(ptr).CloseEditorDefault(std_widgets.NewQWidgetFromPointer(editor), std_widgets.QAbstractItemDelegate__EndEditHint(hint))
	}
}

func (ptr *MyTableView) CloseEditorDefault(editor std_widgets.QWidget_ITF, hint std_widgets.QAbstractItemDelegate__EndEditHint) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_CloseEditorDefault(ptr.Pointer(), std_widgets.PointerFromQWidget(editor), C.longlong(hint))
	}
}

//export callbackMyTableView871826_CommitData
func callbackMyTableView871826_CommitData(ptr unsafe.Pointer, editor unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "commitData"); signal != nil {
		(*(*func(*std_widgets.QWidget))(signal))(std_widgets.NewQWidgetFromPointer(editor))
	} else {
		NewMyTableViewFromPointer(ptr).CommitDataDefault(std_widgets.NewQWidgetFromPointer(editor))
	}
}

func (ptr *MyTableView) CommitDataDefault(editor std_widgets.QWidget_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_CommitDataDefault(ptr.Pointer(), std_widgets.PointerFromQWidget(editor))
	}
}

//export callbackMyTableView871826_DataChanged
func callbackMyTableView871826_DataChanged(ptr unsafe.Pointer, topLeft unsafe.Pointer, bottomRight unsafe.Pointer, roles C.struct_Moc_PackedList) {
	if signal := qt.GetSignal(ptr, "dataChanged"); signal != nil {
		(*(*func(*std_core.QModelIndex, *std_core.QModelIndex, []int))(signal))(std_core.NewQModelIndexFromPointer(topLeft), std_core.NewQModelIndexFromPointer(bottomRight), func(l C.struct_Moc_PackedList) []int {
			out := make([]int, int(l.len))
			tmpList := NewMyTableViewFromPointer(l.data)
			for i := 0; i < len(out); i++ {
				out[i] = tmpList.__dataChanged_roles_atList(i)
			}
			return out
		}(roles))
	} else {
		NewMyTableViewFromPointer(ptr).DataChangedDefault(std_core.NewQModelIndexFromPointer(topLeft), std_core.NewQModelIndexFromPointer(bottomRight), func(l C.struct_Moc_PackedList) []int {
			out := make([]int, int(l.len))
			tmpList := NewMyTableViewFromPointer(l.data)
			for i := 0; i < len(out); i++ {
				out[i] = tmpList.__dataChanged_roles_atList(i)
			}
			return out
		}(roles))
	}
}

func (ptr *MyTableView) DataChangedDefault(topLeft std_core.QModelIndex_ITF, bottomRight std_core.QModelIndex_ITF, roles []int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DataChangedDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(topLeft), std_core.PointerFromQModelIndex(bottomRight), func() unsafe.Pointer {
			tmpList := NewMyTableViewFromPointer(NewMyTableViewFromPointer(nil).__dataChanged_roles_newList())
			for _, v := range roles {
				tmpList.__dataChanged_roles_setList(v)
			}
			return tmpList.Pointer()
		}())
	}
}

//export callbackMyTableView871826_DoubleClicked
func callbackMyTableView871826_DoubleClicked(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "doubleClicked"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	}

}

//export callbackMyTableView871826_DragEnterEvent
func callbackMyTableView871826_DragEnterEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragEnterEvent"); signal != nil {
		(*(*func(*std_gui.QDragEnterEvent))(signal))(std_gui.NewQDragEnterEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).DragEnterEventDefault(std_gui.NewQDragEnterEventFromPointer(event))
	}
}

func (ptr *MyTableView) DragEnterEventDefault(event std_gui.QDragEnterEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DragEnterEventDefault(ptr.Pointer(), std_gui.PointerFromQDragEnterEvent(event))
	}
}

//export callbackMyTableView871826_DragLeaveEvent
func callbackMyTableView871826_DragLeaveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragLeaveEvent"); signal != nil {
		(*(*func(*std_gui.QDragLeaveEvent))(signal))(std_gui.NewQDragLeaveEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).DragLeaveEventDefault(std_gui.NewQDragLeaveEventFromPointer(event))
	}
}

func (ptr *MyTableView) DragLeaveEventDefault(event std_gui.QDragLeaveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DragLeaveEventDefault(ptr.Pointer(), std_gui.PointerFromQDragLeaveEvent(event))
	}
}

//export callbackMyTableView871826_DragMoveEvent
func callbackMyTableView871826_DragMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragMoveEvent"); signal != nil {
		(*(*func(*std_gui.QDragMoveEvent))(signal))(std_gui.NewQDragMoveEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).DragMoveEventDefault(std_gui.NewQDragMoveEventFromPointer(event))
	}
}

func (ptr *MyTableView) DragMoveEventDefault(event std_gui.QDragMoveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DragMoveEventDefault(ptr.Pointer(), std_gui.PointerFromQDragMoveEvent(event))
	}
}

//export callbackMyTableView871826_DropEvent
func callbackMyTableView871826_DropEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dropEvent"); signal != nil {
		(*(*func(*std_gui.QDropEvent))(signal))(std_gui.NewQDropEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).DropEventDefault(std_gui.NewQDropEventFromPointer(event))
	}
}

func (ptr *MyTableView) DropEventDefault(event std_gui.QDropEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DropEventDefault(ptr.Pointer(), std_gui.PointerFromQDropEvent(event))
	}
}

//export callbackMyTableView871826_Edit
func callbackMyTableView871826_Edit(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "edit"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	} else {
		NewMyTableViewFromPointer(ptr).EditDefault(std_core.NewQModelIndexFromPointer(index))
	}
}

func (ptr *MyTableView) EditDefault(index std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_EditDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index))
	}
}

//export callbackMyTableView871826_Edit2
func callbackMyTableView871826_Edit2(ptr unsafe.Pointer, index unsafe.Pointer, trigger C.longlong, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "edit2"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QModelIndex, std_widgets.QAbstractItemView__EditTrigger, *std_core.QEvent) bool)(signal))(std_core.NewQModelIndexFromPointer(index), std_widgets.QAbstractItemView__EditTrigger(trigger), std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).Edit2Default(std_core.NewQModelIndexFromPointer(index), std_widgets.QAbstractItemView__EditTrigger(trigger), std_core.NewQEventFromPointer(event)))))
}

func (ptr *MyTableView) Edit2Default(index std_core.QModelIndex_ITF, trigger std_widgets.QAbstractItemView__EditTrigger, event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_Edit2Default(ptr.Pointer(), std_core.PointerFromQModelIndex(index), C.longlong(trigger), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackMyTableView871826_EditorDestroyed
func callbackMyTableView871826_EditorDestroyed(ptr unsafe.Pointer, editor unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "editorDestroyed"); signal != nil {
		(*(*func(*std_core.QObject))(signal))(std_core.NewQObjectFromPointer(editor))
	} else {
		NewMyTableViewFromPointer(ptr).EditorDestroyedDefault(std_core.NewQObjectFromPointer(editor))
	}
}

func (ptr *MyTableView) EditorDestroyedDefault(editor std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_EditorDestroyedDefault(ptr.Pointer(), std_core.PointerFromQObject(editor))
	}
}

//export callbackMyTableView871826_Entered
func callbackMyTableView871826_Entered(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "entered"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	}

}

//export callbackMyTableView871826_Event
func callbackMyTableView871826_Event(ptr unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "event"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QEvent) bool)(signal))(std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).EventDefault(std_core.NewQEventFromPointer(event)))))
}

func (ptr *MyTableView) EventDefault(event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_EventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackMyTableView871826_EventFilter
func callbackMyTableView871826_EventFilter(ptr unsafe.Pointer, object unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "eventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QObject, *std_core.QEvent) bool)(signal))(std_core.NewQObjectFromPointer(object), std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).EventFilterDefault(std_core.NewQObjectFromPointer(object), std_core.NewQEventFromPointer(event)))))
}

func (ptr *MyTableView) EventFilterDefault(object std_core.QObject_ITF, event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_EventFilterDefault(ptr.Pointer(), std_core.PointerFromQObject(object), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackMyTableView871826_FocusInEvent
func callbackMyTableView871826_FocusInEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusInEvent"); signal != nil {
		(*(*func(*std_gui.QFocusEvent))(signal))(std_gui.NewQFocusEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).FocusInEventDefault(std_gui.NewQFocusEventFromPointer(event))
	}
}

func (ptr *MyTableView) FocusInEventDefault(event std_gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_FocusInEventDefault(ptr.Pointer(), std_gui.PointerFromQFocusEvent(event))
	}
}

//export callbackMyTableView871826_FocusNextPrevChild
func callbackMyTableView871826_FocusNextPrevChild(ptr unsafe.Pointer, next C.char) C.char {
	if signal := qt.GetSignal(ptr, "focusNextPrevChild"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(bool) bool)(signal))(int8(next) != 0))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).FocusNextPrevChildDefault(int8(next) != 0))))
}

func (ptr *MyTableView) FocusNextPrevChildDefault(next bool) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_FocusNextPrevChildDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(next))))) != 0
	}
	return false
}

//export callbackMyTableView871826_FocusOutEvent
func callbackMyTableView871826_FocusOutEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusOutEvent"); signal != nil {
		(*(*func(*std_gui.QFocusEvent))(signal))(std_gui.NewQFocusEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).FocusOutEventDefault(std_gui.NewQFocusEventFromPointer(event))
	}
}

func (ptr *MyTableView) FocusOutEventDefault(event std_gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_FocusOutEventDefault(ptr.Pointer(), std_gui.PointerFromQFocusEvent(event))
	}
}

//export callbackMyTableView871826_IconSizeChanged
func callbackMyTableView871826_IconSizeChanged(ptr unsafe.Pointer, size unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "iconSizeChanged"); signal != nil {
		(*(*func(*std_core.QSize))(signal))(std_core.NewQSizeFromPointer(size))
	}

}

//export callbackMyTableView871826_InputMethodEvent
func callbackMyTableView871826_InputMethodEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "inputMethodEvent"); signal != nil {
		(*(*func(*std_gui.QInputMethodEvent))(signal))(std_gui.NewQInputMethodEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).InputMethodEventDefault(std_gui.NewQInputMethodEventFromPointer(event))
	}
}

func (ptr *MyTableView) InputMethodEventDefault(event std_gui.QInputMethodEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_InputMethodEventDefault(ptr.Pointer(), std_gui.PointerFromQInputMethodEvent(event))
	}
}

//export callbackMyTableView871826_InputMethodQuery
func callbackMyTableView871826_InputMethodQuery(ptr unsafe.Pointer, query C.longlong) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "inputMethodQuery"); signal != nil {
		return std_core.PointerFromQVariant((*(*func(std_core.Qt__InputMethodQuery) *std_core.QVariant)(signal))(std_core.Qt__InputMethodQuery(query)))
	}

	return std_core.PointerFromQVariant(NewMyTableViewFromPointer(ptr).InputMethodQueryDefault(std_core.Qt__InputMethodQuery(query)))
}

func (ptr *MyTableView) InputMethodQueryDefault(query std_core.Qt__InputMethodQuery) *std_core.QVariant {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQVariantFromPointer(C.MyTableView871826_InputMethodQueryDefault(ptr.Pointer(), C.longlong(query)))
		qt.SetFinalizer(tmpValue, (*std_core.QVariant).DestroyQVariant)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_KeyPressEvent
func callbackMyTableView871826_KeyPressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyPressEvent"); signal != nil {
		(*(*func(*std_gui.QKeyEvent))(signal))(std_gui.NewQKeyEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).KeyPressEventDefault(std_gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *MyTableView) KeyPressEventDefault(event std_gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_KeyPressEventDefault(ptr.Pointer(), std_gui.PointerFromQKeyEvent(event))
	}
}

//export callbackMyTableView871826_KeyboardSearch
func callbackMyTableView871826_KeyboardSearch(ptr unsafe.Pointer, search C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "keyboardSearch"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(search))
	} else {
		NewMyTableViewFromPointer(ptr).KeyboardSearchDefault(cGoUnpackString(search))
	}
}

func (ptr *MyTableView) KeyboardSearchDefault(search string) {
	if ptr.Pointer() != nil {
		var searchC *C.char
		if search != "" {
			searchC = C.CString(search)
			defer C.free(unsafe.Pointer(searchC))
		}
		C.MyTableView871826_KeyboardSearchDefault(ptr.Pointer(), C.struct_Moc_PackedString{data: searchC, len: C.longlong(len(search))})
	}
}

//export callbackMyTableView871826_MouseDoubleClickEvent
func callbackMyTableView871826_MouseDoubleClickEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseDoubleClickEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).MouseDoubleClickEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *MyTableView) MouseDoubleClickEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_MouseDoubleClickEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackMyTableView871826_MouseMoveEvent
func callbackMyTableView871826_MouseMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseMoveEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).MouseMoveEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *MyTableView) MouseMoveEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_MouseMoveEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackMyTableView871826_MousePressEvent
func callbackMyTableView871826_MousePressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mousePressEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).MousePressEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *MyTableView) MousePressEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_MousePressEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackMyTableView871826_MouseReleaseEvent
func callbackMyTableView871826_MouseReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseReleaseEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).MouseReleaseEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *MyTableView) MouseReleaseEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_MouseReleaseEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackMyTableView871826_Pressed
func callbackMyTableView871826_Pressed(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "pressed"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	}

}

//export callbackMyTableView871826_Reset
func callbackMyTableView871826_Reset(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "reset"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ResetDefault()
	}
}

func (ptr *MyTableView) ResetDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResetDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ResizeEvent
func callbackMyTableView871826_ResizeEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "resizeEvent"); signal != nil {
		(*(*func(*std_gui.QResizeEvent))(signal))(std_gui.NewQResizeEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).ResizeEventDefault(std_gui.NewQResizeEventFromPointer(event))
	}
}

func (ptr *MyTableView) ResizeEventDefault(event std_gui.QResizeEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ResizeEventDefault(ptr.Pointer(), std_gui.PointerFromQResizeEvent(event))
	}
}

//export callbackMyTableView871826_RowsAboutToBeRemoved
func callbackMyTableView871826_RowsAboutToBeRemoved(ptr unsafe.Pointer, parent unsafe.Pointer, start C.int, end C.int) {
	if signal := qt.GetSignal(ptr, "rowsAboutToBeRemoved"); signal != nil {
		(*(*func(*std_core.QModelIndex, int, int))(signal))(std_core.NewQModelIndexFromPointer(parent), int(int32(start)), int(int32(end)))
	} else {
		NewMyTableViewFromPointer(ptr).RowsAboutToBeRemovedDefault(std_core.NewQModelIndexFromPointer(parent), int(int32(start)), int(int32(end)))
	}
}

func (ptr *MyTableView) RowsAboutToBeRemovedDefault(parent std_core.QModelIndex_ITF, start int, end int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RowsAboutToBeRemovedDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(parent), C.int(int32(start)), C.int(int32(end)))
	}
}

//export callbackMyTableView871826_RowsInserted
func callbackMyTableView871826_RowsInserted(ptr unsafe.Pointer, parent unsafe.Pointer, start C.int, end C.int) {
	if signal := qt.GetSignal(ptr, "rowsInserted"); signal != nil {
		(*(*func(*std_core.QModelIndex, int, int))(signal))(std_core.NewQModelIndexFromPointer(parent), int(int32(start)), int(int32(end)))
	} else {
		NewMyTableViewFromPointer(ptr).RowsInsertedDefault(std_core.NewQModelIndexFromPointer(parent), int(int32(start)), int(int32(end)))
	}
}

func (ptr *MyTableView) RowsInsertedDefault(parent std_core.QModelIndex_ITF, start int, end int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RowsInsertedDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(parent), C.int(int32(start)), C.int(int32(end)))
	}
}

//export callbackMyTableView871826_ScrollTo
func callbackMyTableView871826_ScrollTo(ptr unsafe.Pointer, index unsafe.Pointer, hint C.longlong) {
	if signal := qt.GetSignal(ptr, "scrollTo"); signal != nil {
		(*(*func(*std_core.QModelIndex, std_widgets.QAbstractItemView__ScrollHint))(signal))(std_core.NewQModelIndexFromPointer(index), std_widgets.QAbstractItemView__ScrollHint(hint))
	} else {
		NewMyTableViewFromPointer(ptr).ScrollToDefault(std_core.NewQModelIndexFromPointer(index), std_widgets.QAbstractItemView__ScrollHint(hint))
	}
}

func (ptr *MyTableView) ScrollToDefault(index std_core.QModelIndex_ITF, hint std_widgets.QAbstractItemView__ScrollHint) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ScrollToDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index), C.longlong(hint))
	}
}

//export callbackMyTableView871826_ScrollToBottom
func callbackMyTableView871826_ScrollToBottom(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "scrollToBottom"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ScrollToBottomDefault()
	}
}

func (ptr *MyTableView) ScrollToBottomDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ScrollToBottomDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ScrollToTop
func callbackMyTableView871826_ScrollToTop(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "scrollToTop"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ScrollToTopDefault()
	}
}

func (ptr *MyTableView) ScrollToTopDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ScrollToTopDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_SelectAll
func callbackMyTableView871826_SelectAll(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "selectAll"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).SelectAllDefault()
	}
}

func (ptr *MyTableView) SelectAllDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SelectAllDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_SelectionCommand
func callbackMyTableView871826_SelectionCommand(ptr unsafe.Pointer, index unsafe.Pointer, event unsafe.Pointer) C.longlong {
	if signal := qt.GetSignal(ptr, "selectionCommand"); signal != nil {
		return C.longlong((*(*func(*std_core.QModelIndex, *std_core.QEvent) std_core.QItemSelectionModel__SelectionFlag)(signal))(std_core.NewQModelIndexFromPointer(index), std_core.NewQEventFromPointer(event)))
	}

	return C.longlong(NewMyTableViewFromPointer(ptr).SelectionCommandDefault(std_core.NewQModelIndexFromPointer(index), std_core.NewQEventFromPointer(event)))
}

func (ptr *MyTableView) SelectionCommandDefault(index std_core.QModelIndex_ITF, event std_core.QEvent_ITF) std_core.QItemSelectionModel__SelectionFlag {
	if ptr.Pointer() != nil {
		return std_core.QItemSelectionModel__SelectionFlag(C.MyTableView871826_SelectionCommandDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index), std_core.PointerFromQEvent(event)))
	}
	return 0
}

//export callbackMyTableView871826_SetCurrentIndex
func callbackMyTableView871826_SetCurrentIndex(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setCurrentIndex"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	} else {
		NewMyTableViewFromPointer(ptr).SetCurrentIndexDefault(std_core.NewQModelIndexFromPointer(index))
	}
}

func (ptr *MyTableView) SetCurrentIndexDefault(index std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetCurrentIndexDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index))
	}
}

//export callbackMyTableView871826_StartDrag
func callbackMyTableView871826_StartDrag(ptr unsafe.Pointer, supportedActions C.longlong) {
	if signal := qt.GetSignal(ptr, "startDrag"); signal != nil {
		(*(*func(std_core.Qt__DropAction))(signal))(std_core.Qt__DropAction(supportedActions))
	} else {
		NewMyTableViewFromPointer(ptr).StartDragDefault(std_core.Qt__DropAction(supportedActions))
	}
}

func (ptr *MyTableView) StartDragDefault(supportedActions std_core.Qt__DropAction) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_StartDragDefault(ptr.Pointer(), C.longlong(supportedActions))
	}
}

//export callbackMyTableView871826_Update
func callbackMyTableView871826_Update(ptr unsafe.Pointer, index unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "update"); signal != nil {
		(*(*func(*std_core.QModelIndex))(signal))(std_core.NewQModelIndexFromPointer(index))
	} else {
		NewMyTableViewFromPointer(ptr).UpdateDefault(std_core.NewQModelIndexFromPointer(index))
	}
}

func (ptr *MyTableView) UpdateDefault(index std_core.QModelIndex_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_UpdateDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index))
	}
}

//export callbackMyTableView871826_ViewportEntered
func callbackMyTableView871826_ViewportEntered(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "viewportEntered"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackMyTableView871826_ViewportEvent
func callbackMyTableView871826_ViewportEvent(ptr unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "viewportEvent"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QEvent) bool)(signal))(std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).ViewportEventDefault(std_core.NewQEventFromPointer(event)))))
}

func (ptr *MyTableView) ViewportEventDefault(event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_ViewportEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackMyTableView871826_VisualRect
func callbackMyTableView871826_VisualRect(ptr unsafe.Pointer, index unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "visualRect"); signal != nil {
		return std_core.PointerFromQRect((*(*func(*std_core.QModelIndex) *std_core.QRect)(signal))(std_core.NewQModelIndexFromPointer(index)))
	}

	return std_core.PointerFromQRect(NewMyTableViewFromPointer(ptr).VisualRectDefault(std_core.NewQModelIndexFromPointer(index)))
}

func (ptr *MyTableView) VisualRectDefault(index std_core.QModelIndex_ITF) *std_core.QRect {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQRectFromPointer(C.MyTableView871826_VisualRectDefault(ptr.Pointer(), std_core.PointerFromQModelIndex(index)))
		qt.SetFinalizer(tmpValue, (*std_core.QRect).DestroyQRect)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_VisualRegionForSelection
func callbackMyTableView871826_VisualRegionForSelection(ptr unsafe.Pointer, selection unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "visualRegionForSelection"); signal != nil {
		return std_gui.PointerFromQRegion((*(*func(*std_core.QItemSelection) *std_gui.QRegion)(signal))(std_core.NewQItemSelectionFromPointer(selection)))
	}

	return std_gui.PointerFromQRegion(NewMyTableViewFromPointer(ptr).VisualRegionForSelectionDefault(std_core.NewQItemSelectionFromPointer(selection)))
}

func (ptr *MyTableView) VisualRegionForSelectionDefault(selection std_core.QItemSelection_ITF) *std_gui.QRegion {
	if ptr.Pointer() != nil {
		tmpValue := std_gui.NewQRegionFromPointer(C.MyTableView871826_VisualRegionForSelectionDefault(ptr.Pointer(), std_core.PointerFromQItemSelection(selection)))
		qt.SetFinalizer(tmpValue, (*std_gui.QRegion).DestroyQRegion)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_ContextMenuEvent
func callbackMyTableView871826_ContextMenuEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "contextMenuEvent"); signal != nil {
		(*(*func(*std_gui.QContextMenuEvent))(signal))(std_gui.NewQContextMenuEventFromPointer(e))
	} else {
		NewMyTableViewFromPointer(ptr).ContextMenuEventDefault(std_gui.NewQContextMenuEventFromPointer(e))
	}
}

func (ptr *MyTableView) ContextMenuEventDefault(e std_gui.QContextMenuEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ContextMenuEventDefault(ptr.Pointer(), std_gui.PointerFromQContextMenuEvent(e))
	}
}

//export callbackMyTableView871826_MinimumSizeHint
func callbackMyTableView871826_MinimumSizeHint(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "minimumSizeHint"); signal != nil {
		return std_core.PointerFromQSize((*(*func() *std_core.QSize)(signal))())
	}

	return std_core.PointerFromQSize(NewMyTableViewFromPointer(ptr).MinimumSizeHintDefault())
}

func (ptr *MyTableView) MinimumSizeHintDefault() *std_core.QSize {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQSizeFromPointer(C.MyTableView871826_MinimumSizeHintDefault(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_core.QSize).DestroyQSize)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_ScrollContentsBy
func callbackMyTableView871826_ScrollContentsBy(ptr unsafe.Pointer, dx C.int, dy C.int) {
	if signal := qt.GetSignal(ptr, "scrollContentsBy"); signal != nil {
		(*(*func(int, int))(signal))(int(int32(dx)), int(int32(dy)))
	} else {
		NewMyTableViewFromPointer(ptr).ScrollContentsByDefault(int(int32(dx)), int(int32(dy)))
	}
}

func (ptr *MyTableView) ScrollContentsByDefault(dx int, dy int) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ScrollContentsByDefault(ptr.Pointer(), C.int(int32(dx)), C.int(int32(dy)))
	}
}

//export callbackMyTableView871826_SetupViewport
func callbackMyTableView871826_SetupViewport(ptr unsafe.Pointer, viewport unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setupViewport"); signal != nil {
		(*(*func(*std_widgets.QWidget))(signal))(std_widgets.NewQWidgetFromPointer(viewport))
	} else {
		NewMyTableViewFromPointer(ptr).SetupViewportDefault(std_widgets.NewQWidgetFromPointer(viewport))
	}
}

func (ptr *MyTableView) SetupViewportDefault(viewport std_widgets.QWidget_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetupViewportDefault(ptr.Pointer(), std_widgets.PointerFromQWidget(viewport))
	}
}

//export callbackMyTableView871826_SizeHint
func callbackMyTableView871826_SizeHint(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "sizeHint"); signal != nil {
		return std_core.PointerFromQSize((*(*func() *std_core.QSize)(signal))())
	}

	return std_core.PointerFromQSize(NewMyTableViewFromPointer(ptr).SizeHintDefault())
}

func (ptr *MyTableView) SizeHintDefault() *std_core.QSize {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQSizeFromPointer(C.MyTableView871826_SizeHintDefault(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_core.QSize).DestroyQSize)
		return tmpValue
	}
	return nil
}

//export callbackMyTableView871826_WheelEvent
func callbackMyTableView871826_WheelEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "wheelEvent"); signal != nil {
		(*(*func(*std_gui.QWheelEvent))(signal))(std_gui.NewQWheelEventFromPointer(e))
	} else {
		NewMyTableViewFromPointer(ptr).WheelEventDefault(std_gui.NewQWheelEventFromPointer(e))
	}
}

func (ptr *MyTableView) WheelEventDefault(e std_gui.QWheelEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_WheelEventDefault(ptr.Pointer(), std_gui.PointerFromQWheelEvent(e))
	}
}

//export callbackMyTableView871826_ChangeEvent
func callbackMyTableView871826_ChangeEvent(ptr unsafe.Pointer, ev unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "changeEvent"); signal != nil {
		(*(*func(*std_core.QEvent))(signal))(std_core.NewQEventFromPointer(ev))
	} else {
		NewMyTableViewFromPointer(ptr).ChangeEventDefault(std_core.NewQEventFromPointer(ev))
	}
}

func (ptr *MyTableView) ChangeEventDefault(ev std_core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ChangeEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(ev))
	}
}

//export callbackMyTableView871826_ActionEvent
func callbackMyTableView871826_ActionEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "actionEvent"); signal != nil {
		(*(*func(*std_gui.QActionEvent))(signal))(std_gui.NewQActionEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).ActionEventDefault(std_gui.NewQActionEventFromPointer(event))
	}
}

func (ptr *MyTableView) ActionEventDefault(event std_gui.QActionEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ActionEventDefault(ptr.Pointer(), std_gui.PointerFromQActionEvent(event))
	}
}

//export callbackMyTableView871826_Close
func callbackMyTableView871826_Close(ptr unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "close"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func() bool)(signal))())))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).CloseDefault())))
}

func (ptr *MyTableView) CloseDefault() bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_CloseDefault(ptr.Pointer())) != 0
	}
	return false
}

//export callbackMyTableView871826_CloseEvent
func callbackMyTableView871826_CloseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "closeEvent"); signal != nil {
		(*(*func(*std_gui.QCloseEvent))(signal))(std_gui.NewQCloseEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).CloseEventDefault(std_gui.NewQCloseEventFromPointer(event))
	}
}

func (ptr *MyTableView) CloseEventDefault(event std_gui.QCloseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_CloseEventDefault(ptr.Pointer(), std_gui.PointerFromQCloseEvent(event))
	}
}

//export callbackMyTableView871826_CustomContextMenuRequested
func callbackMyTableView871826_CustomContextMenuRequested(ptr unsafe.Pointer, pos unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customContextMenuRequested"); signal != nil {
		(*(*func(*std_core.QPoint))(signal))(std_core.NewQPointFromPointer(pos))
	}

}

//export callbackMyTableView871826_EnterEvent
func callbackMyTableView871826_EnterEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "enterEvent"); signal != nil {
		(*(*func(*std_core.QEvent))(signal))(std_core.NewQEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).EnterEventDefault(std_core.NewQEventFromPointer(event))
	}
}

func (ptr *MyTableView) EnterEventDefault(event std_core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_EnterEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))
	}
}

//export callbackMyTableView871826_HasHeightForWidth
func callbackMyTableView871826_HasHeightForWidth(ptr unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "hasHeightForWidth"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func() bool)(signal))())))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).HasHeightForWidthDefault())))
}

func (ptr *MyTableView) HasHeightForWidthDefault() bool {
	if ptr.Pointer() != nil {
		return int8(C.MyTableView871826_HasHeightForWidthDefault(ptr.Pointer())) != 0
	}
	return false
}

//export callbackMyTableView871826_HeightForWidth
func callbackMyTableView871826_HeightForWidth(ptr unsafe.Pointer, w C.int) C.int {
	if signal := qt.GetSignal(ptr, "heightForWidth"); signal != nil {
		return C.int(int32((*(*func(int) int)(signal))(int(int32(w)))))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).HeightForWidthDefault(int(int32(w)))))
}

func (ptr *MyTableView) HeightForWidthDefault(w int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_HeightForWidthDefault(ptr.Pointer(), C.int(int32(w)))))
	}
	return 0
}

//export callbackMyTableView871826_Hide
func callbackMyTableView871826_Hide(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hide"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).HideDefault()
	}
}

func (ptr *MyTableView) HideDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_HideDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_HideEvent
func callbackMyTableView871826_HideEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hideEvent"); signal != nil {
		(*(*func(*std_gui.QHideEvent))(signal))(std_gui.NewQHideEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).HideEventDefault(std_gui.NewQHideEventFromPointer(event))
	}
}

func (ptr *MyTableView) HideEventDefault(event std_gui.QHideEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_HideEventDefault(ptr.Pointer(), std_gui.PointerFromQHideEvent(event))
	}
}

//export callbackMyTableView871826_InitPainter
func callbackMyTableView871826_InitPainter(ptr unsafe.Pointer, painter unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "initPainter"); signal != nil {
		(*(*func(*std_gui.QPainter))(signal))(std_gui.NewQPainterFromPointer(painter))
	} else {
		NewMyTableViewFromPointer(ptr).InitPainterDefault(std_gui.NewQPainterFromPointer(painter))
	}
}

func (ptr *MyTableView) InitPainterDefault(painter std_gui.QPainter_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_InitPainterDefault(ptr.Pointer(), std_gui.PointerFromQPainter(painter))
	}
}

//export callbackMyTableView871826_KeyReleaseEvent
func callbackMyTableView871826_KeyReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyReleaseEvent"); signal != nil {
		(*(*func(*std_gui.QKeyEvent))(signal))(std_gui.NewQKeyEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).KeyReleaseEventDefault(std_gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *MyTableView) KeyReleaseEventDefault(event std_gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_KeyReleaseEventDefault(ptr.Pointer(), std_gui.PointerFromQKeyEvent(event))
	}
}

//export callbackMyTableView871826_LeaveEvent
func callbackMyTableView871826_LeaveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "leaveEvent"); signal != nil {
		(*(*func(*std_core.QEvent))(signal))(std_core.NewQEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).LeaveEventDefault(std_core.NewQEventFromPointer(event))
	}
}

func (ptr *MyTableView) LeaveEventDefault(event std_core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_LeaveEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))
	}
}

//export callbackMyTableView871826_Lower
func callbackMyTableView871826_Lower(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "lower"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).LowerDefault()
	}
}

func (ptr *MyTableView) LowerDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_LowerDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_Metric
func callbackMyTableView871826_Metric(ptr unsafe.Pointer, m C.longlong) C.int {
	if signal := qt.GetSignal(ptr, "metric"); signal != nil {
		return C.int(int32((*(*func(std_gui.QPaintDevice__PaintDeviceMetric) int)(signal))(std_gui.QPaintDevice__PaintDeviceMetric(m))))
	}

	return C.int(int32(NewMyTableViewFromPointer(ptr).MetricDefault(std_gui.QPaintDevice__PaintDeviceMetric(m))))
}

func (ptr *MyTableView) MetricDefault(m std_gui.QPaintDevice__PaintDeviceMetric) int {
	if ptr.Pointer() != nil {
		return int(int32(C.MyTableView871826_MetricDefault(ptr.Pointer(), C.longlong(m))))
	}
	return 0
}

//export callbackMyTableView871826_MoveEvent
func callbackMyTableView871826_MoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "moveEvent"); signal != nil {
		(*(*func(*std_gui.QMoveEvent))(signal))(std_gui.NewQMoveEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).MoveEventDefault(std_gui.NewQMoveEventFromPointer(event))
	}
}

func (ptr *MyTableView) MoveEventDefault(event std_gui.QMoveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_MoveEventDefault(ptr.Pointer(), std_gui.PointerFromQMoveEvent(event))
	}
}

//export callbackMyTableView871826_NativeEvent
func callbackMyTableView871826_NativeEvent(ptr unsafe.Pointer, eventType unsafe.Pointer, message unsafe.Pointer, result *C.long) C.char {
	var resultR int
	if result != nil {
		resultR = int(int32(*result))
		defer func() { *result = C.long(int32(resultR)) }()
	}
	if signal := qt.GetSignal(ptr, "nativeEvent"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QByteArray, unsafe.Pointer, *int) bool)(signal))(std_core.NewQByteArrayFromPointer(eventType), message, &resultR))))
	}

	return C.char(int8(qt.GoBoolToInt(NewMyTableViewFromPointer(ptr).NativeEventDefault(std_core.NewQByteArrayFromPointer(eventType), message, &resultR))))
}

func (ptr *MyTableView) NativeEventDefault(eventType std_core.QByteArray_ITF, message unsafe.Pointer, result *int) bool {
	if ptr.Pointer() != nil {
		var resultC C.long
		if result != nil {
			resultC = C.long(int32(*result))
			defer func() { *result = int(int32(resultC)) }()
		}
		return int8(C.MyTableView871826_NativeEventDefault(ptr.Pointer(), std_core.PointerFromQByteArray(eventType), message, &resultC)) != 0
	}
	return false
}

//export callbackMyTableView871826_PaintEngine
func callbackMyTableView871826_PaintEngine(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "paintEngine"); signal != nil {
		return std_gui.PointerFromQPaintEngine((*(*func() *std_gui.QPaintEngine)(signal))())
	}

	return std_gui.PointerFromQPaintEngine(NewMyTableViewFromPointer(ptr).PaintEngineDefault())
}

func (ptr *MyTableView) PaintEngineDefault() *std_gui.QPaintEngine {
	if ptr.Pointer() != nil {
		return std_gui.NewQPaintEngineFromPointer(C.MyTableView871826_PaintEngineDefault(ptr.Pointer()))
	}
	return nil
}

//export callbackMyTableView871826_Raise
func callbackMyTableView871826_Raise(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "raise"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).RaiseDefault()
	}
}

func (ptr *MyTableView) RaiseDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RaiseDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_Repaint
func callbackMyTableView871826_Repaint(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "repaint"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).RepaintDefault()
	}
}

func (ptr *MyTableView) RepaintDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_RepaintDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_SetDisabled
func callbackMyTableView871826_SetDisabled(ptr unsafe.Pointer, disable C.char) {
	if signal := qt.GetSignal(ptr, "setDisabled"); signal != nil {
		(*(*func(bool))(signal))(int8(disable) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetDisabledDefault(int8(disable) != 0)
	}
}

func (ptr *MyTableView) SetDisabledDefault(disable bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetDisabledDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(disable))))
	}
}

//export callbackMyTableView871826_SetEnabled
func callbackMyTableView871826_SetEnabled(ptr unsafe.Pointer, vbo C.char) {
	if signal := qt.GetSignal(ptr, "setEnabled"); signal != nil {
		(*(*func(bool))(signal))(int8(vbo) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetEnabledDefault(int8(vbo) != 0)
	}
}

func (ptr *MyTableView) SetEnabledDefault(vbo bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetEnabledDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(vbo))))
	}
}

//export callbackMyTableView871826_SetFocus2
func callbackMyTableView871826_SetFocus2(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setFocus2"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).SetFocus2Default()
	}
}

func (ptr *MyTableView) SetFocus2Default() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetFocus2Default(ptr.Pointer())
	}
}

//export callbackMyTableView871826_SetHidden
func callbackMyTableView871826_SetHidden(ptr unsafe.Pointer, hidden C.char) {
	if signal := qt.GetSignal(ptr, "setHidden"); signal != nil {
		(*(*func(bool))(signal))(int8(hidden) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetHiddenDefault(int8(hidden) != 0)
	}
}

func (ptr *MyTableView) SetHiddenDefault(hidden bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetHiddenDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(hidden))))
	}
}

//export callbackMyTableView871826_SetStyleSheet
func callbackMyTableView871826_SetStyleSheet(ptr unsafe.Pointer, styleSheet C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "setStyleSheet"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(styleSheet))
	} else {
		NewMyTableViewFromPointer(ptr).SetStyleSheetDefault(cGoUnpackString(styleSheet))
	}
}

func (ptr *MyTableView) SetStyleSheetDefault(styleSheet string) {
	if ptr.Pointer() != nil {
		var styleSheetC *C.char
		if styleSheet != "" {
			styleSheetC = C.CString(styleSheet)
			defer C.free(unsafe.Pointer(styleSheetC))
		}
		C.MyTableView871826_SetStyleSheetDefault(ptr.Pointer(), C.struct_Moc_PackedString{data: styleSheetC, len: C.longlong(len(styleSheet))})
	}
}

//export callbackMyTableView871826_SetVisible
func callbackMyTableView871826_SetVisible(ptr unsafe.Pointer, visible C.char) {
	if signal := qt.GetSignal(ptr, "setVisible"); signal != nil {
		(*(*func(bool))(signal))(int8(visible) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetVisibleDefault(int8(visible) != 0)
	}
}

func (ptr *MyTableView) SetVisibleDefault(visible bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetVisibleDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(visible))))
	}
}

//export callbackMyTableView871826_SetWindowModified
func callbackMyTableView871826_SetWindowModified(ptr unsafe.Pointer, vbo C.char) {
	if signal := qt.GetSignal(ptr, "setWindowModified"); signal != nil {
		(*(*func(bool))(signal))(int8(vbo) != 0)
	} else {
		NewMyTableViewFromPointer(ptr).SetWindowModifiedDefault(int8(vbo) != 0)
	}
}

func (ptr *MyTableView) SetWindowModifiedDefault(vbo bool) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_SetWindowModifiedDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(vbo))))
	}
}

//export callbackMyTableView871826_SetWindowTitle
func callbackMyTableView871826_SetWindowTitle(ptr unsafe.Pointer, vqs C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "setWindowTitle"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(vqs))
	} else {
		NewMyTableViewFromPointer(ptr).SetWindowTitleDefault(cGoUnpackString(vqs))
	}
}

func (ptr *MyTableView) SetWindowTitleDefault(vqs string) {
	if ptr.Pointer() != nil {
		var vqsC *C.char
		if vqs != "" {
			vqsC = C.CString(vqs)
			defer C.free(unsafe.Pointer(vqsC))
		}
		C.MyTableView871826_SetWindowTitleDefault(ptr.Pointer(), C.struct_Moc_PackedString{data: vqsC, len: C.longlong(len(vqs))})
	}
}

//export callbackMyTableView871826_Show
func callbackMyTableView871826_Show(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "show"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ShowDefault()
	}
}

func (ptr *MyTableView) ShowDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ShowEvent
func callbackMyTableView871826_ShowEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showEvent"); signal != nil {
		(*(*func(*std_gui.QShowEvent))(signal))(std_gui.NewQShowEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).ShowEventDefault(std_gui.NewQShowEventFromPointer(event))
	}
}

func (ptr *MyTableView) ShowEventDefault(event std_gui.QShowEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowEventDefault(ptr.Pointer(), std_gui.PointerFromQShowEvent(event))
	}
}

//export callbackMyTableView871826_ShowFullScreen
func callbackMyTableView871826_ShowFullScreen(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showFullScreen"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ShowFullScreenDefault()
	}
}

func (ptr *MyTableView) ShowFullScreenDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowFullScreenDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ShowMaximized
func callbackMyTableView871826_ShowMaximized(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showMaximized"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ShowMaximizedDefault()
	}
}

func (ptr *MyTableView) ShowMaximizedDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowMaximizedDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ShowMinimized
func callbackMyTableView871826_ShowMinimized(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showMinimized"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ShowMinimizedDefault()
	}
}

func (ptr *MyTableView) ShowMinimizedDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowMinimizedDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_ShowNormal
func callbackMyTableView871826_ShowNormal(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showNormal"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).ShowNormalDefault()
	}
}

func (ptr *MyTableView) ShowNormalDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ShowNormalDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_TabletEvent
func callbackMyTableView871826_TabletEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "tabletEvent"); signal != nil {
		(*(*func(*std_gui.QTabletEvent))(signal))(std_gui.NewQTabletEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).TabletEventDefault(std_gui.NewQTabletEventFromPointer(event))
	}
}

func (ptr *MyTableView) TabletEventDefault(event std_gui.QTabletEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_TabletEventDefault(ptr.Pointer(), std_gui.PointerFromQTabletEvent(event))
	}
}

//export callbackMyTableView871826_UpdateMicroFocus
func callbackMyTableView871826_UpdateMicroFocus(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "updateMicroFocus"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).UpdateMicroFocusDefault()
	}
}

func (ptr *MyTableView) UpdateMicroFocusDefault() {
	if ptr.Pointer() != nil {
		C.MyTableView871826_UpdateMicroFocusDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_WindowIconChanged
func callbackMyTableView871826_WindowIconChanged(ptr unsafe.Pointer, icon unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "windowIconChanged"); signal != nil {
		(*(*func(*std_gui.QIcon))(signal))(std_gui.NewQIconFromPointer(icon))
	}

}

//export callbackMyTableView871826_WindowTitleChanged
func callbackMyTableView871826_WindowTitleChanged(ptr unsafe.Pointer, title C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "windowTitleChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(title))
	}

}

//export callbackMyTableView871826_ChildEvent
func callbackMyTableView871826_ChildEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "childEvent"); signal != nil {
		(*(*func(*std_core.QChildEvent))(signal))(std_core.NewQChildEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).ChildEventDefault(std_core.NewQChildEventFromPointer(event))
	}
}

func (ptr *MyTableView) ChildEventDefault(event std_core.QChildEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ChildEventDefault(ptr.Pointer(), std_core.PointerFromQChildEvent(event))
	}
}

//export callbackMyTableView871826_ConnectNotify
func callbackMyTableView871826_ConnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "connectNotify"); signal != nil {
		(*(*func(*std_core.QMetaMethod))(signal))(std_core.NewQMetaMethodFromPointer(sign))
	} else {
		NewMyTableViewFromPointer(ptr).ConnectNotifyDefault(std_core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *MyTableView) ConnectNotifyDefault(sign std_core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_ConnectNotifyDefault(ptr.Pointer(), std_core.PointerFromQMetaMethod(sign))
	}
}

//export callbackMyTableView871826_CustomEvent
func callbackMyTableView871826_CustomEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customEvent"); signal != nil {
		(*(*func(*std_core.QEvent))(signal))(std_core.NewQEventFromPointer(event))
	} else {
		NewMyTableViewFromPointer(ptr).CustomEventDefault(std_core.NewQEventFromPointer(event))
	}
}

func (ptr *MyTableView) CustomEventDefault(event std_core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_CustomEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))
	}
}

//export callbackMyTableView871826_DeleteLater
func callbackMyTableView871826_DeleteLater(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "deleteLater"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewMyTableViewFromPointer(ptr).DeleteLaterDefault()
	}
}

func (ptr *MyTableView) DeleteLaterDefault() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.MyTableView871826_DeleteLaterDefault(ptr.Pointer())
	}
}

//export callbackMyTableView871826_Destroyed
func callbackMyTableView871826_Destroyed(ptr unsafe.Pointer, obj unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "destroyed"); signal != nil {
		(*(*func(*std_core.QObject))(signal))(std_core.NewQObjectFromPointer(obj))
	}
	qt.Unregister(ptr)

}

//export callbackMyTableView871826_DisconnectNotify
func callbackMyTableView871826_DisconnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "disconnectNotify"); signal != nil {
		(*(*func(*std_core.QMetaMethod))(signal))(std_core.NewQMetaMethodFromPointer(sign))
	} else {
		NewMyTableViewFromPointer(ptr).DisconnectNotifyDefault(std_core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *MyTableView) DisconnectNotifyDefault(sign std_core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.MyTableView871826_DisconnectNotifyDefault(ptr.Pointer(), std_core.PointerFromQMetaMethod(sign))
	}
}

//export callbackMyTableView871826_ObjectNameChanged
func callbackMyTableView871826_ObjectNameChanged(ptr unsafe.Pointer, objectName C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "objectNameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(objectName))
	}

}

func init() {
}
