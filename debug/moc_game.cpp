/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_game_t {
    QByteArrayData data[15];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "game"
QT_MOC_LITERAL(1, 5, 15), // "ShowPauseWindow"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "gameend"
QT_MOC_LITERAL(4, 30, 10), // "time_start"
QT_MOC_LITERAL(5, 41, 5), // "reset"
QT_MOC_LITERAL(6, 47, 7), // "restart"
QT_MOC_LITERAL(7, 55, 9), // "gamePause"
QT_MOC_LITERAL(8, 65, 12), // "gameContinue"
QT_MOC_LITERAL(9, 78, 20), // "on_lawn_area_clicked"
QT_MOC_LITERAL(10, 99, 25), // "on_shop_list_area_clicked"
QT_MOC_LITERAL(11, 125, 22), // "on_shovel_area_clicked"
QT_MOC_LITERAL(12, 148, 11), // "time_action"
QT_MOC_LITERAL(13, 160, 23), // "on_pause_botton_clicked"
QT_MOC_LITERAL(14, 184, 19) // "fight_stage_upgrade"

    },
    "game\0ShowPauseWindow\0\0gameend\0time_start\0"
    "reset\0restart\0gamePause\0gameContinue\0"
    "on_lawn_area_clicked\0on_shop_list_area_clicked\0"
    "on_shovel_area_clicked\0time_action\0"
    "on_pause_botton_clicked\0fight_stage_upgrade"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   83,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowPauseWindow(); break;
        case 1: _t->gameend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->time_start(); break;
        case 3: _t->reset(); break;
        case 4: _t->restart(); break;
        case 5: _t->gamePause(); break;
        case 6: _t->gameContinue(); break;
        case 7: _t->on_lawn_area_clicked(); break;
        case 8: _t->on_shop_list_area_clicked(); break;
        case 9: _t->on_shovel_area_clicked(); break;
        case 10: _t->time_action(); break;
        case 11: _t->on_pause_botton_clicked(); break;
        case 12: _t->fight_stage_upgrade(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&game::ShowPauseWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (game::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&game::gameend)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject game::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_game.data,
    qt_meta_data_game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_game.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void game::ShowPauseWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void game::gameend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
