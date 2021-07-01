

#define protected public
#define private public

#include "moc.h"
#include "_cgo_export.h"

#include <QAbstractItemDelegate>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QAction>
#include <QActionEvent>
#include <QByteArray>
#include <QChildEvent>
#include <QCloseEvent>
#include <QContextMenuEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFocusEvent>
#include <QHideEvent>
#include <QIcon>
#include <QInputMethodEvent>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QKeyEvent>
#include <QMetaMethod>
#include <QModelIndex>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QObject>
#include <QPaintDevice>
#include <QPaintEngine>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QRegion>
#include <QResizeEvent>
#include <QShowEvent>
#include <QSize>
#include <QString>
#include <QStyleOptionViewItem>
#include <QTableView>
#include <QTabletEvent>
#include <QTimerEvent>
#include <QVariant>
#include <QVector>
#include <QWheelEvent>
#include <QWidget>

#ifdef QT_QML_LIB
	#include <QQmlEngine>
#endif


class MyTableView871826: public QTableView
{
Q_OBJECT
public:
	MyTableView871826(QWidget *parent = Q_NULLPTR) : QTableView(parent) {qRegisterMetaType<quintptr>("quintptr");MyTableView871826_MyTableView871826_QRegisterMetaType();MyTableView871826_MyTableView871826_QRegisterMetaTypes();callbackMyTableView871826_Constructor(this);};
	 ~MyTableView871826() { callbackMyTableView871826_DestroyMyTableView(this); };
	void columnCountChanged(int oldCount, int newCount) { callbackMyTableView871826_ColumnCountChanged(this, oldCount, newCount); };
	void columnMoved(int column, int oldIndex, int newIndex) { callbackMyTableView871826_ColumnMoved(this, column, oldIndex, newIndex); };
	void columnResized(int column, int oldWidth, int newWidth) { callbackMyTableView871826_ColumnResized(this, column, oldWidth, newWidth); };
	void currentChanged(const QModelIndex & current, const QModelIndex & previous) { callbackMyTableView871826_CurrentChanged(this, const_cast<QModelIndex*>(&current), const_cast<QModelIndex*>(&previous)); };
	void hideColumn(int column) { callbackMyTableView871826_HideColumn(this, column); };
	void hideRow(int row) { callbackMyTableView871826_HideRow(this, row); };
	int horizontalOffset() const { return callbackMyTableView871826_HorizontalOffset(const_cast<void*>(static_cast<const void*>(this))); };
	QModelIndex indexAt(const QPoint & pos) const { return *static_cast<QModelIndex*>(callbackMyTableView871826_IndexAt(const_cast<void*>(static_cast<const void*>(this)), const_cast<QPoint*>(&pos))); };
	bool isIndexHidden(const QModelIndex & index) const { return callbackMyTableView871826_IsIndexHidden(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index)) != 0; };
	QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers) { return *static_cast<QModelIndex*>(callbackMyTableView871826_MoveCursor(this, cursorAction, modifiers)); };
	void paintEvent(QPaintEvent * event) { callbackMyTableView871826_PaintEvent(this, event); };
	void resizeColumnToContents(int column) { callbackMyTableView871826_ResizeColumnToContents(this, column); };
	void resizeColumnsToContents() { callbackMyTableView871826_ResizeColumnsToContents(this); };
	void resizeRowToContents(int row) { callbackMyTableView871826_ResizeRowToContents(this, row); };
	void resizeRowsToContents() { callbackMyTableView871826_ResizeRowsToContents(this); };
	void rowCountChanged(int oldCount, int newCount) { callbackMyTableView871826_RowCountChanged(this, oldCount, newCount); };
	void rowMoved(int row, int oldIndex, int newIndex) { callbackMyTableView871826_RowMoved(this, row, oldIndex, newIndex); };
	void rowResized(int row, int oldHeight, int newHeight) { callbackMyTableView871826_RowResized(this, row, oldHeight, newHeight); };
	void selectColumn(int column) { callbackMyTableView871826_SelectColumn(this, column); };
	void selectRow(int row) { callbackMyTableView871826_SelectRow(this, row); };
	QList<QModelIndex> selectedIndexes() const { return ({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(callbackMyTableView871826_SelectedIndexes(const_cast<void*>(static_cast<const void*>(this)))); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }); };
	void selectionChanged(const QItemSelection & selected, const QItemSelection & deselected) { callbackMyTableView871826_SelectionChanged(this, const_cast<QItemSelection*>(&selected), const_cast<QItemSelection*>(&deselected)); };
	void setModel(QAbstractItemModel * model) { callbackMyTableView871826_SetModel(this, model); };
	void setRootIndex(const QModelIndex & index) { callbackMyTableView871826_SetRootIndex(this, const_cast<QModelIndex*>(&index)); };
	void setSelection(const QRect & rect, QItemSelectionModel::SelectionFlags flags) { callbackMyTableView871826_SetSelection(this, const_cast<QRect*>(&rect), flags); };
	void setSelectionModel(QItemSelectionModel * selectionModel) { callbackMyTableView871826_SetSelectionModel(this, selectionModel); };
	void setShowGrid(bool show) { callbackMyTableView871826_SetShowGrid(this, show); };
	void showColumn(int column) { callbackMyTableView871826_ShowColumn(this, column); };
	void showRow(int row) { callbackMyTableView871826_ShowRow(this, row); };
	int sizeHintForColumn(int column) const { return callbackMyTableView871826_SizeHintForColumn(const_cast<void*>(static_cast<const void*>(this)), column); };
	int sizeHintForRow(int row) const { return callbackMyTableView871826_SizeHintForRow(const_cast<void*>(static_cast<const void*>(this)), row); };
	void sortByColumn(int column, Qt::SortOrder order) { callbackMyTableView871826_SortByColumn(this, column, order); };
	void timerEvent(QTimerEvent * event) { callbackMyTableView871826_TimerEvent(this, event); };
	void updateGeometries() { callbackMyTableView871826_UpdateGeometries(this); };
	int verticalOffset() const { return callbackMyTableView871826_VerticalOffset(const_cast<void*>(static_cast<const void*>(this))); };
	QStyleOptionViewItem viewOptions() const { return *static_cast<QStyleOptionViewItem*>(callbackMyTableView871826_ViewOptions(const_cast<void*>(static_cast<const void*>(this)))); };
	QSize viewportSizeHint() const { return *static_cast<QSize*>(callbackMyTableView871826_ViewportSizeHint(const_cast<void*>(static_cast<const void*>(this)))); };
	void Signal_Activated(const QModelIndex & index) { callbackMyTableView871826_Activated(this, const_cast<QModelIndex*>(&index)); };
	void clearSelection() { callbackMyTableView871826_ClearSelection(this); };
	void Signal_Clicked(const QModelIndex & index) { callbackMyTableView871826_Clicked(this, const_cast<QModelIndex*>(&index)); };
	void closeEditor(QWidget * editor, QAbstractItemDelegate::EndEditHint hint) { callbackMyTableView871826_CloseEditor(this, editor, hint); };
	void commitData(QWidget * editor) { callbackMyTableView871826_CommitData(this, editor); };
	void dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight, const QVector<int> & roles) { callbackMyTableView871826_DataChanged(this, const_cast<QModelIndex*>(&topLeft), const_cast<QModelIndex*>(&bottomRight), ({ QVector<int>* tmpValue037c88 = new QVector<int>(roles); Moc_PackedList { tmpValue037c88, tmpValue037c88->size() }; })); };
	void Signal_DoubleClicked(const QModelIndex & index) { callbackMyTableView871826_DoubleClicked(this, const_cast<QModelIndex*>(&index)); };
	void dragEnterEvent(QDragEnterEvent * event) { callbackMyTableView871826_DragEnterEvent(this, event); };
	void dragLeaveEvent(QDragLeaveEvent * event) { callbackMyTableView871826_DragLeaveEvent(this, event); };
	void dragMoveEvent(QDragMoveEvent * event) { callbackMyTableView871826_DragMoveEvent(this, event); };
	void dropEvent(QDropEvent * event) { callbackMyTableView871826_DropEvent(this, event); };
	void edit(const QModelIndex & index) { callbackMyTableView871826_Edit(this, const_cast<QModelIndex*>(&index)); };
	bool edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event) { return callbackMyTableView871826_Edit2(this, const_cast<QModelIndex*>(&index), trigger, event) != 0; };
	void editorDestroyed(QObject * editor) { callbackMyTableView871826_EditorDestroyed(this, editor); };
	void Signal_Entered(const QModelIndex & index) { callbackMyTableView871826_Entered(this, const_cast<QModelIndex*>(&index)); };
	bool event(QEvent * event) { return callbackMyTableView871826_Event(this, event) != 0; };
	bool eventFilter(QObject * object, QEvent * event) { return callbackMyTableView871826_EventFilter(this, object, event) != 0; };
	void focusInEvent(QFocusEvent * event) { callbackMyTableView871826_FocusInEvent(this, event); };
	bool focusNextPrevChild(bool next) { return callbackMyTableView871826_FocusNextPrevChild(this, next) != 0; };
	void focusOutEvent(QFocusEvent * event) { callbackMyTableView871826_FocusOutEvent(this, event); };
	void Signal_IconSizeChanged(const QSize & size) { callbackMyTableView871826_IconSizeChanged(this, const_cast<QSize*>(&size)); };
	void inputMethodEvent(QInputMethodEvent * event) { callbackMyTableView871826_InputMethodEvent(this, event); };
	QVariant inputMethodQuery(Qt::InputMethodQuery query) const { return *static_cast<QVariant*>(callbackMyTableView871826_InputMethodQuery(const_cast<void*>(static_cast<const void*>(this)), query)); };
	void keyPressEvent(QKeyEvent * event) { callbackMyTableView871826_KeyPressEvent(this, event); };
	void keyboardSearch(const QString & search) { QByteArray* t3559d7 = new QByteArray(search.toUtf8()); Moc_PackedString searchPacked = { const_cast<char*>(t3559d7->prepend("WHITESPACE").constData()+10), t3559d7->size()-10, t3559d7 };callbackMyTableView871826_KeyboardSearch(this, searchPacked); };
	void mouseDoubleClickEvent(QMouseEvent * event) { callbackMyTableView871826_MouseDoubleClickEvent(this, event); };
	void mouseMoveEvent(QMouseEvent * event) { callbackMyTableView871826_MouseMoveEvent(this, event); };
	void mousePressEvent(QMouseEvent * event) { callbackMyTableView871826_MousePressEvent(this, event); };
	void mouseReleaseEvent(QMouseEvent * event) { callbackMyTableView871826_MouseReleaseEvent(this, event); };
	void Signal_Pressed(const QModelIndex & index) { callbackMyTableView871826_Pressed(this, const_cast<QModelIndex*>(&index)); };
	void reset() { callbackMyTableView871826_Reset(this); };
	void resizeEvent(QResizeEvent * event) { callbackMyTableView871826_ResizeEvent(this, event); };
	void rowsAboutToBeRemoved(const QModelIndex & parent, int start, int end) { callbackMyTableView871826_RowsAboutToBeRemoved(this, const_cast<QModelIndex*>(&parent), start, end); };
	void rowsInserted(const QModelIndex & parent, int start, int end) { callbackMyTableView871826_RowsInserted(this, const_cast<QModelIndex*>(&parent), start, end); };
	void scrollTo(const QModelIndex & index, QAbstractItemView::ScrollHint hint) { callbackMyTableView871826_ScrollTo(this, const_cast<QModelIndex*>(&index), hint); };
	void scrollToBottom() { callbackMyTableView871826_ScrollToBottom(this); };
	void scrollToTop() { callbackMyTableView871826_ScrollToTop(this); };
	void selectAll() { callbackMyTableView871826_SelectAll(this); };
	QItemSelectionModel::SelectionFlags selectionCommand(const QModelIndex & index, const QEvent * event) const { return static_cast<QItemSelectionModel::SelectionFlag>(callbackMyTableView871826_SelectionCommand(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index), const_cast<QEvent*>(event))); };
	void setCurrentIndex(const QModelIndex & index) { callbackMyTableView871826_SetCurrentIndex(this, const_cast<QModelIndex*>(&index)); };
	void startDrag(Qt::DropActions supportedActions) { callbackMyTableView871826_StartDrag(this, supportedActions); };
	void update(const QModelIndex & index) { callbackMyTableView871826_Update(this, const_cast<QModelIndex*>(&index)); };
	void Signal_ViewportEntered() { callbackMyTableView871826_ViewportEntered(this); };
	bool viewportEvent(QEvent * event) { return callbackMyTableView871826_ViewportEvent(this, event) != 0; };
	QRect visualRect(const QModelIndex & index) const { return *static_cast<QRect*>(callbackMyTableView871826_VisualRect(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); };
	QRegion visualRegionForSelection(const QItemSelection & selection) const { return *static_cast<QRegion*>(callbackMyTableView871826_VisualRegionForSelection(const_cast<void*>(static_cast<const void*>(this)), const_cast<QItemSelection*>(&selection))); };
	void contextMenuEvent(QContextMenuEvent * e) { callbackMyTableView871826_ContextMenuEvent(this, e); };
	QSize minimumSizeHint() const { return *static_cast<QSize*>(callbackMyTableView871826_MinimumSizeHint(const_cast<void*>(static_cast<const void*>(this)))); };
	void scrollContentsBy(int dx, int dy) { callbackMyTableView871826_ScrollContentsBy(this, dx, dy); };
	void setupViewport(QWidget * viewport) { callbackMyTableView871826_SetupViewport(this, viewport); };
	QSize sizeHint() const { return *static_cast<QSize*>(callbackMyTableView871826_SizeHint(const_cast<void*>(static_cast<const void*>(this)))); };
	void wheelEvent(QWheelEvent * e) { callbackMyTableView871826_WheelEvent(this, e); };
	void changeEvent(QEvent * ev) { callbackMyTableView871826_ChangeEvent(this, ev); };
	void actionEvent(QActionEvent * event) { callbackMyTableView871826_ActionEvent(this, event); };
	bool close() { return callbackMyTableView871826_Close(this) != 0; };
	void closeEvent(QCloseEvent * event) { callbackMyTableView871826_CloseEvent(this, event); };
	void Signal_CustomContextMenuRequested(const QPoint & pos) { callbackMyTableView871826_CustomContextMenuRequested(this, const_cast<QPoint*>(&pos)); };
	void enterEvent(QEvent * event) { callbackMyTableView871826_EnterEvent(this, event); };
	bool hasHeightForWidth() const { return callbackMyTableView871826_HasHeightForWidth(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	int heightForWidth(int w) const { return callbackMyTableView871826_HeightForWidth(const_cast<void*>(static_cast<const void*>(this)), w); };
	void hide() { callbackMyTableView871826_Hide(this); };
	void hideEvent(QHideEvent * event) { callbackMyTableView871826_HideEvent(this, event); };
	void initPainter(QPainter * painter) const { callbackMyTableView871826_InitPainter(const_cast<void*>(static_cast<const void*>(this)), painter); };
	void keyReleaseEvent(QKeyEvent * event) { callbackMyTableView871826_KeyReleaseEvent(this, event); };
	void leaveEvent(QEvent * event) { callbackMyTableView871826_LeaveEvent(this, event); };
	void lower() { callbackMyTableView871826_Lower(this); };
	int metric(QPaintDevice::PaintDeviceMetric m) const { return callbackMyTableView871826_Metric(const_cast<void*>(static_cast<const void*>(this)), m); };
	void moveEvent(QMoveEvent * event) { callbackMyTableView871826_MoveEvent(this, event); };
	bool nativeEvent(const QByteArray & eventType, void * message, long * result) { return callbackMyTableView871826_NativeEvent(this, const_cast<QByteArray*>(&eventType), message, result) != 0; };
	QPaintEngine * paintEngine() const { return static_cast<QPaintEngine*>(callbackMyTableView871826_PaintEngine(const_cast<void*>(static_cast<const void*>(this)))); };
	void raise() { callbackMyTableView871826_Raise(this); };
	void repaint() { callbackMyTableView871826_Repaint(this); };
	void setDisabled(bool disable) { callbackMyTableView871826_SetDisabled(this, disable); };
	void setEnabled(bool vbo) { callbackMyTableView871826_SetEnabled(this, vbo); };
	void setFocus() { callbackMyTableView871826_SetFocus2(this); };
	void setHidden(bool hidden) { callbackMyTableView871826_SetHidden(this, hidden); };
	void setStyleSheet(const QString & styleSheet) { QByteArray* t728ae7 = new QByteArray(styleSheet.toUtf8()); Moc_PackedString styleSheetPacked = { const_cast<char*>(t728ae7->prepend("WHITESPACE").constData()+10), t728ae7->size()-10, t728ae7 };callbackMyTableView871826_SetStyleSheet(this, styleSheetPacked); };
	void setVisible(bool visible) { callbackMyTableView871826_SetVisible(this, visible); };
	void setWindowModified(bool vbo) { callbackMyTableView871826_SetWindowModified(this, vbo); };
	void setWindowTitle(const QString & vqs) { QByteArray* tda39a3 = new QByteArray(vqs.toUtf8()); Moc_PackedString vqsPacked = { const_cast<char*>(tda39a3->prepend("WHITESPACE").constData()+10), tda39a3->size()-10, tda39a3 };callbackMyTableView871826_SetWindowTitle(this, vqsPacked); };
	void show() { callbackMyTableView871826_Show(this); };
	void showEvent(QShowEvent * event) { callbackMyTableView871826_ShowEvent(this, event); };
	void showFullScreen() { callbackMyTableView871826_ShowFullScreen(this); };
	void showMaximized() { callbackMyTableView871826_ShowMaximized(this); };
	void showMinimized() { callbackMyTableView871826_ShowMinimized(this); };
	void showNormal() { callbackMyTableView871826_ShowNormal(this); };
	void tabletEvent(QTabletEvent * event) { callbackMyTableView871826_TabletEvent(this, event); };
	void updateMicroFocus() { callbackMyTableView871826_UpdateMicroFocus(this); };
	void Signal_WindowIconChanged(const QIcon & icon) { callbackMyTableView871826_WindowIconChanged(this, const_cast<QIcon*>(&icon)); };
	void Signal_WindowTitleChanged(const QString & title) { QByteArray* t3c6de1 = new QByteArray(title.toUtf8()); Moc_PackedString titlePacked = { const_cast<char*>(t3c6de1->prepend("WHITESPACE").constData()+10), t3c6de1->size()-10, t3c6de1 };callbackMyTableView871826_WindowTitleChanged(this, titlePacked); };
	void childEvent(QChildEvent * event) { callbackMyTableView871826_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackMyTableView871826_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackMyTableView871826_CustomEvent(this, event); };
	void deleteLater() { callbackMyTableView871826_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackMyTableView871826_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackMyTableView871826_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray* taa2c4f = new QByteArray(objectName.toUtf8()); Moc_PackedString objectNamePacked = { const_cast<char*>(taa2c4f->prepend("WHITESPACE").constData()+10), taa2c4f->size()-10, taa2c4f };callbackMyTableView871826_ObjectNameChanged(this, objectNamePacked); };
signals:
public slots:
private:
};

Q_DECLARE_METATYPE(MyTableView871826*)


void MyTableView871826_MyTableView871826_QRegisterMetaTypes() {
}

int MyTableView871826_MyTableView871826_QRegisterMetaType()
{
	return qRegisterMetaType<MyTableView871826*>();
}

int MyTableView871826_MyTableView871826_QRegisterMetaType2(char* typeName)
{
	return qRegisterMetaType<MyTableView871826*>(const_cast<const char*>(typeName));
}

int MyTableView871826_MyTableView871826_QmlRegisterType()
{
#ifdef QT_QML_LIB
	return qmlRegisterType<MyTableView871826>();
#else
	return 0;
#endif
}

int MyTableView871826_MyTableView871826_QmlRegisterType2(char* uri, int versionMajor, int versionMinor, char* qmlName)
{
#ifdef QT_QML_LIB
	return qmlRegisterType<MyTableView871826>(const_cast<const char*>(uri), versionMajor, versionMinor, const_cast<const char*>(qmlName));
#else
	return 0;
#endif
}

int MyTableView871826_MyTableView871826_QmlRegisterUncreatableType(char* uri, int versionMajor, int versionMinor, char* qmlName, struct Moc_PackedString message)
{
#ifdef QT_QML_LIB
	return qmlRegisterUncreatableType<MyTableView871826>(const_cast<const char*>(uri), versionMajor, versionMinor, const_cast<const char*>(qmlName), QString::fromUtf8(message.data, message.len));
#else
	return 0;
#endif
}

void* MyTableView871826___selectedIndexes_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void MyTableView871826___selectedIndexes_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* MyTableView871826___selectedIndexes_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

int MyTableView871826___dataChanged_roles_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QVector<int>*>(ptr)->at(i); if (i == static_cast<QVector<int>*>(ptr)->size()-1) { static_cast<QVector<int>*>(ptr)->~QVector(); free(ptr); }; tmp; });
}

