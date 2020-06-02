/****************************************************************************
** Meta object code from reading C++ file 'GUIm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUIm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUIByHand_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIByHand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIByHand_t qt_meta_stringdata_GUIByHand = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GUIByHand"
QT_MOC_LITERAL(1, 10, 10), // "sortedList"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "shuffledList"
QT_MOC_LITERAL(4, 35, 9), // "addAction"
QT_MOC_LITERAL(5, 45, 12), // "updateAction"
QT_MOC_LITERAL(6, 58, 12), // "removeAction"
QT_MOC_LITERAL(7, 71, 14), // "addToWatchlist"
QT_MOC_LITERAL(8, 86, 16), // "refreshWatchlist"
QT_MOC_LITERAL(9, 103, 13) // "gerenateGenre"

    },
    "GUIByHand\0sortedList\0\0shuffledList\0"
    "addAction\0updateAction\0removeAction\0"
    "addToWatchlist\0refreshWatchlist\0"
    "gerenateGenre"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIByHand[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
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

void GUIByHand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUIByHand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sortedList(); break;
        case 1: _t->shuffledList(); break;
        case 2: _t->addAction(); break;
        case 3: _t->updateAction(); break;
        case 4: _t->removeAction(); break;
        case 5: _t->addToWatchlist(); break;
        case 6: _t->refreshWatchlist(); break;
        case 7: _t->gerenateGenre(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GUIByHand::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GUIByHand.data,
    qt_meta_data_GUIByHand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUIByHand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIByHand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUIByHand.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUIByHand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
