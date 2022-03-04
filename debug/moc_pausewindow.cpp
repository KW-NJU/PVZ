/****************************************************************************
** Meta object code from reading C++ file 'pausewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../pausewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pausewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PauseWindow_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PauseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PauseWindow_t qt_meta_stringdata_PauseWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PauseWindow"
QT_MOC_LITERAL(1, 12, 14), // "return_to_menu"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "game_continue"
QT_MOC_LITERAL(4, 42, 11), // "gameRestart"
QT_MOC_LITERAL(5, 54, 8), // "showself"
QT_MOC_LITERAL(6, 63, 8), // "hideself"
QT_MOC_LITERAL(7, 72, 26), // "on_continue_botton_clicked"
QT_MOC_LITERAL(8, 99, 25), // "on_restart_botton_clicked"
QT_MOC_LITERAL(9, 125, 32) // "on_return_to_menu_botton_clicked"

    },
    "PauseWindow\0return_to_menu\0\0game_continue\0"
    "gameRestart\0showself\0hideself\0"
    "on_continue_botton_clicked\0"
    "on_restart_botton_clicked\0"
    "on_return_to_menu_botton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PauseWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PauseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PauseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_menu(); break;
        case 1: _t->game_continue(); break;
        case 2: _t->gameRestart(); break;
        case 3: _t->showself(); break;
        case 4: _t->hideself(); break;
        case 5: _t->on_continue_botton_clicked(); break;
        case 6: _t->on_restart_botton_clicked(); break;
        case 7: _t->on_return_to_menu_botton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::return_to_menu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::game_continue)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PauseWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PauseWindow::gameRestart)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PauseWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_PauseWindow.data,
    qt_meta_data_PauseWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PauseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PauseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PauseWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PauseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void PauseWindow::return_to_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PauseWindow::game_continue()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PauseWindow::gameRestart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