void MyTableView871826___dataChanged_roles_setList(void* ptr, int i)
{
	static_cast<QVector<int>*>(ptr)->append(i);
}

void* MyTableView871826___dataChanged_roles_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<int>();
}

void* MyTableView871826___scrollBarWidgets_atList(void* ptr, int i)
{
	return ({QWidget * tmp = static_cast<QList<QWidget *>*>(ptr)->at(i); if (i == static_cast<QList<QWidget *>*>(ptr)->size()-1) { static_cast<QList<QWidget *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___scrollBarWidgets_setList(void* ptr, void* i)
{
	static_cast<QList<QWidget *>*>(ptr)->append(static_cast<QWidget*>(i));
}

void* MyTableView871826___scrollBarWidgets_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QWidget *>();
}

void* MyTableView871826___actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* MyTableView871826___actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* MyTableView871826___addActions_actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___addActions_actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* MyTableView871826___addActions_actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* MyTableView871826___insertActions_actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___insertActions_actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* MyTableView871826___insertActions_actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* MyTableView871826___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* MyTableView871826___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

void* MyTableView871826___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void MyTableView871826___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* MyTableView871826___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* MyTableView871826___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* MyTableView871826___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* MyTableView871826___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void MyTableView871826___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* MyTableView871826___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* MyTableView871826_NewMyTableView(void* parent)
{
		return new MyTableView871826(static_cast<QWidget*>(parent));
}

void MyTableView871826_DestroyMyTableView(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->~MyTableView871826();
}

void MyTableView871826_DestroyMyTableViewDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void MyTableView871826_ColumnCountChangedDefault(void* ptr, int oldCount, int newCount)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::columnCountChanged(oldCount, newCount);
}

void MyTableView871826_ColumnMovedDefault(void* ptr, int column, int oldIndex, int newIndex)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::columnMoved(column, oldIndex, newIndex);
}

void MyTableView871826_ColumnResizedDefault(void* ptr, int column, int oldWidth, int newWidth)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::columnResized(column, oldWidth, newWidth);
}

