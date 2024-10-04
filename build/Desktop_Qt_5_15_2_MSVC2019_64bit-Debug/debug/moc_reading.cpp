/****************************************************************************
** Meta object code from reading C++ file 'reading.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../reading.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reading_t {
    QByteArrayData data[12];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_reading_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_reading_t qt_meta_stringdata_reading = {
    {
QT_MOC_LITERAL(0, 0, 7), // "reading"
QT_MOC_LITERAL(1, 8, 11), // "checkAnswer"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "on_xyt_clicked"
QT_MOC_LITERAL(4, 36, 21), // "fetchPreviousQuestion"
QT_MOC_LITERAL(5, 58, 17), // "fetchNextQuestion"
QT_MOC_LITERAL(6, 76, 14), // "on_syt_clicked"
QT_MOC_LITERAL(7, 91, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 113, 19), // "on_xuanze_activated"
QT_MOC_LITERAL(9, 133, 5), // "index"
QT_MOC_LITERAL(10, 139, 28), // "jumpToFirstQuestionOfArticle"
QT_MOC_LITERAL(11, 168, 9) // "articleId"

    },
    "reading\0checkAnswer\0\0on_xyt_clicked\0"
    "fetchPreviousQuestion\0fetchNextQuestion\0"
    "on_syt_clicked\0on_pushButton_clicked\0"
    "on_xuanze_activated\0index\0"
    "jumpToFirstQuestionOfArticle\0articleId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reading[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void reading::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reading *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkAnswer(); break;
        case 1: _t->on_xyt_clicked(); break;
        case 2: _t->fetchPreviousQuestion(); break;
        case 3: _t->fetchNextQuestion(); break;
        case 4: _t->on_syt_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_xuanze_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->jumpToFirstQuestionOfArticle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject reading::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_reading.data,
    qt_meta_data_reading,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *reading::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reading::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reading.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int reading::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
