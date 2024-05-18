/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Viwer/myopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    s21::MyOpenGLWidget *widget;
    QPushButton *OpenFileButton;
    QLineEdit *FileNamelineEdit;
    QGroupBox *RotateBox;
    QPushButton *RotateButton;
    QLineEdit *RotatelineEdit;
    QRadioButton *XRotateRB;
    QRadioButton *YRotateRB;
    QRadioButton *ZRotateRB;
    QGroupBox *MoveBox;
    QLineEdit *MovelineEdit;
    QRadioButton *XMoveRB;
    QRadioButton *YMoveRB;
    QRadioButton *ZMoveRB;
    QPushButton *MoveButton;
    QGroupBox *groupBox;
    QPushButton *BackColor;
    QPushButton *LineColor;
    QPushButton *VerticesColor;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ScalePlus;
    QPushButton *ScaleMinus;
    QLineEdit *ScalelineEdit;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *FileNameInfLineEdit;
    QLineEdit *VertCountLineEdit;
    QLineEdit *EdgeCountLineEdit;
    QGroupBox *groupBox_4;
    QPushButton *ProjectionButton;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *SquareVert;
    QPushButton *CircleVert;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *VertPlus;
    QPushButton *VertMinus;
    QPushButton *DisablePoints;
    QGroupBox *groupBox_6;
    QPushButton *DashedLine;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *LineWidthPlus;
    QPushButton *LineWidthMinus;
    QGroupBox *groupBox_8;
    QPushButton *MakeJpeg;
    QPushButton *MakeBmp;
    QPushButton *MakeGifButt;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *PlayButton;
    QPushButton *StopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 840);
        MainWindow->setMinimumSize(QSize(1200, 840));
        MainWindow->setMaximumSize(QSize(1200, 840));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new s21::MyOpenGLWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 800, 800));
        OpenFileButton = new QPushButton(centralwidget);
        OpenFileButton->setObjectName("OpenFileButton");
        OpenFileButton->setGeometry(QRect(950, 40, 100, 32));
        FileNamelineEdit = new QLineEdit(centralwidget);
        FileNamelineEdit->setObjectName("FileNamelineEdit");
        FileNamelineEdit->setEnabled(false);
        FileNamelineEdit->setGeometry(QRect(840, 10, 341, 21));
        RotateBox = new QGroupBox(centralwidget);
        RotateBox->setObjectName("RotateBox");
        RotateBox->setGeometry(QRect(870, 190, 131, 141));
        RotateButton = new QPushButton(RotateBox);
        RotateButton->setObjectName("RotateButton");
        RotateButton->setGeometry(QRect(20, 100, 100, 32));
        RotatelineEdit = new QLineEdit(RotateBox);
        RotatelineEdit->setObjectName("RotatelineEdit");
        RotatelineEdit->setGeometry(QRect(10, 70, 113, 21));
        XRotateRB = new QRadioButton(RotateBox);
        XRotateRB->setObjectName("XRotateRB");
        XRotateRB->setGeometry(QRect(10, 30, 31, 20));
        XRotateRB->setChecked(true);
        YRotateRB = new QRadioButton(RotateBox);
        YRotateRB->setObjectName("YRotateRB");
        YRotateRB->setGeometry(QRect(50, 30, 31, 20));
        ZRotateRB = new QRadioButton(RotateBox);
        ZRotateRB->setObjectName("ZRotateRB");
        ZRotateRB->setGeometry(QRect(90, 30, 31, 20));
        MoveBox = new QGroupBox(centralwidget);
        MoveBox->setObjectName("MoveBox");
        MoveBox->setGeometry(QRect(1010, 190, 131, 141));
        MovelineEdit = new QLineEdit(MoveBox);
        MovelineEdit->setObjectName("MovelineEdit");
        MovelineEdit->setGeometry(QRect(10, 60, 113, 21));
        XMoveRB = new QRadioButton(MoveBox);
        XMoveRB->setObjectName("XMoveRB");
        XMoveRB->setGeometry(QRect(10, 30, 31, 20));
        XMoveRB->setChecked(true);
        YMoveRB = new QRadioButton(MoveBox);
        YMoveRB->setObjectName("YMoveRB");
        YMoveRB->setGeometry(QRect(50, 30, 31, 20));
        ZMoveRB = new QRadioButton(MoveBox);
        ZMoveRB->setObjectName("ZMoveRB");
        ZMoveRB->setGeometry(QRect(90, 30, 31, 20));
        MoveButton = new QPushButton(MoveBox);
        MoveButton->setObjectName("MoveButton");
        MoveButton->setGeometry(QRect(20, 100, 100, 32));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(870, 330, 131, 111));
        BackColor = new QPushButton(groupBox);
        BackColor->setObjectName("BackColor");
        BackColor->setGeometry(QRect(20, 20, 100, 32));
        BackColor->setMaximumSize(QSize(100, 32));
        LineColor = new QPushButton(groupBox);
        LineColor->setObjectName("LineColor");
        LineColor->setGeometry(QRect(20, 50, 100, 32));
        LineColor->setMaximumSize(QSize(100, 32));
        VerticesColor = new QPushButton(groupBox);
        VerticesColor->setObjectName("VerticesColor");
        VerticesColor->setGeometry(QRect(20, 80, 100, 32));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(1010, 330, 131, 141));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 90, 111, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ScalePlus = new QPushButton(layoutWidget);
        ScalePlus->setObjectName("ScalePlus");
        ScalePlus->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(ScalePlus);

        ScaleMinus = new QPushButton(layoutWidget);
        ScaleMinus->setObjectName("ScaleMinus");
        ScaleMinus->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(ScaleMinus);

        ScalelineEdit = new QLineEdit(groupBox_2);
        ScalelineEdit->setObjectName("ScalelineEdit");
        ScalelineEdit->setGeometry(QRect(10, 40, 113, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(870, 69, 271, 121));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 61, 16));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 91, 16));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 81, 16));
        FileNameInfLineEdit = new QLineEdit(groupBox_3);
        FileNameInfLineEdit->setObjectName("FileNameInfLineEdit");
        FileNameInfLineEdit->setEnabled(false);
        FileNameInfLineEdit->setGeometry(QRect(110, 30, 141, 21));
        VertCountLineEdit = new QLineEdit(groupBox_3);
        VertCountLineEdit->setObjectName("VertCountLineEdit");
        VertCountLineEdit->setEnabled(false);
        VertCountLineEdit->setGeometry(QRect(110, 60, 141, 21));
        EdgeCountLineEdit = new QLineEdit(groupBox_3);
        EdgeCountLineEdit->setObjectName("EdgeCountLineEdit");
        EdgeCountLineEdit->setEnabled(false);
        EdgeCountLineEdit->setGeometry(QRect(110, 90, 141, 21));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1010, 480, 131, 71));
        ProjectionButton = new QPushButton(groupBox_4);
        ProjectionButton->setObjectName("ProjectionButton");
        ProjectionButton->setGeometry(QRect(20, 30, 100, 32));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(870, 440, 131, 191));
        layoutWidget1 = new QWidget(groupBox_5);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 30, 121, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        SquareVert = new QPushButton(layoutWidget1);
        SquareVert->setObjectName("SquareVert");

        verticalLayout->addWidget(SquareVert);

        CircleVert = new QPushButton(layoutWidget1);
        CircleVert->setObjectName("CircleVert");

        verticalLayout->addWidget(CircleVert);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        VertPlus = new QPushButton(layoutWidget1);
        VertPlus->setObjectName("VertPlus");
        VertPlus->setMaximumSize(QSize(100, 100));

        horizontalLayout_2->addWidget(VertPlus);

        VertMinus = new QPushButton(layoutWidget1);
        VertMinus->setObjectName("VertMinus");
        VertMinus->setMaximumSize(QSize(100, 100));

        horizontalLayout_2->addWidget(VertMinus);


        verticalLayout_2->addLayout(horizontalLayout_2);

        DisablePoints = new QPushButton(layoutWidget1);
        DisablePoints->setObjectName("DisablePoints");

        verticalLayout_2->addWidget(DisablePoints);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(1010, 560, 131, 71));
        DashedLine = new QPushButton(groupBox_6);
        DashedLine->setObjectName("DashedLine");
        DashedLine->setGeometry(QRect(20, 30, 100, 32));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(1010, 630, 131, 71));
        layoutWidget_2 = new QWidget(groupBox_7);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 30, 111, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        LineWidthPlus = new QPushButton(layoutWidget_2);
        LineWidthPlus->setObjectName("LineWidthPlus");
        LineWidthPlus->setMaximumSize(QSize(100, 100));

        horizontalLayout_3->addWidget(LineWidthPlus);

        LineWidthMinus = new QPushButton(layoutWidget_2);
        LineWidthMinus->setObjectName("LineWidthMinus");
        LineWidthMinus->setMaximumSize(QSize(100, 100));

        horizontalLayout_3->addWidget(LineWidthMinus);

        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(870, 640, 131, 81));
        MakeJpeg = new QPushButton(groupBox_8);
        MakeJpeg->setObjectName("MakeJpeg");
        MakeJpeg->setGeometry(QRect(20, 50, 100, 32));
        MakeJpeg->setMaximumSize(QSize(100, 32));
        MakeBmp = new QPushButton(groupBox_8);
        MakeBmp->setObjectName("MakeBmp");
        MakeBmp->setGeometry(QRect(20, 20, 100, 32));
        MakeBmp->setMaximumSize(QSize(100, 32));
        MakeGifButt = new QPushButton(centralwidget);
        MakeGifButt->setObjectName("MakeGifButt");
        MakeGifButt->setGeometry(QRect(890, 730, 100, 32));
        MakeGifButt->setMaximumSize(QSize(100, 32));
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(1030, 720, 101, 66));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        PlayButton = new QPushButton(layoutWidget2);
        PlayButton->setObjectName("PlayButton");

        verticalLayout_3->addWidget(PlayButton);

        StopButton = new QPushButton(layoutWidget2);
        StopButton->setObjectName("StopButton");

        verticalLayout_3->addWidget(StopButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(PlayButton, &QPushButton::clicked, widget, qOverload<>(&s21::MyOpenGLWidget::changeZ));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenFileButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        RotateBox->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        RotateButton->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        XRotateRB->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        YRotateRB->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        ZRotateRB->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        MoveBox->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        XMoveRB->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        YMoveRB->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        ZMoveRB->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        MoveButton->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Color", nullptr));
        BackColor->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        LineColor->setText(QCoreApplication::translate("MainWindow", "Lines", nullptr));
        VerticesColor->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        ScalePlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        ScaleMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Model Info", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "File name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vertices count", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Edges count", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        ProjectionButton->setText(QCoreApplication::translate("MainWindow", "Switch", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        SquareVert->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        CircleVert->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        VertPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        VertMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        DisablePoints->setText(QCoreApplication::translate("MainWindow", "Enable/Disable", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Dashed line", nullptr));
        DashedLine->setText(QCoreApplication::translate("MainWindow", "Enable/Disable", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Line width", nullptr));
        LineWidthPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        LineWidthMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Screenshots", nullptr));
        MakeJpeg->setText(QCoreApplication::translate("MainWindow", ".jpeg", nullptr));
        MakeBmp->setText(QCoreApplication::translate("MainWindow", ".bmp", nullptr));
        MakeGifButt->setText(QCoreApplication::translate("MainWindow", ".gif", nullptr));
        PlayButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        StopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
