/****************************************************************************
** Meta object code from reading C++ file 'mousesize.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mousesize.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mousesize.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MouseSize_t {
    QByteArrayData data[13];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MouseSize_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MouseSize_t qt_meta_stringdata_MouseSize = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MouseSize"
QT_MOC_LITERAL(1, 10, 9), // "sendPoint"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 2), // "x1"
QT_MOC_LITERAL(4, 24, 2), // "y1"
QT_MOC_LITERAL(5, 27, 2), // "x2"
QT_MOC_LITERAL(6, 30, 2), // "y2"
QT_MOC_LITERAL(7, 33, 10), // "CirIsClied"
QT_MOC_LITERAL(8, 44, 5), // "value"
QT_MOC_LITERAL(9, 50, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(10, 81, 4), // "arg1"
QT_MOC_LITERAL(11, 86, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(12, 120, 5) // "index"

    },
    "MouseSize\0sendPoint\0\0x1\0y1\0x2\0y2\0"
    "CirIsClied\0value\0on_comboBox_currentTextChanged\0"
    "arg1\0on_comboBox_2_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MouseSize[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   51,    2, 0x08 /* Private */,
      11,    1,   54,    2, 0x08 /* Private */,
      11,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint, QMetaType::QPoint, QMetaType::QPoint,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void MouseSize::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MouseSize *_t = static_cast<MouseSize *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPoint((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2])),(*reinterpret_cast< QPoint(*)>(_a[3])),(*reinterpret_cast< QPoint(*)>(_a[4]))); break;
        case 1: _t->CirIsClied((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MouseSize::*_t)(QPoint , QPoint , QPoint , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MouseSize::sendPoint)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MouseSize::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MouseSize::CirIsClied)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MouseSize::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MouseSize.data,
      qt_meta_data_MouseSize,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MouseSize::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MouseSize::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MouseSize.stringdata0))
        return static_cast<void*>(const_cast< MouseSize*>(this));
    return QWidget::qt_metacast(_clname);
}

int MouseSize::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MouseSize::sendPoint(QPoint _t1, QPoint _t2, QPoint _t3, QPoint _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MouseSize::CirIsClied(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
