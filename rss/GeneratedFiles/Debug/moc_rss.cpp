/****************************************************************************
** Meta object code from reading C++ file 'rss.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rss.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rss.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rss_t {
    QByteArrayData data[15];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rss_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rss_t qt_meta_stringdata_rss = {
    {
QT_MOC_LITERAL(0, 0, 3), // "rss"
QT_MOC_LITERAL(1, 4, 5), // "onAdd"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 8), // "onRemove"
QT_MOC_LITERAL(4, 20, 9), // "onRefresh"
QT_MOC_LITERAL(5, 30, 15), // "onChannelSelect"
QT_MOC_LITERAL(6, 46, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 63, 4), // "item"
QT_MOC_LITERAL(8, 68, 12), // "onNewChannel"
QT_MOC_LITERAL(9, 81, 9), // "CChannel*"
QT_MOC_LITERAL(10, 91, 7), // "channel"
QT_MOC_LITERAL(11, 99, 16), // "onArticleClicked"
QT_MOC_LITERAL(12, 116, 10), // "closeEvent"
QT_MOC_LITERAL(13, 127, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 140, 5) // "event"

    },
    "rss\0onAdd\0\0onRemove\0onRefresh\0"
    "onChannelSelect\0QListWidgetItem*\0item\0"
    "onNewChannel\0CChannel*\0channel\0"
    "onArticleClicked\0closeEvent\0QCloseEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rss[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
      11,    1,   58,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void rss::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rss *_t = static_cast<rss *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onAdd(); break;
        case 1: _t->onRemove(); break;
        case 2: _t->onRefresh(); break;
        case 3: _t->onChannelSelect((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onNewChannel((*reinterpret_cast< CChannel*(*)>(_a[1]))); break;
        case 5: _t->onArticleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CChannel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject rss::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_rss.data,
      qt_meta_data_rss,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rss::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rss::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rss.stringdata0))
        return static_cast<void*>(const_cast< rss*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int rss::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