void MyTableView871826_CurrentChangedDefault(void* ptr, void* current, void* previous)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::currentChanged(*static_cast<QModelIndex*>(current), *static_cast<QModelIndex*>(previous));
}

void MyTableView871826_HideColumnDefault(void* ptr, int column)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::hideColumn(column);
}

void MyTableView871826_HideRowDefault(void* ptr, int row)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::hideRow(row);
}

int MyTableView871826_HorizontalOffsetDefault(void* ptr)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::horizontalOffset();
}

void* MyTableView871826_IndexAtDefault(void* ptr, void* pos)
{
	return new QModelIndex(static_cast<MyTableView871826*>(ptr)->QTableView::indexAt(*static_cast<QPoint*>(pos)));
}

char MyTableView871826_IsIndexHiddenDefault(void* ptr, void* index)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::isIndexHidden(*static_cast<QModelIndex*>(index));
}

void* MyTableView871826_MoveCursorDefault(void* ptr, long long cursorAction, long long modifiers)
{
	return new QModelIndex(static_cast<MyTableView871826*>(ptr)->QTableView::moveCursor(static_cast<QAbstractItemView::CursorAction>(cursorAction), static_cast<Qt::KeyboardModifier>(modifiers)));
}

void MyTableView871826_PaintEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::paintEvent(static_cast<QPaintEvent*>(event));
}

