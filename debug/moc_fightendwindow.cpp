/****************************************************************************
** Meta object code from reading C++ file 'fightendwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../fightendwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fightendwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FightEndWindow_t {
    QByteArrayData data[7];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FightEndWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FightEndWindow_t qt_meta_stringdata_FightEndWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FightEndWindow"
QT_MOC_LITERAL(1, 15, 14), // "return_to_menu"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "fight_stage_upgrade"
QT_MOC_LITERAL(4, 51, 30), // "on_back_to_menu_botton_clicked"
QT_MOC_LITERAL(5, 82, 15), // "change_showmode"
QT_MOC_LITERAL(6, 98, 2) // "in"

    },
    "FightEndWindow\0return_to_menu\0\0"
    "fight_stage_upgrade\0on_back_to_menu_botton_clicked\0"
    "change_showmode\0in"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FightEndWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void FightEndWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FightEndWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_menu(); break;
        case 1: _t->fight_stage_upgrade(); break;
        case 2: _t->on_back_to_menu_botton_clicked(); break;
        case 3: _t->change_showmode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FightEndWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FightEndWindow::return_to_menu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FightEndWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FightEndWindow::fight_stage_upgrade)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FightEndWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_FightEndWindow.data,
    qt_meta_data_FightEndWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FightEndWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FightEndWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FightEndWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FightEndWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FightEndWindow::return_to_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FightEndWindow::fight_stage_upgrade()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
