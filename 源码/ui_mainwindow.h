/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *Btn_SaveFile;
    QPushButton *Btn_SaveOther;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *Btn_CirNewChosse;
    QPushButton *Btn_HuaYuan;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QWidget *widget_2;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QWidget *widget_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *lineEdit_start_x_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *lineEdit_start_y_2;
    QLabel *label_10;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLineEdit *lineEdit_start_x;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_start_y;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_5;
    QLineEdit *lineEdit_Dpointy;
    QLineEdit *lineEdit_Dpointx;
    QLineEdit *lineEdit_Lenth;
    QLabel *label_16;
    QLabel *label_6;
    QLineEdit *lineEdit_Dpointx_2;
    QLabel *label_17;
    QLineEdit *lineEdit_Dpointy_2;
    QLineEdit *lineEdit_angle;
    QLabel *label_18;
    QSlider *horizontalSlider_Binarization;
    QLineEdit *ldt_Gray;
    QLabel *label_24;
    QLineEdit *ldt_Binarization;
    QLabel *label_29;
    QSlider *horizontalSlider_Gray;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *ldt_LinearStrength;
    QSlider *horizontalSlider_LinearStrength;
    QSlider *horizontalSlider_LinearLength;
    QLineEdit *ldt_LinearIntervalLength;
    QLabel *label_32;
    QLabel *label_33;
    QSlider *horizontalSlider_LinearIntervalLength;
    QLineEdit *ldt_LinearLength;
    QWidget *tab_4;
    QLabel *label_11;
    QLineEdit *lineEdit_size_w;
    QLabel *label_12;
    QLineEdit *lineEdit_CirPoint;
    QWidget *widget_5;
    QLabel *Lbl_CMD;
    QLabel *Lbl_CMD_2;
    QPushButton *pushButton_5;
    QPushButton *Btn_SetCir;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *widget_8;
    QLabel *label_35;
    QLineEdit *ldt__Maxcir;
    QLineEdit *ldt_Mincir;
    QLabel *label_36;
    QLabel *label_38;
    QSlider *horizontalSlider_Maxcir;
    QSlider *horizontalSlider_CirH;
    QSlider *horizontalSlider_CirL;
    QLabel *label_34;
    QLabel *label_37;
    QLineEdit *ldt__MinHCir;
    QSlider *horizontalSlider_MinHCir;
    QLineEdit *ldt_CirL;
    QSlider *horizontalSlider_Mincir;
    QLineEdit *ldt_CirH;
    QTreeView *treeView;
    QPushButton *Btn_Remove_2;
    QPushButton *Btn_DeAll;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_5;
    QPushButton *Btn_Save;
    QTreeView *treeView_2;
    QWidget *widget_7;
    QLabel *label_22;
    QLabel *label_20;
    QLabel *label_23;
    QLabel *label_21;
    QLineEdit *Ldt_CirPoint;
    QLineEdit *Ldt_cirPi;
    QWidget *widget_6;
    QLabel *label_8;
    QLabel *label_19;
    QLineEdit *Ldt_CD;
    QLabel *label;
    QLabel *label_7;
    QLineEdit *Ldt_Jdu;
    QPushButton *Btn_Remove;
    QPushButton *Btn_DeAll_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1800, 1000);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/group (5).png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon1);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 1021, 44));
        widget->setStyleSheet(QStringLiteral("QWidget#widget{border:1px solid #242424;}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton);

        Btn_SaveFile = new QPushButton(widget);
        Btn_SaveFile->setObjectName(QStringLiteral("Btn_SaveFile"));
        Btn_SaveFile->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(Btn_SaveFile);

        Btn_SaveOther = new QPushButton(widget);
        Btn_SaveOther->setObjectName(QStringLiteral("Btn_SaveOther"));
        Btn_SaveOther->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(Btn_SaveOther);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_4);

        Btn_CirNewChosse = new QPushButton(widget);
        Btn_CirNewChosse->setObjectName(QStringLiteral("Btn_CirNewChosse"));
        Btn_CirNewChosse->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(Btn_CirNewChosse);

        Btn_HuaYuan = new QPushButton(widget);
        Btn_HuaYuan->setObjectName(QStringLiteral("Btn_HuaYuan"));
        Btn_HuaYuan->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(Btn_HuaYuan);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton_11);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 43, 1531, 891));
        widget_2->setMinimumSize(QSize(971, 0));
        widget_2->setStyleSheet(QStringLiteral("QWidget#widget_2{border:1px solid rgb(85, 170, 255);}"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(20, 10, 1501, 711));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(widget_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 720, 1511, 161));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 0, 1491, 134));
        widget_3->setStyleSheet(QStringLiteral("QWidget#widget_3{border:1px solid rgb(170, 255, 255);}"));
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(143, 69, 101, 52));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_4);

        lineEdit_start_x_2 = new QLineEdit(layoutWidget);
        lineEdit_start_x_2->setObjectName(QStringLiteral("lineEdit_start_x_2"));
        lineEdit_start_x_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(lineEdit_start_x_2);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(label_13);

        lineEdit_start_y_2 = new QLineEdit(layoutWidget);
        lineEdit_start_y_2->setObjectName(QStringLiteral("lineEdit_start_y_2"));
        lineEdit_start_y_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(lineEdit_start_y_2);


        verticalLayout_4->addLayout(horizontalLayout_12);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(11, 30, 151, 16));
        layoutWidget_2 = new QWidget(widget_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 70, 101, 52));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(label_3);

        lineEdit_start_x = new QLineEdit(layoutWidget_2);
        lineEdit_start_x->setObjectName(QStringLiteral("lineEdit_start_x"));
        lineEdit_start_x->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(lineEdit_start_x);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_start_y = new QLineEdit(layoutWidget_2);
        lineEdit_start_y->setObjectName(QStringLiteral("lineEdit_start_y"));
        lineEdit_start_y->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(lineEdit_start_y);


        verticalLayout_3->addLayout(horizontalLayout_9);

        label_14 = new QLabel(widget_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 30, 81, 16));
        label_15 = new QLabel(widget_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(400, 40, 18, 20));
        label_15->setMaximumSize(QSize(100, 16777215));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 10, 18, 20));
        label_5->setMaximumSize(QSize(100, 16777215));
        lineEdit_Dpointy = new QLineEdit(widget_3);
        lineEdit_Dpointy->setObjectName(QStringLiteral("lineEdit_Dpointy"));
        lineEdit_Dpointy->setGeometry(QRect(424, 40, 73, 20));
        lineEdit_Dpointy->setMaximumSize(QSize(100, 16777215));
        lineEdit_Dpointx = new QLineEdit(widget_3);
        lineEdit_Dpointx->setObjectName(QStringLiteral("lineEdit_Dpointx"));
        lineEdit_Dpointx->setGeometry(QRect(424, 10, 73, 20));
        lineEdit_Dpointx->setMaximumSize(QSize(100, 16777215));
        lineEdit_Lenth = new QLineEdit(widget_3);
        lineEdit_Lenth->setObjectName(QStringLiteral("lineEdit_Lenth"));
        lineEdit_Lenth->setGeometry(QRect(590, 10, 73, 20));
        lineEdit_Lenth->setMaximumSize(QSize(100, 16777215));
        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(510, 12, 61, 20));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 70, 18, 20));
        label_6->setMaximumSize(QSize(100, 16777215));
        lineEdit_Dpointx_2 = new QLineEdit(widget_3);
        lineEdit_Dpointx_2->setObjectName(QStringLiteral("lineEdit_Dpointx_2"));
        lineEdit_Dpointx_2->setGeometry(QRect(424, 70, 73, 20));
        lineEdit_Dpointx_2->setMaximumSize(QSize(100, 16777215));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(400, 100, 18, 20));
        label_17->setMaximumSize(QSize(100, 16777215));
        lineEdit_Dpointy_2 = new QLineEdit(widget_3);
        lineEdit_Dpointy_2->setObjectName(QStringLiteral("lineEdit_Dpointy_2"));
        lineEdit_Dpointy_2->setGeometry(QRect(424, 100, 73, 20));
        lineEdit_Dpointy_2->setMaximumSize(QSize(100, 16777215));
        lineEdit_angle = new QLineEdit(widget_3);
        lineEdit_angle->setObjectName(QStringLiteral("lineEdit_angle"));
        lineEdit_angle->setGeometry(QRect(590, 40, 73, 20));
        lineEdit_angle->setMaximumSize(QSize(100, 16777215));
        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(510, 42, 61, 20));
        horizontalSlider_Binarization = new QSlider(widget_3);
        horizontalSlider_Binarization->setObjectName(QStringLiteral("horizontalSlider_Binarization"));
        horizontalSlider_Binarization->setGeometry(QRect(780, 67, 200, 15));
        horizontalSlider_Binarization->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_Binarization->setMaximum(200);
        horizontalSlider_Binarization->setOrientation(Qt::Horizontal);
        ldt_Gray = new QLineEdit(widget_3);
        ldt_Gray->setObjectName(QStringLiteral("ldt_Gray"));
        ldt_Gray->setGeometry(QRect(990, 20, 40, 30));
        ldt_Gray->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        label_24 = new QLabel(widget_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(1080, 0, 281, 41));
        QFont font;
        font.setPointSize(13);
        label_24->setFont(font);
        ldt_Binarization = new QLineEdit(widget_3);
        ldt_Binarization->setObjectName(QStringLiteral("ldt_Binarization"));
        ldt_Binarization->setGeometry(QRect(990, 100, 40, 30));
        ldt_Binarization->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        label_29 = new QLabel(widget_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(650, 24, 121, 22));
        label_29->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_29->setAlignment(Qt::AlignCenter);
        horizontalSlider_Gray = new QSlider(widget_3);
        horizontalSlider_Gray->setObjectName(QStringLiteral("horizontalSlider_Gray"));
        horizontalSlider_Gray->setGeometry(QRect(780, 27, 200, 15));
        horizontalSlider_Gray->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_Gray->setMaximum(100);
        horizontalSlider_Gray->setOrientation(Qt::Horizontal);
        label_30 = new QLabel(widget_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(654, 67, 121, 22));
        label_30->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_30->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(widget_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(654, 105, 121, 22));
        label_31->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_31->setAlignment(Qt::AlignCenter);
        ldt_LinearStrength = new QLineEdit(widget_3);
        ldt_LinearStrength->setObjectName(QStringLiteral("ldt_LinearStrength"));
        ldt_LinearStrength->setGeometry(QRect(990, 60, 40, 30));
        ldt_LinearStrength->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        horizontalSlider_LinearStrength = new QSlider(widget_3);
        horizontalSlider_LinearStrength->setObjectName(QStringLiteral("horizontalSlider_LinearStrength"));
        horizontalSlider_LinearStrength->setGeometry(QRect(780, 110, 200, 15));
        horizontalSlider_LinearStrength->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_LinearStrength->setOrientation(Qt::Horizontal);
        horizontalSlider_LinearLength = new QSlider(widget_3);
        horizontalSlider_LinearLength->setObjectName(QStringLiteral("horizontalSlider_LinearLength"));
        horizontalSlider_LinearLength->setGeometry(QRect(1216, 60, 200, 15));
        horizontalSlider_LinearLength->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_LinearLength->setOrientation(Qt::Horizontal);
        ldt_LinearIntervalLength = new QLineEdit(widget_3);
        ldt_LinearIntervalLength->setObjectName(QStringLiteral("ldt_LinearIntervalLength"));
        ldt_LinearIntervalLength->setGeometry(QRect(1420, 100, 40, 30));
        ldt_LinearIntervalLength->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        label_32 = new QLabel(widget_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(1070, 57, 121, 22));
        label_32->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_32->setAlignment(Qt::AlignCenter);
        label_33 = new QLabel(widget_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(1070, 107, 141, 22));
        label_33->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_33->setAlignment(Qt::AlignCenter);
        horizontalSlider_LinearIntervalLength = new QSlider(widget_3);
        horizontalSlider_LinearIntervalLength->setObjectName(QStringLiteral("horizontalSlider_LinearIntervalLength"));
        horizontalSlider_LinearIntervalLength->setGeometry(QRect(1216, 110, 200, 15));
        horizontalSlider_LinearIntervalLength->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_LinearIntervalLength->setMaximum(50);
        horizontalSlider_LinearIntervalLength->setOrientation(Qt::Horizontal);
        ldt_LinearLength = new QLineEdit(widget_3);
        ldt_LinearLength->setObjectName(QStringLiteral("ldt_LinearLength"));
        ldt_LinearLength->setGeometry(QRect(1420, 50, 40, 30));
        ldt_LinearLength->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 80, 51, 16));
        lineEdit_size_w = new QLineEdit(tab_4);
        lineEdit_size_w->setObjectName(QStringLiteral("lineEdit_size_w"));
        lineEdit_size_w->setGeometry(QRect(80, 30, 82, 20));
        lineEdit_size_w->setMaximumSize(QSize(100, 16777215));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 30, 36, 20));
        label_12->setMaximumSize(QSize(100, 16777215));
        lineEdit_CirPoint = new QLineEdit(tab_4);
        lineEdit_CirPoint->setObjectName(QStringLiteral("lineEdit_CirPoint"));
        lineEdit_CirPoint->setGeometry(QRect(80, 80, 82, 20));
        lineEdit_CirPoint->setMaximumSize(QSize(100, 16777215));
        tabWidget_2->addTab(tab_4, QString());
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 930, 1321, 30));
        Lbl_CMD = new QLabel(widget_5);
        Lbl_CMD->setObjectName(QStringLiteral("Lbl_CMD"));
        Lbl_CMD->setGeometry(QRect(10, 0, 141, 30));
        Lbl_CMD_2 = new QLabel(widget_5);
        Lbl_CMD_2->setObjectName(QStringLiteral("Lbl_CMD_2"));
        Lbl_CMD_2->setGeometry(QRect(1030, 0, 141, 30));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1110, 10, 76, 30));
        pushButton_5->setMinimumSize(QSize(0, 30));
        Btn_SetCir = new QPushButton(centralWidget);
        Btn_SetCir->setObjectName(QStringLiteral("Btn_SetCir"));
        Btn_SetCir->setGeometry(QRect(1200, 10, 92, 30));
        Btn_SetCir->setMinimumSize(QSize(0, 30));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 45, 21, 16));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1030, 10, 92, 30));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1380, 10, 78, 30));
        pushButton_8->setMinimumSize(QSize(0, 30));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1296, 10, 78, 30));
        pushButton_7->setMinimumSize(QSize(0, 30));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1800, 23));
        menuBar->setLayoutDirection(Qt::LeftToRight);
        menuBar->setInputMethodHints(Qt::ImhNone);
        menuBar->setDefaultUp(false);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setLayoutDirection(Qt::LeftToRight);
        menu->setInputMethodHints(Qt::ImhNone);
        menu->setTearOffEnabled(false);
        menu->setSeparatorsCollapsible(false);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        MainWindow->setMenuBar(menuBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(250, 38));
        dockWidget->setMaximumSize(QSize(524287, 300));
        dockWidget->setContextMenuPolicy(Qt::PreventContextMenu);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(-120, 730, 411, 0));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget_8 = new QWidget(tab_2);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(0, 10, 411, 0));
        label_35 = new QLabel(widget_8);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(20, 87, 121, 22));
        label_35->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_35->setAlignment(Qt::AlignCenter);
        ldt__Maxcir = new QLineEdit(widget_8);
        ldt__Maxcir->setObjectName(QStringLiteral("ldt__Maxcir"));
        ldt__Maxcir->setGeometry(QRect(370, 300, 40, 30));
        ldt__Maxcir->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        ldt_Mincir = new QLineEdit(widget_8);
        ldt_Mincir->setObjectName(QStringLiteral("ldt_Mincir"));
        ldt_Mincir->setGeometry(QRect(370, 220, 40, 30));
        ldt_Mincir->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        label_36 = new QLabel(widget_8);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(20, 157, 121, 22));
        label_36->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_36->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(widget_8);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(10, 307, 141, 22));
        label_38->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_38->setAlignment(Qt::AlignCenter);
        horizontalSlider_Maxcir = new QSlider(widget_8);
        horizontalSlider_Maxcir->setObjectName(QStringLiteral("horizontalSlider_Maxcir"));
        horizontalSlider_Maxcir->setGeometry(QRect(166, 310, 200, 15));
        horizontalSlider_Maxcir->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_Maxcir->setMaximum(1000);
        horizontalSlider_Maxcir->setOrientation(Qt::Horizontal);
        horizontalSlider_CirH = new QSlider(widget_8);
        horizontalSlider_CirH->setObjectName(QStringLiteral("horizontalSlider_CirH"));
        horizontalSlider_CirH->setGeometry(QRect(166, 90, 200, 15));
        horizontalSlider_CirH->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_CirH->setMaximum(255);
        horizontalSlider_CirH->setOrientation(Qt::Horizontal);
        horizontalSlider_CirL = new QSlider(widget_8);
        horizontalSlider_CirL->setObjectName(QStringLiteral("horizontalSlider_CirL"));
        horizontalSlider_CirL->setGeometry(QRect(166, 160, 200, 15));
        horizontalSlider_CirL->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_CirL->setMaximum(255);
        horizontalSlider_CirL->setOrientation(Qt::Horizontal);
        label_34 = new QLabel(widget_8);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(20, 17, 131, 22));
        label_34->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_34->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(widget_8);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(20, 227, 121, 22));
        label_37->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_37->setAlignment(Qt::AlignCenter);
        ldt__MinHCir = new QLineEdit(widget_8);
        ldt__MinHCir->setObjectName(QStringLiteral("ldt__MinHCir"));
        ldt__MinHCir->setGeometry(QRect(370, 10, 40, 30));
        ldt__MinHCir->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        horizontalSlider_MinHCir = new QSlider(widget_8);
        horizontalSlider_MinHCir->setObjectName(QStringLiteral("horizontalSlider_MinHCir"));
        horizontalSlider_MinHCir->setGeometry(QRect(166, 20, 200, 15));
        horizontalSlider_MinHCir->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_MinHCir->setMaximum(100);
        horizontalSlider_MinHCir->setOrientation(Qt::Horizontal);
        ldt_CirL = new QLineEdit(widget_8);
        ldt_CirL->setObjectName(QStringLiteral("ldt_CirL"));
        ldt_CirL->setGeometry(QRect(370, 153, 40, 30));
        ldt_CirL->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        horizontalSlider_Mincir = new QSlider(widget_8);
        horizontalSlider_Mincir->setObjectName(QStringLiteral("horizontalSlider_Mincir"));
        horizontalSlider_Mincir->setGeometry(QRect(166, 230, 200, 15));
        horizontalSlider_Mincir->setStyleSheet(QString::fromUtf8("QSlider{\n"
"    border: 1px solid transparent;\n"
"}\n"
"QSlider::groove{\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::handle {/*\350\256\276\347\275\256\344\270\255\351\227\264\347\232\204\351\202\243\344\270\252\346\273\221\345\212\250\347\232\204\351\224\256*/                           \n"
"    border: 1px solid   rgb(154,187,255);\n"
"    background:rgb(154,187,255);\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    left:5px; right: 5px;\n"
"}\n"
"QSlider::groove:vertical{\n"
"    width: 3px;\n"
"    top: 5px; bottom: 5px;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"    width: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::handle:vertical{\n"
"    height: 6px;\n"
"    margin: -7px; /* height */\n"
"}\n"
"QSlider::add-page{/*\350\277\230\346\262\241\346\234\211\346\273\221\344\270\212\345\216\273\347\232\204\345\234\260\346"
                        "\226\271*/\n"
"    border: 1px solid   rgb(0,84,253);\n"
"    background:  rgb(0,84,253);\n"
"}\n"
"QSlider::sub-page{/*\345\267\262\347\273\217\345\210\222\350\277\207\347\232\204\344\273\216\345\234\260\346\226\271*/                            \n"
"    background:  rgb(0,84,253);\n"
"}"));
        horizontalSlider_Mincir->setMaximum(1000);
        horizontalSlider_Mincir->setOrientation(Qt::Horizontal);
        ldt_CirH = new QLineEdit(widget_8);
        ldt_CirH->setObjectName(QStringLiteral("ldt_CirH"));
        ldt_CirH->setGeometry(QRect(370, 81, 40, 30));
        ldt_CirH->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;\n"
"/* identical to box height */\n"
"\n"
"\n"
"color: #666666;"));
        tabWidget->addTab(tab_2, QString());
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(0, 0, 243, 171));
        Btn_Remove_2 = new QPushButton(dockWidgetContents);
        Btn_Remove_2->setObjectName(QStringLiteral("Btn_Remove_2"));
        Btn_Remove_2->setGeometry(QRect(130, 180, 78, 30));
        Btn_Remove_2->setMinimumSize(QSize(0, 30));
        Btn_DeAll = new QPushButton(dockWidgetContents);
        Btn_DeAll->setObjectName(QStringLiteral("Btn_DeAll"));
        Btn_DeAll->setGeometry(QRect(40, 180, 78, 30));
        Btn_DeAll->setMinimumSize(QSize(0, 30));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(250, 38));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        Btn_Save = new QPushButton(dockWidgetContents_5);
        Btn_Save->setObjectName(QStringLiteral("Btn_Save"));
        Btn_Save->setGeometry(QRect(0, 180, 78, 30));
        Btn_Save->setMinimumSize(QSize(0, 30));
        treeView_2 = new QTreeView(dockWidgetContents_5);
        treeView_2->setObjectName(QStringLiteral("treeView_2"));
        treeView_2->setGeometry(QRect(0, 0, 243, 171));
        widget_7 = new QWidget(dockWidgetContents_5);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(-10, 220, 251, 161));
        widget_7->setStyleSheet(QStringLiteral("QWidget#widget_7{border:1px solid rgb(118, 118, 118);}"));
        label_22 = new QLabel(widget_7);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 40, 101, 21));
        QFont font1;
        font1.setPointSize(11);
        label_22->setFont(font1);
        label_20 = new QLabel(widget_7);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 70, 41, 25));
        QFont font2;
        font2.setPointSize(10);
        label_20->setFont(font2);
        label_23 = new QLabel(widget_7);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 10, 131, 31));
        label_23->setFont(font1);
        label_21 = new QLabel(widget_7);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 110, 41, 25));
        label_21->setFont(font2);
        Ldt_CirPoint = new QLineEdit(widget_7);
        Ldt_CirPoint->setObjectName(QStringLiteral("Ldt_CirPoint"));
        Ldt_CirPoint->setGeometry(QRect(90, 70, 113, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("PingFang SC"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        Ldt_CirPoint->setFont(font3);
        Ldt_CirPoint->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;"));
        Ldt_cirPi = new QLineEdit(widget_7);
        Ldt_cirPi->setObjectName(QStringLiteral("Ldt_cirPi"));
        Ldt_cirPi->setGeometry(QRect(90, 110, 113, 25));
        Ldt_cirPi->setFont(font3);
        Ldt_cirPi->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;"));
        widget_6 = new QWidget(dockWidgetContents_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 380, 250, 161));
        widget_6->setStyleSheet(QStringLiteral("QWidget#widget_6{border:1px solid rgb(118, 118, 118);}"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 80, 41, 25));
        label_8->setFont(font2);
        label_19 = new QLabel(widget_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 120, 41, 25));
        label_19->setFont(font2);
        Ldt_CD = new QLineEdit(widget_6);
        Ldt_CD->setObjectName(QStringLiteral("Ldt_CD"));
        Ldt_CD->setGeometry(QRect(90, 120, 113, 25));
        Ldt_CD->setFont(font3);
        Ldt_CD->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;"));
        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 101, 21));
        label->setFont(font1);
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 131, 31));
        label_7->setFont(font1);
        Ldt_Jdu = new QLineEdit(widget_6);
        Ldt_Jdu->setObjectName(QStringLiteral("Ldt_Jdu"));
        Ldt_Jdu->setGeometry(QRect(90, 80, 113, 25));
        Ldt_Jdu->setFont(font3);
        Ldt_Jdu->setStyleSheet(QLatin1String("background: #FFFFFF;\n"
"border: 1px solid #5498E8;\n"
"box-sizing: border-box;\n"
"border-radius: 4px;\n"
"\n"
"font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 14px;\n"
"line-height: 20px;"));
        Btn_Remove = new QPushButton(dockWidgetContents_5);
        Btn_Remove->setObjectName(QStringLiteral("Btn_Remove"));
        Btn_Remove->setGeometry(QRect(160, 180, 78, 30));
        Btn_Remove->setMinimumSize(QSize(0, 30));
        Btn_DeAll_2 = new QPushButton(dockWidgetContents_5);
        Btn_DeAll_2->setObjectName(QStringLiteral("Btn_DeAll_2"));
        Btn_DeAll_2->setGeometry(QRect(80, 180, 78, 30));
        Btn_DeAll_2->setMinimumSize(QSize(0, 30));
        dockWidget_2->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);
        menu->addAction(action_5);
        menu_5->addAction(action);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\346\226\207\346\241\243", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\235\345\255\230", Q_NULLPTR));
        action_4->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        action_5->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", Q_NULLPTR));
        Btn_SaveFile->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\346\211\223\345\274\200\350\257\273\345\233\276", Q_NULLPTR));
        Btn_SaveOther->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\351\200\211\346\213\251", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\234\206\351\200\211\346\213\251", Q_NULLPTR));
        Btn_CirNewChosse->setText(QApplication::translate("MainWindow", "\346\243\200\346\265\213\345\234\206", Q_NULLPTR));
        Btn_HuaYuan->setText(QApplication::translate("MainWindow", "\344\270\211\347\202\271\345\256\232\345\234\206", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "  \350\257\273\345\207\272\345\275\223\345\211\215\345\233\276", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\345\257\274\350\210\252\346\240\217", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "\345\234\206\345\257\274\350\210\252\346\240\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "x2:", Q_NULLPTR));
        lineEdit_start_x_2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "y2:", Q_NULLPTR));
        lineEdit_start_y_2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\345\233\276\347\211\207\345\256\236\346\227\266\347\202\271\344\275\215:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "x1:", Q_NULLPTR));
        lineEdit_start_x->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "y1:", Q_NULLPTR));
        lineEdit_start_y->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\347\253\257\347\202\271\345\235\220\346\240\207:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "y1:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "x1:", Q_NULLPTR));
        lineEdit_Dpointy->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lineEdit_Dpointx->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lineEdit_Lenth->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\351\225\277\345\272\246:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "x2:", Q_NULLPTR));
        lineEdit_Dpointx_2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "y2:", Q_NULLPTR));
        lineEdit_Dpointy_2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lineEdit_angle->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\350\247\222\345\272\246:", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", " \351\230\210\345\200\2741", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\2742", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\346\243\200\346\265\213\345\274\272\345\272\246", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\346\243\200\346\265\213\347\272\277\351\225\277", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277\346\243\200\346\265\213\351\227\264\351\232\224\347\272\277\351\225\277", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "\347\233\264\347\272\277", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\234\206\347\202\271\344\275\215:", Q_NULLPTR));
        lineEdit_size_w->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\234\206\345\215\212\345\276\204", Q_NULLPTR));
        lineEdit_CirPoint->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        Lbl_CMD->setText(QApplication::translate("MainWindow", "\345\221\275\344\273\244\346\230\276\347\244\272", Q_NULLPTR));
        Lbl_CMD_2->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", Q_NULLPTR));
        Btn_SetCir->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\256\276\344\270\272\345\267\245\344\275\234\345\214\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "0,0", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\205\250\345\261\200\345\235\220\346\240\207\347\263\273", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236\345\216\237\345\233\276", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\351\200\211\344\270\255\345\214\272\345\237\237", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\257\206\345\210\253", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\347\233\264\347\272\277", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\351\253\230\351\230\210\345\200\274", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "\345\234\206\345\277\203\347\264\257\345\212\240\345\231\250\351\230\210\345\200\274", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\345\234\206\345\215\212\345\276\204", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "\345\234\206\345\277\203\344\271\213\351\227\264\346\234\200\345\260\217\350\267\235\347\246\273", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\234\206\345\215\212\345\276\204", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        Btn_Remove_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        Btn_DeAll->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        Btn_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "\345\234\206\345\277\203\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "\345\215\212\345\276\204\357\274\232", Q_NULLPTR));
        Ldt_CirPoint->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\351\225\277\345\272\246\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213", Q_NULLPTR));
        Btn_Remove->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        Btn_DeAll_2->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