void MyTableView871826_ResizeColumnToContentsDefault(void* ptr, int column)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::resizeColumnToContents(column);
}

void MyTableView871826_ResizeColumnsToContentsDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::resizeColumnsToContents();
}

void MyTableView871826_ResizeRowToContentsDefault(void* ptr, int row)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::resizeRowToContents(row);
}

void MyTableView871826_ResizeRowsToContentsDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::resizeRowsToContents();
}

void MyTableView871826_RowCountChangedDefault(void* ptr, int oldCount, int newCount)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::rowCountChanged(oldCount, newCount);
}

void MyTableView871826_RowMovedDefault(void* ptr, int row, int oldIndex, int newIndex)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::rowMoved(row, oldIndex, newIndex);
}

void MyTableView871826_RowResizedDefault(void* ptr, int row, int oldHeight, int newHeight)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::rowResized(row, oldHeight, newHeight);
}

void MyTableView871826_SelectColumnDefault(void* ptr, int column)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::selectColumn(column);
}

void MyTableView871826_SelectRowDefault(void* ptr, int row)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::selectRow(row);
}

struct Moc_PackedList MyTableView871826_SelectedIndexesDefault(void* ptr)
{
	return ({ QList<QModelIndex>* tmpValue847b80 = new QList<QModelIndex>(static_cast<MyTableView871826*>(ptr)->QTableView::selectedIndexes()); Moc_PackedList { tmpValue847b80, tmpValue847b80->size() }; });
}

