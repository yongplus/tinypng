/****************************************************************************
** Meta object code from reading C++ file 'GridTableHeaderView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GridTableHeaderView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GridTableHeaderView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GridTableHeaderView_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GridTableHeaderView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GridTableHeaderView_t qt_meta_stringdata_GridTableHeaderView = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GridTableHeaderView"
QT_MOC_LITERAL(1, 20, 14), // "sectionPressed"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "from"
QT_MOC_LITERAL(4, 41, 2), // "to"
QT_MOC_LITERAL(5, 44, 16), // "onSectionResized"
QT_MOC_LITERAL(6, 61, 12), // "logicalIndex"
QT_MOC_LITERAL(7, 74, 7), // "oldSize"
QT_MOC_LITERAL(8, 82, 7) // "newSize"

    },
    "GridTableHeaderView\0sectionPressed\0\0"
    "from\0to\0onSectionResized\0logicalIndex\0"
    "oldSize\0newSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GridTableHeaderView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   29,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,

       0        // eod
};

void GridTableHeaderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GridTableHeaderView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sectionPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GridTableHeaderView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridTableHeaderView::sectionPressed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GridTableHeaderView::staticMetaObject = { {
    QMetaObject::SuperData::link<QHeaderView::staticMetaObject>(),
    qt_meta_stringdata_GridTableHeaderView.data,
    qt_meta_data_GridTableHeaderView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GridTableHeaderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GridTableHeaderView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GridTableHeaderView.stringdata0))
        return static_cast<void*>(this);
    return QHeaderView::qt_metacast(_clname);
}

int GridTableHeaderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GridTableHeaderView::sectionPressed(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
