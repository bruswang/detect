/****************************************************************************
** Meta object code from reading C++ file 'hi_graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hi_graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hi_graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HI_GraphicsView_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HI_GraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HI_GraphicsView_t qt_meta_stringdata_HI_GraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HI_GraphicsView"
QT_MOC_LITERAL(1, 16, 6), // "ZoomIn"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "ZoomOut"
QT_MOC_LITERAL(4, 32, 4), // "Zoom"
QT_MOC_LITERAL(5, 37, 11), // "scaleFactor"
QT_MOC_LITERAL(6, 49, 9), // "Translate"
QT_MOC_LITERAL(7, 59, 5) // "delta"

    },
    "HI_GraphicsView\0ZoomIn\0\0ZoomOut\0Zoom\0"
    "scaleFactor\0Translate\0delta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HI_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::QPointF,    7,

       0        // eod
};

void HI_GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HI_GraphicsView *_t = static_cast<HI_GraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ZoomIn(); break;
        case 1: _t->ZoomOut(); break;
        case 2: _t->Zoom((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->Translate((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject HI_GraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_HI_GraphicsView.data,
      qt_meta_data_HI_GraphicsView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HI_GraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HI_GraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HI_GraphicsView.stringdata0))
        return static_cast<void*>(const_cast< HI_GraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int HI_GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