void MyTableView871826_SelectionChangedDefault(void* ptr, void* selected, void* deselected)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::selectionChanged(*static_cast<QItemSelection*>(selected), *static_cast<QItemSelection*>(deselected));
}

void MyTableView871826_SetModelDefault(void* ptr, void* model)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setModel(static_cast<QAbstractItemModel*>(model));
}

void MyTableView871826_SetRootIndexDefault(void* ptr, void* index)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setRootIndex(*static_cast<QModelIndex*>(index));
}

void MyTableView871826_SetSelectionDefault(void* ptr, void* rect, long long flags)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setSelection(*static_cast<QRect*>(rect), static_cast<QItemSelectionModel::SelectionFlag>(flags));
}

void MyTableView871826_SetSelectionModelDefault(void* ptr, void* selectionModel)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setSelectionModel(static_cast<QItemSelectionModel*>(selectionModel));
}

void MyTableView871826_SetShowGridDefault(void* ptr, char show)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setShowGrid(show != 0);
}

void MyTableView871826_ShowColumnDefault(void* ptr, int column)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showColumn(column);
}

void MyTableView871826_ShowRowDefault(void* ptr, int row)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showRow(row);
}

int MyTableView871826_SizeHintForColumnDefault(void* ptr, int column)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::sizeHintForColumn(column);
}

