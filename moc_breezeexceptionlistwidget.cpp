/****************************************************************************
** Meta object code from reading C++ file 'breezeexceptionlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../media/Storage/Development/source/breeze/kdecoration/config/breezeexceptionlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breezeexceptionlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Breeze__ExceptionListWidget_t {
    QByteArrayData data[10];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Breeze__ExceptionListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Breeze__ExceptionListWidget_t qt_meta_stringdata_Breeze__ExceptionListWidget = {
    {
QT_MOC_LITERAL(0, 0, 27),
QT_MOC_LITERAL(1, 28, 7),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 13),
QT_MOC_LITERAL(4, 51, 3),
QT_MOC_LITERAL(5, 55, 4),
QT_MOC_LITERAL(6, 60, 6),
QT_MOC_LITERAL(7, 67, 6),
QT_MOC_LITERAL(8, 74, 2),
QT_MOC_LITERAL(9, 77, 4)
    },
    "Breeze::ExceptionListWidget\0changed\0"
    "\0updateButtons\0add\0edit\0remove\0toggle\0"
    "up\0down"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Breeze__ExceptionListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x09 /* Protected */,
       4,    0,   58,    2, 0x09 /* Protected */,
       5,    0,   59,    2, 0x09 /* Protected */,
       6,    0,   60,    2, 0x09 /* Protected */,
       7,    1,   61,    2, 0x09 /* Protected */,
       8,    0,   64,    2, 0x09 /* Protected */,
       9,    0,   65,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Breeze::ExceptionListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExceptionListWidget *_t = static_cast<ExceptionListWidget *>(_o);
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateButtons(); break;
        case 2: _t->add(); break;
        case 3: _t->edit(); break;
        case 4: _t->remove(); break;
        case 5: _t->toggle((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->up(); break;
        case 7: _t->down(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExceptionListWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExceptionListWidget::changed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Breeze::ExceptionListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Breeze__ExceptionListWidget.data,
      qt_meta_data_Breeze__ExceptionListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Breeze::ExceptionListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Breeze::ExceptionListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Breeze__ExceptionListWidget.stringdata))
        return static_cast<void*>(const_cast< ExceptionListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Breeze::ExceptionListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Breeze::ExceptionListWidget::changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE