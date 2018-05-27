/****************************************************************************
** Meta object code from reading C++ file 'administratorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Lab10QT/administratorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'administratorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdministratorWindow_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdministratorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdministratorWindow_t qt_meta_stringdata_AdministratorWindow = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AdministratorWindow"
QT_MOC_LITERAL(1, 20, 20), // "on_buttonAdd_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "on_buttonDelete_clicked"
QT_MOC_LITERAL(4, 66, 23), // "on_buttonUpdate_clicked"
QT_MOC_LITERAL(5, 90, 16), // "setupDataInTable"
QT_MOC_LITERAL(6, 107, 14), // "onCellSelected"
QT_MOC_LITERAL(7, 122, 5) // "index"

    },
    "AdministratorWindow\0on_buttonAdd_clicked\0"
    "\0on_buttonDelete_clicked\0"
    "on_buttonUpdate_clicked\0setupDataInTable\0"
    "onCellSelected\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdministratorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void AdministratorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdministratorWindow *_t = static_cast<AdministratorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonAdd_clicked(); break;
        case 1: _t->on_buttonDelete_clicked(); break;
        case 2: _t->on_buttonUpdate_clicked(); break;
        case 3: _t->setupDataInTable(); break;
        case 4: _t->onCellSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdministratorWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdministratorWindow.data,
      qt_meta_data_AdministratorWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdministratorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdministratorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdministratorWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdministratorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