int MyTableView871826_SizeHintForRowDefault(void* ptr, int row)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::sizeHintForRow(row);
}

void MyTableView871826_SortByColumnDefault(void* ptr, int column, long long order)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::sortByColumn(column, static_cast<Qt::SortOrder>(order));
}

void MyTableView871826_TimerEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::timerEvent(static_cast<QTimerEvent*>(event));
}

void MyTableView871826_UpdateGeometriesDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::updateGeometries();
}

int MyTableView871826_VerticalOffsetDefault(void* ptr)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::verticalOffset();
}

void* MyTableView871826_ViewOptionsDefault(void* ptr)
{
	return new QStyleOptionViewItem(static_cast<MyTableView871826*>(ptr)->QTableView::viewOptions());
}

void* MyTableView871826_ViewportSizeHintDefault(void* ptr)
{
	return ({ QSize tmpValue = static_cast<MyTableView871826*>(ptr)->QTableView::viewportSizeHint(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void MyTableView871826_ClearSelectionDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::clearSelection();
}

void MyTableView871826_CloseEditorDefault(void* ptr, void* editor, long long hint)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::closeEditor(static_cast<QWidget*>(editor), static_cast<QAbstractItemDelegate::EndEditHint>(hint));
}

void MyTableView871826_CommitDataDefault(void* ptr, void* editor)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::commitData(static_cast<QWidget*>(editor));
}

void MyTableView871826_DataChangedDefault(void* ptr, void* topLeft, void* bottomRight, void* roles)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::dataChanged(*static_cast<QModelIndex*>(topLeft), *static_cast<QModelIndex*>(bottomRight), *static_cast<QVector<int>*>(roles));
}

void MyTableView871826_DragEnterEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::dragEnterEvent(static_cast<QDragEnterEvent*>(event));
}

void MyTableView871826_DragLeaveEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::dragLeaveEvent(static_cast<QDragLeaveEvent*>(event));
}

