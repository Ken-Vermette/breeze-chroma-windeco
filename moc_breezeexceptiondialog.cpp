/****************************************************************************
** Meta object code from reading C++ file 'breezeexceptiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../media/Storage/Development/source/breeze/kdecoration/config/breezeexceptiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breezeexceptiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Breeze__ExceptionDialog_t {
    QByteArrayData data[6];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Breeze__ExceptionDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Breeze__ExceptionDialog_t qt_meta_stringdata_Breeze__ExceptionDialog = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 7),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 13),
QT_MOC_LITERAL(4, 47, 22),
QT_MOC_LITERAL(5, 70, 20)
    },
    "Breeze::ExceptionDialog\0changed\0\0"
    "updateChanged\0selectWindowProperties\0"
    "readWindowProperties"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Breeze__ExceptionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x09 /* Protected */,
       4,    0,   38,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Breeze::ExceptionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExceptionDialog *_t = static_cast<ExceptionDialog *>(_o);
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateChanged(); break;
        case 2: _t->selectWindowProperties(); break;
        case 3: _t->readWindowProperties((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExceptionDialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExceptionDialog::changed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Breeze::ExceptionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Breeze__ExceptionDialog.data,
      qt_meta_data_Breeze__ExceptionDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *Breeze::ExceptionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Breeze::ExceptionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Breeze__ExceptionDialog.stringdata))
        return static_cast<void*>(const_cast< ExceptionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Breeze::ExceptionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Breeze::ExceptionDialog::changed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
