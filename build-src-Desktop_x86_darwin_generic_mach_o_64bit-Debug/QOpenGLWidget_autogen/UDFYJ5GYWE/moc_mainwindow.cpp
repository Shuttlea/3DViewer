/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Viwer/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS = QtMocHelpers::stringData(
    "s21::MainWindow",
    "signal",
    "",
    "StopTimer",
    "Rotate",
    "value",
    "axi",
    "Move",
    "ScalePlus",
    "scale_change",
    "ChangeProjection",
    "SquaredPoint",
    "CircledPoint",
    "ShowedPoints",
    "VertPlus",
    "VertMinus",
    "DashedLine",
    "LineWidthPlus",
    "LineWidthMinus",
    "Info",
    "edges_count",
    "vertex_count",
    "on_OpenFileButton_clicked",
    "on_StopButton_clicked",
    "on_RotateButton_clicked",
    "on_MoveButton_clicked",
    "scalePlusClicked",
    "scaleMinusClicked",
    "ChangeBackgroundColor",
    "ChangeLineColor",
    "SaveSettings",
    "LoadSettings",
    "ChangePointColor",
    "SquarePoints",
    "CirclePoints",
    "ShowPoints",
    "VertPlusClicked",
    "VertMinusClicked",
    "DashLine",
    "LineWidthPlusClicked",
    "LineWidthMinusClicked",
    "MakeScreenShoot",
    "NeedJpeg",
    "NeedBmp",
    "MakeGif",
    "NeedGif",
    "on_ProjectionButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS_t {
    uint offsetsAndSizes[94];
    char stringdata0[16];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[7];
    char stringdata5[6];
    char stringdata6[4];
    char stringdata7[5];
    char stringdata8[10];
    char stringdata9[13];
    char stringdata10[17];
    char stringdata11[13];
    char stringdata12[13];
    char stringdata13[13];
    char stringdata14[9];
    char stringdata15[10];
    char stringdata16[11];
    char stringdata17[14];
    char stringdata18[15];
    char stringdata19[5];
    char stringdata20[12];
    char stringdata21[13];
    char stringdata22[26];
    char stringdata23[22];
    char stringdata24[24];
    char stringdata25[22];
    char stringdata26[17];
    char stringdata27[18];
    char stringdata28[22];
    char stringdata29[16];
    char stringdata30[13];
    char stringdata31[13];
    char stringdata32[17];
    char stringdata33[13];
    char stringdata34[13];
    char stringdata35[11];
    char stringdata36[16];
    char stringdata37[17];
    char stringdata38[9];
    char stringdata39[21];
    char stringdata40[22];
    char stringdata41[16];
    char stringdata42[9];
    char stringdata43[8];
    char stringdata44[8];
    char stringdata45[8];
    char stringdata46[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS_t qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "s21::MainWindow"
        QT_MOC_LITERAL(16, 6),  // "signal"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 9),  // "StopTimer"
        QT_MOC_LITERAL(34, 6),  // "Rotate"
        QT_MOC_LITERAL(41, 5),  // "value"
        QT_MOC_LITERAL(47, 3),  // "axi"
        QT_MOC_LITERAL(51, 4),  // "Move"
        QT_MOC_LITERAL(56, 9),  // "ScalePlus"
        QT_MOC_LITERAL(66, 12),  // "scale_change"
        QT_MOC_LITERAL(79, 16),  // "ChangeProjection"
        QT_MOC_LITERAL(96, 12),  // "SquaredPoint"
        QT_MOC_LITERAL(109, 12),  // "CircledPoint"
        QT_MOC_LITERAL(122, 12),  // "ShowedPoints"
        QT_MOC_LITERAL(135, 8),  // "VertPlus"
        QT_MOC_LITERAL(144, 9),  // "VertMinus"
        QT_MOC_LITERAL(154, 10),  // "DashedLine"
        QT_MOC_LITERAL(165, 13),  // "LineWidthPlus"
        QT_MOC_LITERAL(179, 14),  // "LineWidthMinus"
        QT_MOC_LITERAL(194, 4),  // "Info"
        QT_MOC_LITERAL(199, 11),  // "edges_count"
        QT_MOC_LITERAL(211, 12),  // "vertex_count"
        QT_MOC_LITERAL(224, 25),  // "on_OpenFileButton_clicked"
        QT_MOC_LITERAL(250, 21),  // "on_StopButton_clicked"
        QT_MOC_LITERAL(272, 23),  // "on_RotateButton_clicked"
        QT_MOC_LITERAL(296, 21),  // "on_MoveButton_clicked"
        QT_MOC_LITERAL(318, 16),  // "scalePlusClicked"
        QT_MOC_LITERAL(335, 17),  // "scaleMinusClicked"
        QT_MOC_LITERAL(353, 21),  // "ChangeBackgroundColor"
        QT_MOC_LITERAL(375, 15),  // "ChangeLineColor"
        QT_MOC_LITERAL(391, 12),  // "SaveSettings"
        QT_MOC_LITERAL(404, 12),  // "LoadSettings"
        QT_MOC_LITERAL(417, 16),  // "ChangePointColor"
        QT_MOC_LITERAL(434, 12),  // "SquarePoints"
        QT_MOC_LITERAL(447, 12),  // "CirclePoints"
        QT_MOC_LITERAL(460, 10),  // "ShowPoints"
        QT_MOC_LITERAL(471, 15),  // "VertPlusClicked"
        QT_MOC_LITERAL(487, 16),  // "VertMinusClicked"
        QT_MOC_LITERAL(504, 8),  // "DashLine"
        QT_MOC_LITERAL(513, 20),  // "LineWidthPlusClicked"
        QT_MOC_LITERAL(534, 21),  // "LineWidthMinusClicked"
        QT_MOC_LITERAL(556, 15),  // "MakeScreenShoot"
        QT_MOC_LITERAL(572, 8),  // "NeedJpeg"
        QT_MOC_LITERAL(581, 7),  // "NeedBmp"
        QT_MOC_LITERAL(589, 7),  // "MakeGif"
        QT_MOC_LITERAL(597, 7),  // "NeedGif"
        QT_MOC_LITERAL(605, 27)   // "on_ProjectionButton_clicked"
    },
    "s21::MainWindow",
    "signal",
    "",
    "StopTimer",
    "Rotate",
    "value",
    "axi",
    "Move",
    "ScalePlus",
    "scale_change",
    "ChangeProjection",
    "SquaredPoint",
    "CircledPoint",
    "ShowedPoints",
    "VertPlus",
    "VertMinus",
    "DashedLine",
    "LineWidthPlus",
    "LineWidthMinus",
    "Info",
    "edges_count",
    "vertex_count",
    "on_OpenFileButton_clicked",
    "on_StopButton_clicked",
    "on_RotateButton_clicked",
    "on_MoveButton_clicked",
    "scalePlusClicked",
    "scaleMinusClicked",
    "ChangeBackgroundColor",
    "ChangeLineColor",
    "SaveSettings",
    "LoadSettings",
    "ChangePointColor",
    "SquarePoints",
    "CirclePoints",
    "ShowPoints",
    "VertPlusClicked",
    "VertMinusClicked",
    "DashLine",
    "LineWidthPlusClicked",
    "LineWidthMinusClicked",
    "MakeScreenShoot",
    "NeedJpeg",
    "NeedBmp",
    "MakeGif",
    "NeedGif",
    "on_ProjectionButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSs21SCOPEMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  254,    2, 0x06,    1 /* Public */,
       3,    0,  257,    2, 0x06,    3 /* Public */,
       4,    2,  258,    2, 0x06,    4 /* Public */,
       7,    2,  263,    2, 0x06,    7 /* Public */,
       8,    1,  268,    2, 0x06,   10 /* Public */,
      10,    0,  271,    2, 0x06,   12 /* Public */,
      11,    0,  272,    2, 0x06,   13 /* Public */,
      12,    0,  273,    2, 0x06,   14 /* Public */,
      13,    0,  274,    2, 0x06,   15 /* Public */,
      14,    0,  275,    2, 0x06,   16 /* Public */,
      15,    0,  276,    2, 0x06,   17 /* Public */,
      16,    0,  277,    2, 0x06,   18 /* Public */,
      17,    0,  278,    2, 0x06,   19 /* Public */,
      18,    0,  279,    2, 0x06,   20 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    2,  280,    2, 0x0a,   21 /* Public */,
      22,    0,  285,    2, 0x08,   24 /* Private */,
      23,    0,  286,    2, 0x08,   25 /* Private */,
      24,    0,  287,    2, 0x08,   26 /* Private */,
      25,    0,  288,    2, 0x08,   27 /* Private */,
      26,    0,  289,    2, 0x08,   28 /* Private */,
      27,    0,  290,    2, 0x08,   29 /* Private */,
      28,    0,  291,    2, 0x08,   30 /* Private */,
      29,    0,  292,    2, 0x08,   31 /* Private */,
      30,    0,  293,    2, 0x08,   32 /* Private */,
      31,    0,  294,    2, 0x08,   33 /* Private */,
      32,    0,  295,    2, 0x08,   34 /* Private */,
      33,    0,  296,    2, 0x08,   35 /* Private */,
      34,    0,  297,    2, 0x08,   36 /* Private */,
      35,    0,  298,    2, 0x08,   37 /* Private */,
      36,    0,  299,    2, 0x08,   38 /* Private */,
      37,    0,  300,    2, 0x08,   39 /* Private */,
      38,    0,  301,    2, 0x08,   40 /* Private */,
      39,    0,  302,    2, 0x08,   41 /* Private */,
      40,    0,  303,    2, 0x08,   42 /* Private */,
      41,    0,  304,    2, 0x08,   43 /* Private */,
      42,    0,  305,    2, 0x08,   44 /* Private */,
      43,    0,  306,    2, 0x08,   45 /* Private */,
      44,    0,  307,    2, 0x08,   46 /* Private */,
      45,    0,  308,    2, 0x08,   47 /* Private */,
      46,    0,  309,    2, 0x08,   48 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Char,    5,    6,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSs21SCOPEMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'StopTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Rotate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<char, std::false_type>,
        // method 'Move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'ScalePlus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'ChangeProjection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SquaredPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CircledPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowedPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VertPlus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VertMinus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DashedLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LineWidthPlus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LineWidthMinus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_OpenFileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_StopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RotateButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MoveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scalePlusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scaleMinusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangeBackgroundColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangeLineColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SaveSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LoadSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChangePointColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SquarePoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CirclePoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VertPlusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VertMinusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DashLine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LineWidthPlusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LineWidthMinusClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MakeScreenShoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NeedJpeg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NeedBmp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MakeGif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NeedGif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ProjectionButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->StopTimer(); break;
        case 2: _t->Rotate((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char>>(_a[2]))); break;
        case 3: _t->Move((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->ScalePlus((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 5: _t->ChangeProjection(); break;
        case 6: _t->SquaredPoint(); break;
        case 7: _t->CircledPoint(); break;
        case 8: _t->ShowedPoints(); break;
        case 9: _t->VertPlus(); break;
        case 10: _t->VertMinus(); break;
        case 11: _t->DashedLine(); break;
        case 12: _t->LineWidthPlus(); break;
        case 13: _t->LineWidthMinus(); break;
        case 14: _t->Info((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->on_OpenFileButton_clicked(); break;
        case 16: _t->on_StopButton_clicked(); break;
        case 17: _t->on_RotateButton_clicked(); break;
        case 18: _t->on_MoveButton_clicked(); break;
        case 19: _t->scalePlusClicked(); break;
        case 20: _t->scaleMinusClicked(); break;
        case 21: _t->ChangeBackgroundColor(); break;
        case 22: _t->ChangeLineColor(); break;
        case 23: _t->SaveSettings(); break;
        case 24: _t->LoadSettings(); break;
        case 25: _t->ChangePointColor(); break;
        case 26: _t->SquarePoints(); break;
        case 27: _t->CirclePoints(); break;
        case 28: _t->ShowPoints(); break;
        case 29: _t->VertPlusClicked(); break;
        case 30: _t->VertMinusClicked(); break;
        case 31: _t->DashLine(); break;
        case 32: _t->LineWidthPlusClicked(); break;
        case 33: _t->LineWidthMinusClicked(); break;
        case 34: _t->MakeScreenShoot(); break;
        case 35: _t->NeedJpeg(); break;
        case 36: _t->NeedBmp(); break;
        case 37: _t->MakeGif(); break;
        case 38: _t->NeedGif(); break;
        case 39: _t->on_ProjectionButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::StopTimer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float , char );
            if (_t _q_method = &MainWindow::Rotate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float , int );
            if (_t _q_method = &MainWindow::Move; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float );
            if (_t _q_method = &MainWindow::ScalePlus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::ChangeProjection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::SquaredPoint; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::CircledPoint; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::ShowedPoints; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::VertPlus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::VertMinus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::DashedLine; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::LineWidthPlus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::LineWidthMinus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject *s21::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSs21SCOPEMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int s21::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void s21::MainWindow::signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::MainWindow::StopTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void s21::MainWindow::Rotate(float _t1, char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void s21::MainWindow::Move(float _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void s21::MainWindow::ScalePlus(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void s21::MainWindow::ChangeProjection()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void s21::MainWindow::SquaredPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void s21::MainWindow::CircledPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void s21::MainWindow::ShowedPoints()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void s21::MainWindow::VertPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void s21::MainWindow::VertMinus()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void s21::MainWindow::DashedLine()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void s21::MainWindow::LineWidthPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void s21::MainWindow::LineWidthMinus()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