void MyTableView871826_DragMoveEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::dragMoveEvent(static_cast<QDragMoveEvent*>(event));
}

void MyTableView871826_DropEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::dropEvent(static_cast<QDropEvent*>(event));
}

void MyTableView871826_EditDefault(void* ptr, void* index)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::edit(*static_cast<QModelIndex*>(index));
}

char MyTableView871826_Edit2Default(void* ptr, void* index, long long trigger, void* event)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::edit(*static_cast<QModelIndex*>(index), static_cast<QAbstractItemView::EditTrigger>(trigger), static_cast<QEvent*>(event));
}

void MyTableView871826_EditorDestroyedDefault(void* ptr, void* editor)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::editorDestroyed(static_cast<QObject*>(editor));
}

char MyTableView871826_EventDefault(void* ptr, void* event)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::event(static_cast<QEvent*>(event));
}

char MyTableView871826_EventFilterDefault(void* ptr, void* object, void* event)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::eventFilter(static_cast<QObject*>(object), static_cast<QEvent*>(event));
}

void MyTableView871826_FocusInEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::focusInEvent(static_cast<QFocusEvent*>(event));
}

char MyTableView871826_FocusNextPrevChildDefault(void* ptr, char next)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::focusNextPrevChild(next != 0);
}

void MyTableView871826_FocusOutEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::focusOutEvent(static_cast<QFocusEvent*>(event));
}

void MyTableView871826_InputMethodEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::inputMethodEvent(static_cast<QInputMethodEvent*>(event));
}

void* MyTableView871826_InputMethodQueryDefault(void* ptr, long long query)
{
	return new QVariant(static_cast<MyTableView871826*>(ptr)->QTableView::inputMethodQuery(static_cast<Qt::InputMethodQuery>(query)));
}

void MyTableView871826_KeyPressEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::keyPressEvent(static_cast<QKeyEvent*>(event));
}

void MyTableView871826_KeyboardSearchDefault(void* ptr, struct Moc_PackedString search)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::keyboardSearch(QString::fromUtf8(search.data, search.len));
}

void MyTableView871826_MouseDoubleClickEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::mouseDoubleClickEvent(static_cast<QMouseEvent*>(event));
}

void MyTableView871826_MouseMoveEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::mouseMoveEvent(static_cast<QMouseEvent*>(event));
}

void MyTableView871826_MousePressEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::mousePressEvent(static_cast<QMouseEvent*>(event));
}

void MyTableView871826_MouseReleaseEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::mouseReleaseEvent(static_cast<QMouseEvent*>(event));
}

void MyTableView871826_ResetDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::reset();
}

void MyTableView871826_ResizeEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::resizeEvent(static_cast<QResizeEvent*>(event));
}

void MyTableView871826_RowsAboutToBeRemovedDefault(void* ptr, void* parent, int start, int end)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::rowsAboutToBeRemoved(*static_cast<QModelIndex*>(parent), start, end);
}

void MyTableView871826_RowsInsertedDefault(void* ptr, void* parent, int start, int end)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::rowsInserted(*static_cast<QModelIndex*>(parent), start, end);
}

void MyTableView871826_ScrollToDefault(void* ptr, void* index, long long hint)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::scrollTo(*static_cast<QModelIndex*>(index), static_cast<QAbstractItemView::ScrollHint>(hint));
}

void MyTableView871826_ScrollToBottomDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::scrollToBottom();
}

void MyTableView871826_ScrollToTopDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::scrollToTop();
}

void MyTableView871826_SelectAllDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::selectAll();
}

long long MyTableView871826_SelectionCommandDefault(void* ptr, void* index, void* event)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::selectionCommand(*static_cast<QModelIndex*>(index), static_cast<QEvent*>(event));
}

void MyTableView871826_SetCurrentIndexDefault(void* ptr, void* index)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setCurrentIndex(*static_cast<QModelIndex*>(index));
}

void MyTableView871826_StartDragDefault(void* ptr, long long supportedActions)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::startDrag(static_cast<Qt::DropAction>(supportedActions));
}

void MyTableView871826_UpdateDefault(void* ptr, void* index)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::update(*static_cast<QModelIndex*>(index));
}

char MyTableView871826_ViewportEventDefault(void* ptr, void* event)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::viewportEvent(static_cast<QEvent*>(event));
}

