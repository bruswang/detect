/****************************************************************************
** Meta object code from reading C++ file 'droptreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../droptreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'droptreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DropTreeWidget_t {
    QByteArrayData data[9];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DropTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DropTreeWidget_t qt_meta_stringdata_DropTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DropTreeWidget"
QT_MOC_LITERAL(1, 15, 17), // "ReloadFile_Camera"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 28), // "onCustomContextMenuRequested"
QT_MOC_LITERAL(4, 63, 2), // "pt"
QT_MOC_LITERAL(5, 66, 12), // "onDeletetask"
QT_MOC_LITERAL(6, 79, 10), // "onCopytask"
QT_MOC_LITERAL(7, 90, 12), // "onDeleteTool"
QT_MOC_LITERAL(8, 103, 10) // "onCopyTool"

    },
    "DropTreeWidget\0ReloadFile_Camera\0\0"
    "onCustomContextMenuRequested\0pt\0"
    "onDeletetask\0onCopytask\0onDeleteTool\0"
    "onCopyTool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DropTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DropTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DropTreeWidget *_t = static_cast<DropTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReloadFile_Camera(); break;
        case 1: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->onDeletetask(); break;
        case 3: _t->onCopytask(); break;
        case 4: _t->onDeleteTool(); break;
        case 5: _t->onCopyTool(); break;
        default: ;
        }
    }
}

const QMetaObject DropTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_DropTreeWidget.data,
      qt_meta_data_DropTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DropTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DropTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DropTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< DropTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int DropTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