void* MyTableView871826_VisualRectDefault(void* ptr, void* index)
{
	return ({ QRect tmpValue = static_cast<MyTableView871826*>(ptr)->QTableView::visualRect(*static_cast<QModelIndex*>(index)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* MyTableView871826_VisualRegionForSelectionDefault(void* ptr, void* selection)
{
	return new QRegion(static_cast<MyTableView871826*>(ptr)->QTableView::visualRegionForSelection(*static_cast<QItemSelection*>(selection)));
}

void MyTableView871826_ContextMenuEventDefault(void* ptr, void* e)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::contextMenuEvent(static_cast<QContextMenuEvent*>(e));
}

void* MyTableView871826_MinimumSizeHintDefault(void* ptr)
{
	return ({ QSize tmpValue = static_cast<MyTableView871826*>(ptr)->QTableView::minimumSizeHint(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void MyTableView871826_ScrollContentsByDefault(void* ptr, int dx, int dy)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::scrollContentsBy(dx, dy);
}

void MyTableView871826_SetupViewportDefault(void* ptr, void* viewport)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setupViewport(static_cast<QWidget*>(viewport));
}

void* MyTableView871826_SizeHintDefault(void* ptr)
{
	return ({ QSize tmpValue = static_cast<MyTableView871826*>(ptr)->QTableView::sizeHint(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void MyTableView871826_WheelEventDefault(void* ptr, void* e)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::wheelEvent(static_cast<QWheelEvent*>(e));
}

void MyTableView871826_ChangeEventDefault(void* ptr, void* ev)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::changeEvent(static_cast<QEvent*>(ev));
}

void MyTableView871826_ActionEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::actionEvent(static_cast<QActionEvent*>(event));
}

char MyTableView871826_CloseDefault(void* ptr)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::close();
}

void MyTableView871826_CloseEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::closeEvent(static_cast<QCloseEvent*>(event));
}

void MyTableView871826_EnterEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::enterEvent(static_cast<QEvent*>(event));
}

char MyTableView871826_HasHeightForWidthDefault(void* ptr)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::hasHeightForWidth();
}

int MyTableView871826_HeightForWidthDefault(void* ptr, int w)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::heightForWidth(w);
}

void MyTableView871826_HideDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::hide();
}

void MyTableView871826_HideEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::hideEvent(static_cast<QHideEvent*>(event));
}

void MyTableView871826_InitPainterDefault(void* ptr, void* painter)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::initPainter(static_cast<QPainter*>(painter));
}

void MyTableView871826_KeyReleaseEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::keyReleaseEvent(static_cast<QKeyEvent*>(event));
}

void MyTableView871826_LeaveEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::leaveEvent(static_cast<QEvent*>(event));
}

void MyTableView871826_LowerDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::lower();
}

int MyTableView871826_MetricDefault(void* ptr, long long m)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::metric(static_cast<QPaintDevice::PaintDeviceMetric>(m));
}

void MyTableView871826_MoveEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::moveEvent(static_cast<QMoveEvent*>(event));
}

char MyTableView871826_NativeEventDefault(void* ptr, void* eventType, void* message, long* result)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::nativeEvent(*static_cast<QByteArray*>(eventType), message, result);
}

void* MyTableView871826_PaintEngineDefault(void* ptr)
{
	return static_cast<MyTableView871826*>(ptr)->QTableView::paintEngine();
}

void MyTableView871826_RaiseDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::raise();
}

void MyTableView871826_RepaintDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::repaint();
}

void MyTableView871826_SetDisabledDefault(void* ptr, char disable)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setDisabled(disable != 0);
}

void MyTableView871826_SetEnabledDefault(void* ptr, char vbo)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setEnabled(vbo != 0);
}

void MyTableView871826_SetFocus2Default(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setFocus();
}

void MyTableView871826_SetHiddenDefault(void* ptr, char hidden)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setHidden(hidden != 0);
}

void MyTableView871826_SetStyleSheetDefault(void* ptr, struct Moc_PackedString styleSheet)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setStyleSheet(QString::fromUtf8(styleSheet.data, styleSheet.len));
}

void MyTableView871826_SetVisibleDefault(void* ptr, char visible)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setVisible(visible != 0);
}

void MyTableView871826_SetWindowModifiedDefault(void* ptr, char vbo)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setWindowModified(vbo != 0);
}

void MyTableView871826_SetWindowTitleDefault(void* ptr, struct Moc_PackedString vqs)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::setWindowTitle(QString::fromUtf8(vqs.data, vqs.len));
}

void MyTableView871826_ShowDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::show();
}

void MyTableView871826_ShowEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showEvent(static_cast<QShowEvent*>(event));
}

void MyTableView871826_ShowFullScreenDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showFullScreen();
}

void MyTableView871826_ShowMaximizedDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showMaximized();
}

void MyTableView871826_ShowMinimizedDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showMinimized();
}

void MyTableView871826_ShowNormalDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::showNormal();
}

void MyTableView871826_TabletEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::tabletEvent(static_cast<QTabletEvent*>(event));
}

void MyTableView871826_UpdateMicroFocusDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::updateMicroFocus();
}

void MyTableView871826_ChildEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::childEvent(static_cast<QChildEvent*>(event));
}

void MyTableView871826_ConnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void MyTableView871826_CustomEventDefault(void* ptr, void* event)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::customEvent(static_cast<QEvent*>(event));
}

void MyTableView871826_DeleteLaterDefault(void* ptr)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::deleteLater();
}

void MyTableView871826_DisconnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<MyTableView871826*>(ptr)->QTableView::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}



#include "moc_moc.h"
