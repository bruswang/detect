#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <QStandardItemModel>
#include <algorithm>
#include <QProcess>

#define COUT qDebug()<< __TIME__ << __FUNCTION__ << __LINE__ << " : "
#define SHOW_TEMP 1
QVector<QString> Point_StrVect;
QVector<QString> CirPoint_v;
double CirPressPointx;
double CirPressPointy;
double CirPressPointr;
bool IsBigPicK; // 大图框选4
QString openFileName;     // 打开文件名字
cv::Point AllXyP;    // 全局坐标系0.-y
cv::Point NowXyP;   //当前坐标系 0.0

MainWindow *MainWindow::myClassA = NULL;    // 静态成员变量使用前必须先初始化,否则使用是会提示变量未定义

#include<opencv2/opencv.hpp>
#include<Windows.h>
#include <qtreewidget.h>
#include <opencv2/highgui/highgui_c.h>

// 防止字体乱码
#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

///mingw使用QStringLiteral 会有问题
/// 没有_MSC_VER这个宏 我们就认为他用的是mingw编译器

#ifndef _MSC_VER
#define MINGW
#endif

#if defined(WIN32) && !defined(MINGW)

#else
#define QStringLiteral QString
#endif
int m_x,m_y;
int Px,Py;
QRect rect_Fou;
QRect cirLabelSize;
QImage * img_old;
QString filename;
bool Openistrue;  // 判断是否重新打开图片文件
cv::Mat src;     // 原始图像
cv::Mat zoomImg;                      //定义缩放后的图像
double height1; // rows 行 3行 的高度  // 原始高宽
double width1;  // cols 列 3列 的宽度
double NewHeight;  // 放大缩小后的高宽
double NewWidth;  //

bool isFDtrue;  // 是否放大
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void getAllPointClide(QPoint x1,QPoint y1,QPoint x2,QPoint y2,int model);

int CirNumPir;  // 鼠标跟随的大小截图
int ModelChose; // 选择的模式 直线 圆 三点定圆等 新圆
cv::Rect m_select;  // c裁剪区域
cv::Mat Rol;        // 裁剪图
int CirNumTsize;   // 树状图 圆或者线的条数
int LineNumTsize;
int win_width,win_height;

cv::Mat image_Move,win_image; //申明全局变量
cv::Rect rect_win,rect_img;
void moveImage()//实现移动图像
{
    cv::Mat image_ROI=image_Move(rect_img); // 定义源图像感兴趣区域ROI（需要显示的区域）
    COUT<<rect_img.width<<rect_img.x<<rect_img.y;

    image_ROI.convertTo(src,image_ROI.type()); // image_ROI 复制到 src
    ////也可以直接用 Mat src=image_Move(rect_img); //但是很卡 Why？
    cv::imshow("lena",src);
    COUT<<src.cols;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pressThreeP = 1;
    ui->Btn_SetCir->hide();
    ui->pushButton_5->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_2->hide();
    ui->widget_6->hide();
    ui->widget_7->hide();

    treeisclear = false;
    tree2isclear = false;
    myClassA = this;  // 使用静态函数调用静态对象来发信号
    connect(myClassA,SIGNAL(sendPoint(QString,QString,QString,QString)),this,SLOT(getpoint(QString,QString,QString,QString)));
    connect(myClassA,SIGNAL(LeftIsClied(int)),this,SLOT(getCirIsClied(int)));

    Px = 0;Py = 0;
    pointRect_x = 0; pointRect_y = 0;
    // 新嵌入到widget里面
    isFDtrue = false; // 是否放大
    CirNumPir = 20;   // 圆的半径
    Openistrue = false;
    connect(ui->pushButton, &QPushButton::clicked, [&]() {
        //我们所熟悉的Opencv打开一张图片,并显示
        QString OpenFile, OpenFilePath;
        OpenFile = QFileDialog::getOpenFileName(this,
                                                "please choose an image file",
                                                "",
                                                "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
        if(OpenFile.isEmpty())
        {
            return;
        }
        isFDtrue = false;
        if(Openistrue)
        {
            LineDate.clear();
            CirDate.clear();
            openFileName = OpenFile;
            image_Move=cv::imread(OpenFile.toLocal8Bit().toStdString());
            src= cv::imread(OpenFile.toLocal8Bit().toStdString());

            height1 = src.rows; // 得到初始高宽
            width1 = src.cols;
            win_width = width1;
            win_height = height1;
            rect_img=cv::Rect(0,0,win_width,win_height); //窗口图像对应的矩形区
            cv::Mat src=image_Move(rect_img);

            std::string winName = "lena";
            cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
            cv::imshow(winName, src);
        }
        else
        {
            Openistrue = true;
            openFileName = OpenFile;
            //image_Move=cv::imread(OpenFile.toLocal8Bit().toStdString());
            src= cv::imread(OpenFile.toLocal8Bit().toStdString());

            height1 = src.rows; // 得到初始高宽
            width1 = src.cols;
//            win_width = width1/2;
//            win_height = height1/2;
            //rect_img=cv::Rect(0,0,win_width,win_height); //窗口图像对应的矩形区
            //cv::Mat src=image_Move(rect_img);
            AllXyP.x = 0;
            AllXyP.y = height1;
            COUT<<AllXyP.x<<AllXyP.y;
            std::string winName = "lena";
            cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
            cv::imshow(winName, src);
            //再Qt控件上显示cv::nameWindow窗口
            HWND hwnd = (HWND)cvGetWindowHandle(winName.c_str());
            HWND paraent = GetParent(hwnd);//得到nameWindow窗口的父句柄
            SetParent(hwnd, (HWND)ui->widget_4->winId());//设置ui控件的句柄是父句柄
            ShowWindow(paraent, SW_HIDE);//隐藏掉nameWindow窗口
            cv::resizeWindow(winName, ui->widget_4->width(), ui->widget_4->height());
            cv::setMouseCallback("lena", on_MouseHandle);	//关联鼠标响应函数
        }
        OpenImageheight = height1;
        OpenImagewidth = width1;

        // cv::resizeWindow(winName, cv::Size(ui->widget->width(), ui->widget->height()));
    });


    CirFangDA = false;
    QString curPath = QDir::currentPath();
    COUT<<curPath;
    isCir = false;
    ZoomIsTrue = false;
    writeIsAdd = true;
    isFANGDa = false;
    LineIsshow = false;
    this->setWindowTitle(QStringLiteral("线段识别V1.0"));
    MouseChose = 0;

    //    ui->treeView->hide();
    //    ui->treeView_2->hide();
    model = new QStandardItemModel(ui->treeView);//创建模型
    ui->treeView->setModel(model);//导入模型
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
    model->setItem(0,0,new QStandardItem(tr("直线")));
    //model->setItem(2,0,new QStandardItem(tr("长度")));

    QList<QStandardItem*> list = model->findItems(tr("item two"));
    for(int i = 0;i<list.length();i++)
    {
        qDebug() << tr("list has ").append(list.at(i)->text());//打印该条目的文本
    }

    // 圆
    model_2 = new QStandardItemModel(ui->treeView_2);//创建模型
    ui->treeView_2->setModel(model_2);//导入模型
    model_2->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
    model_2->setItem(0,0,new QStandardItem(tr("圆")));
    //model->setItem(2,0,new QStandardItem(tr("长度")));
    //ui->menuBar->setStyle(Qt::ToolButtonTextUnderIcon);
    //ui->centralWidget->setMouseTracking(true);
    this->setMouseTracking(true);      //设置为不按下鼠标键触发moveEvent

    QRect widget_Size = ui->widget_2->geometry();
    m_x = widget_Size.x();
    m_y = widget_Size.y();
    qDebug()<<m_x<<m_y;

    GrayNum = 50;
    BinarizationNum = 200;
    LinearStrengthNum = 50;
    LinearLengthNum = 50;
    LinearIntervalLengthNum = 10;
    MinHcir= 95;
    CirH = 100;
    CirL = 100;
    Mincir = 50;
    Maxcir = 300;
    ModelChose = 0;
    m_drag = false;
    ReleaseIsEnt = false;
    WorkImageIsOk = false; //工作区域图片完成
    GetWorkImageSize = false; // 得到工作区域大小
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::init // 直线检测
 */
void MainWindow::init()
{
    cv::Mat src;
    if(WorkImageIsOk)
    {
        src = cv::imread(WorkImage.toLocal8Bit().toStdString());
        COUT<<WorkImage;
    }
    else if(ReleaseIsEnt)
    {
        //Rol.copyTo(src);
        src = cv::imread(ReleaseFileName.toLocal8Bit().toStdString());
        COUT;
    }
    else
    {
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        COUT<<openFileName;
    }
    COUT<<ReleaseIsEnt<<WorkImageIsOk;
#if 1
    cv::Mat dst, cdst;
    //    Canny(src, dst, GrayNum, BinarizationNum, 3);
    //    cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
    cv::Canny(src, cdst, 80, 180, 3, false);
    cv::threshold(cdst, cdst, 170, 255, cv::THRESH_BINARY);
    vector<cv::Vec4i> lines,lines1;
    //HoughLinesp（原图， 向量， r的单位长度， theta单位长度， 阈值（大于该阈值认定为直线）， 直线最小长度阈值， 直线相邻两点最大距离）
    cv::HoughLinesP(cdst, lines1, 1, CV_PI / 180, 150, 30, 10);
    cv::HoughLinesP(cdst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );


    cv::Mat img1;
    src.copyTo(img1);
    //连接计算出来的直线
    vector<cv::Vec4i> linesPset;
    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        double point_rect_x = pointRect_x;
        double point_rect_y = pointRect_y;
        //line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3,LINE_AA ); //LINE_AA CV_AA
        //line(img1, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines [i][3]), Scalar(255), 3 );
        //line(img1, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines [i][3]), Scalar(255,255,255),2);  //  暂时不要裁剪 首先就裁剪
        cv::Point Pointx = cv::Point(l[0], l[1]);
        cv::Point Pointy =  cv::Point(l[2], l[3]);
        if(WorkImageIsOk)
        {
            double num_j = 10;
            for(int i = 0; i<Point_StrVect.size(); i++)
            {
                const QString localAt = Point_StrVect.at(i);
                QStringList localSplit = localAt.split(",");
                QString x1 = localSplit.at(0);
                QString y1 = localSplit.at(1);
                QString x2 = localSplit.at(2);
                QString y2 = localSplit.at(3);
                num_j= Pointx.x-x1.toDouble();
                if(num_j<0)
                {
                    num_j = x1.toDouble()-Pointx.x;
                }
            }
            if(num_j<5)
            {
            }
            else
            {
                QString txt = QString::number(Pointx.x)+","+QString::number(Pointx.y)+","+QString::number(Pointy.x)+","+QString::number(Pointy.y);
                Point_StrVect.append(txt);
            }
            //            QString txt = QString::number(Pointx.x)+","+QString::number(Pointx.y)+","+QString::number(Pointy.x)+","+QString::number(Pointy.y);
            //            Point_StrVect.append(txt);
        }
        else if(ReleaseIsEnt)
        {
            point_rect_x += Pointx.x;
            point_rect_y += Pointx.y;
            for(int i =0; i<Point_StrVect.size();i++)
            {
                QStringList localSplit = Point_StrVect.at(i).split(',');
                QString cccc = localSplit.at(0);
                QString cccc2 = localSplit.at(1);
                QString cccc3 = localSplit.at(2);
                QString cccc4 = localSplit.at(3);
                QPoint x_p(cccc.toInt(),cccc2.toInt());
                QPoint y(cccc3.toInt(),cccc4.toInt());
                QRect rect_CCC(x_p,y);
                QPoint x(point_rect_x,point_rect_y);
                if(rect_CCC.contains(x))
                {

                    cv::Vec4i line(cccc.toInt(),cccc2.toInt(),cccc3.toInt(),cccc4.toInt());
                    linesPset.push_back(line);
                    double p_x = cccc.toInt();
                    double p_y = cccc2.toInt();
                    double P_x2 = cccc3.toInt();
                    double P_y2 = cccc4.toInt();
                    double localSqrt = sqrt((P_x2-p_x)*(P_x2-p_x) + (P_y2 - p_y)*(P_y2 - p_y));
                    ui->lineEdit_Lenth->setText(QString::number(localSqrt));
                    if(GetWorkImageSize)  // 如果是工作区域即 放大后的图片 点位需要加上当时切图的xy点
                    {
                        ui->lineEdit_Dpointx->setText(QString::number(Px+cccc.toDouble()));
                        ui->lineEdit_Dpointy->setText(QString::number(Py+cccc2.toDouble()));
                        ui->lineEdit_Dpointx_2->setText(QString::number(Px+ cccc3.toDouble()));
                        ui->lineEdit_Dpointy_2->setText(QString::number(Py + cccc4.toDouble()));
                    }
                    else
                    {
                        ui->lineEdit_Dpointx->setText(cccc);
                        ui->lineEdit_Dpointy->setText(cccc2);
                        ui->lineEdit_Dpointx_2->setText(cccc3);
                        ui->lineEdit_Dpointy_2->setText(cccc4);
                    }
                    //显示每条直线的角度
                    vector <float> lines_arctan;//直线斜率的反正切值
                    lines_arctan = get_lines_arctan(lines);
                    for (unsigned int i = 0; i < lines.size(); i++)
                    {
                        //                        COUT<< lines_arctan[i];
                        //                        COUT<< lines_arctan[i] *180.0/3.1415926;
                        ui->lineEdit_angle->setText(QString::number(lines_arctan[i] *180.0/3.1415926));
                    }
                    setTextCirandLine(1);
                }
            }
        }
        else
        {
            double num_j = 10;
            for(int i = 0; i<Point_StrVect.size(); i++)
            {
                const QString localAt = Point_StrVect.at(i);
                QStringList localSplit = localAt.split(",");
                QString x1 = localSplit.at(0);
                QString y1 = localSplit.at(1);
                QString x2 = localSplit.at(2);
                QString y2 = localSplit.at(3);
                num_j= Pointx.x-x1.toDouble();
                if(num_j<0)
                {
                    num_j = x1.toDouble()-Pointx.x;
                }
            }
            if(num_j<5)   // px的距离小于五 就开始判断为一个线段
            {
            }
            else
            {
                QString txt = QString::number(Pointx.x)+","+QString::number(Pointx.y)+","+QString::number(Pointy.x)+","+QString::number(Pointy.y);
                Point_StrVect.append(txt);
            }
        }
    }
    newcdst_show(linesPset);
    img1.copyTo(Work_LineQCImage);
    //imshow("detected Work_LineQCImage", Work_LineQCImage); //显示直线图片

    //imshow("img1init", img1);   // 原始
#endif
}

void MainWindow::NewInitLine()
{
    cv::Mat src;
    if(ReleaseIsEnt)
    {
        //Rol.copyTo(src);
        src = cv::imread(ReleaseFileName.toLocal8Bit().toStdString());
        //        COUT<<ReleaseFileName;
        COUT;
        cv::imshow("now src ",src);
    }
    COUT<<ReleaseIsEnt<<WorkImageIsOk;
    cv::Mat dst, cdst;
    //    Canny(src, dst, GrayNum, BinarizationNum, 3);
    //    cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化

    cv::Canny(src, cdst, 80, 180, 3, false);  // src是主图
    cv::threshold(cdst, cdst, 170, 255, cv::THRESH_BINARY);
    vector<cv::Vec4i> lines,lines1;
    //HoughLinesp（原图， 向量， r的单位长度， theta单位长度， 阈值（大于该阈值认定为直线）， 直线最小长度阈值， 直线相邻两点最大距离）
    cv::HoughLinesP(cdst, lines1, 1, CV_PI / 180, 150, 30, 10);
    LinearLengthNum = 5;
    cv::HoughLinesP(cdst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );

    cv::Mat img1;
    src.copyTo(img1);
    cv::imshow("detected Work_LineQCImage", img1); //显示直线图片

    //连接计算出来的直线
    vector<cv::Vec4i> linesPset;
    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        double point_rect_x = pointRect_x;
        double point_rect_y = pointRect_y;
        COUT<<point_rect_x<<point_rect_y;
        cv::line( img1, cv::Point(lines[i][0], lines[i][1]),cv::Point(lines[i][2], lines [i][3]), cv::Scalar(0,0,255), 3,cv::LINE_AA ); //LINE_AA CV_AA
        //line(img1, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines [i][3]), Scalar(255), 3 );
        cv::Point Pointx = cv::Point(l[0], l[1]);
        cv::Point Pointy =  cv::Point(l[2], l[3]);

        if(ReleaseIsEnt)
        {
            point_rect_x += Pointx.x;
            point_rect_y += Pointx.y;
            for(int i =0; i<Point_StrVect.size();i++)
            {
                QStringList localSplit = Point_StrVect.at(i).split(',');
                QString cccc = localSplit.at(0);
                QString cccc2 = localSplit.at(1);
                QString cccc3 = localSplit.at(2);
                QString cccc4 = localSplit.at(3);
                QPoint x_p(cccc.toInt(),cccc2.toInt());
                QPoint y(cccc3.toInt(),cccc4.toInt());
                QRect rect_CCC(x_p,y);
                QPoint x(point_rect_x,point_rect_y);

                if(rect_CCC.contains(x))        // 如果这个点在这个矩形内
                {
                    cv::Vec4i line(cccc.toInt(),cccc2.toInt(),cccc3.toInt(),cccc4.toInt());

                    COUT<<Pointx.x<<Pointx.y<<Pointy.x<<Pointy.y;
                    COUT<<point_rect_x<<point_rect_y;
                    COUT<<rect_CCC;

                    linesPset.push_back(line); // 加入容器稍后画图

                    //以下是设置角度长度
                    double p_x = cccc.toInt();
                    double p_y = cccc2.toInt();
                    double P_x2 = cccc3.toInt();
                    double P_y2 = cccc4.toInt();
                    double localSqrt = sqrt((P_x2-p_x)*(P_x2-p_x) + (P_y2 - p_y)*(P_y2 - p_y));
                    ui->lineEdit_Lenth->setText(QString::number(localSqrt));
                    if(GetWorkImageSize)  // 如果是工作区域即 放大后的图片 点位需要加上当时切图的xy点
                    {
                        ui->lineEdit_Dpointx->setText(QString::number(Px+cccc.toDouble()));
                        ui->lineEdit_Dpointy->setText(QString::number(Py+cccc2.toDouble()));
                        ui->lineEdit_Dpointx_2->setText(QString::number(Px+ cccc3.toDouble()));
                        ui->lineEdit_Dpointy_2->setText(QString::number(Py + cccc4.toDouble()));
                    }
                    else
                    {
                        ui->lineEdit_Dpointx->setText(cccc);
                        ui->lineEdit_Dpointy->setText(cccc2);
                        ui->lineEdit_Dpointx_2->setText(cccc3);
                        ui->lineEdit_Dpointy_2->setText(cccc4);
                    }
                    //显示每条直线的角度
                    vector <float> lines_arctan;//直线斜率的反正切值
                    lines_arctan = get_lines_arctan(lines);
                    for (unsigned int i = 0; i < lines.size(); i++)
                    {
                        ui->lineEdit_angle->setText(QString::number(lines_arctan[i] *180.0/3.1415926));
                    }
                    setTextCirandLine(1);  // 设置得到的线和角度
                }
            }
        }
        else
        {
            double num_j = 10;
            for(int i = 0; i<Point_StrVect.size(); i++)
            {
                const QString localAt = Point_StrVect.at(i);
                QStringList localSplit = localAt.split(",");
                QString x1 = localSplit.at(0);
                QString y1 = localSplit.at(1);
                QString x2 = localSplit.at(2);
                QString y2 = localSplit.at(3);
                num_j= Pointx.x-x1.toDouble();
                if(num_j<0)
                {
                    num_j = x1.toDouble()-Pointx.x;
                }
            }
            if(num_j<4)   // px的距离小于五 就开始判断为一个线段
            {
            }
            else
            {
                QString txt = QString::number(Pointx.x)+","+QString::number(Pointx.y)+","+QString::number(Pointy.x)+","+QString::number(Pointy.y);
                COUT<<txt;
                Point_StrVect.append(txt);
            }
        }
    }
    COUT<<Point_StrVect;
    newcdst_show(linesPset);   // 直线选择 点击后显示的线条 单条或多条
    cv::imshow("sourceimg1", img1);   // 原始
}

// 最新 直线检测 平移或者取出roi区域
void MainWindow::NewNewInitLine()
{
    COUT<<ReleaseIsEnt<<WorkImageIsOk;
    cv::Mat src, cdst;
    //    Canny(src, dst, GrayNum, BinarizationNum, 3);
    //    cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
    src = cv::imread(ReleaseFileName.toLocal8Bit().toStdString());
    COUT<<ReleaseFileName;

    cv::Canny(src, cdst, 80, 180, 3, false);  // src是主图
    cv::threshold(cdst, cdst, 170, 255, cv::THRESH_BINARY);
    vector<cv::Vec4i> lines,lines1;
    //HoughLinesp（原图， 向量， r的单位长度， theta单位长度， 阈值（大于该阈值认定为直线）， 直线最小长度阈值， 直线相邻两点最大距离）
    cv::HoughLinesP(cdst, lines1, 1, CV_PI / 180, 150, 30, 10);
    cv::HoughLinesP(cdst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );

    cv::Mat img1;
    src.copyTo(img1);
    //连接计算出来的直线
    vector<cv::Vec4i> linesPset;
    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        double point_rect_x = pointRect_x;
        double point_rect_y = pointRect_y;
        cv::line( img1, cv::Point(lines[i][0], lines[i][1]),cv::Point(lines[i][2], lines [i][3]), cv::Scalar(0,0,255), 3,cv::LINE_AA ); //LINE_AA CV_AA

        //显示每条直线的角度
        vector <float> lines_arctan;//直线斜率的反正切值
        lines_arctan = get_lines_arctan(lines);
        for (unsigned int i = 0; i < lines.size(); i++)
        {
            ui->lineEdit_angle->setText(QString::number(lines_arctan[i] *180.0/3.1415926));
        }
        setTextCirandLine(1);  // 设置得到的线和角度
    }
    cv::imshow("imalineNewnew",img1);
}


// 弃用
void MainWindow::init_cir()
{
    cv::Mat src1, gray_src, src2, dst,myworkdst;
    if(WorkImageIsOk)
    {
        src1 = cv::imread(WorkImage.toLocal8Bit().toStdString());
        COUT<<WorkImage;
    }
    else if(ReleaseIsEnt)
    {
        src1 = cv::imread(ReleaseFileName.toLocal8Bit().toStdString());
        COUT<<ReleaseFileName;
    }
    else
    {
        src1 = cv::imread(openFileName.toLocal8Bit().toStdString());
        COUT<<openFileName;
    }
    //src1 = imread(openFileName.toLocal8Bit().toStdString());
    if (src1.empty())
    {
        cout << "could not find src1" << endl;
        return;
    }
    //namedWindow("input", CV_WINDOW_AUTOSIZE);
    //imshow("input", src1);
    medianBlur(src1,src2,3);
    cvtColor(src2,gray_src,CV_BGR2GRAY);
    vector<cv::Vec3f>pcircles;
    //HoughCircles(gray_src,pcircles,CV_HOUGH_GRADIENT,1,100,200,200,100,1000);

    ui->ldt__MinHCir->setText(QString::number(MinHcir));
    ui->ldt_CirH->setText(QString::number(CirH));
    ui->ldt_CirL->setText(QString::number(CirL));
    ui->ldt_Mincir->setText(QString::number(Mincir));
    ui->ldt__Maxcir->setText(QString::number(Maxcir));

    cv::HoughCircles(gray_src, pcircles, CV_HOUGH_GRADIENT,2, MinHcir, CirH, CirL,Mincir,Maxcir);
    qDebug()<< src1.rows/4;
    src1.copyTo(dst);
    src1.copyTo(myworkdst);

    if(WorkImageIsOk)
    {
        for(size_t i = 0; i < pcircles.size(); i++)
        {
            cv::Vec3f circles = pcircles[i];
            cv::circle(dst,cv::Point(circles[0],circles[1]),circles[2],cv::Scalar(255,255,255),3,cv::LINE_AA);    // 这个是切割后的图
            cv::circle(myworkdst,cv::Point(circles[0],circles[1]),circles[2],cv::Scalar(0,0,255),1,cv::LINE_AA);  // 显示图方便看到是否是圆
            QString txt = QString::number(circles[0])+","+QString::number(circles[1])+","+QString::number(circles[2]);
            if(ReleaseIsEnt)
            {

            }
            else
            {
                CirPoint_v.append(txt);
            }
        }
        setTextCirandLine(2);
        //        model_2->clear();
        //        model_2->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
        //        for(int i = 0 ; i <CirPoint_v.size(); i++)
        //        {
        //            QStandardItem * item = new QStandardItem(("圆:"+QString::number(i)));//创建一个条目对象
        //            model_2->appendRow(item);//通过模型对象添加这个条目
        //            model_2->setItem(0,0,new QStandardItem(tr("圆")));
        //            model_2->item(i)->appendRow(new QStandardItem(tr("圆心")+CirPoint_v.at(i)));
        //            model_2->item(i)->appendRow(new QStandardItem(tr("半径")+CirPoint_v.at(i)));
        //        }
    }
    else if(ReleaseIsEnt)
    {
        COUT<<"ReleaseIsEntReleaseIsEntReleaseIsEnt";
        for(int j=0; j<CirPoint_v.size();j++)
        {
            QStringList localSplit = CirPoint_v.at(j).split(',');
            QString cccc = localSplit.at(0);
            QString cccc2 = localSplit.at(1);
            QString cccc3 = localSplit.at(2);
            bool S=  xiangjiao(cccc.toDouble(),cccc2.toDouble(),cccc3.toDouble(),CirPressPointx,CirPressPointy,CirPressPointr);
            if(S)
            {
                newcdstCir_show(cv::Point(cccc.toDouble(),cccc2.toDouble()),cccc3.toDouble());
                //circle(dst,Point(cccc.toDouble(),cccc2.toDouble()),cccc3.toDouble(),Scalar(0,0,255),1,LINE_AA);
                ui->lineEdit_size_w->setText(cccc3);
                ui->lineEdit_CirPoint->setText(cccc+","+cccc2);
                //                model_2->clear();
                //                model_2->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
                //                model_2->setItem(0,0,new QStandardItem(tr("圆")));
                //                model_2->item(0)->appendRow(new QStandardItem(tr("圆心")+ui->lineEdit_CirPoint->text()));
                //                model_2->item(0)->appendRow(new QStandardItem(tr("半径")+ui->lineEdit_size_w->text()));
                setTextCirandLine(2);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < pcircles.size(); i++)
        {
            cv::Vec3f circles = pcircles[i];
            cv::circle(dst,cv::Point(circles[0],circles[1]),circles[2],cv::Scalar(255,255,255),3,cv::LINE_AA);    // 这个是切割后的图
            cv::circle(myworkdst,cv::Point(circles[0],circles[1]),circles[2],cv::Scalar(0,0,255),1,cv::LINE_AA);  // 显示图方便看到是否是圆
            QString txt = QString::number(circles[0])+","+QString::number(circles[1])+","+QString::number(circles[2]);
            if(ReleaseIsEnt)
            {

            }
            else
            {
                CirPoint_v.append(txt);
            }
        }
        setTextCirandLine(2);
        //        model_2->clear();
        //        model_2->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
        //        for(int i = 0 ; i <CirPoint_v.size(); i++)
        //        {
        //            QStandardItem * item = new QStandardItem(("圆:"+QString::number(i)));//创建一个条目对象
        //            model_2->appendRow(item);//通过模型对象添加这个条目
        //            model_2->setItem(0,0,new QStandardItem(tr("圆")));
        //            model_2->item(i)->appendRow(new QStandardItem(tr("圆心")+CirPoint_v.at(i)));
        //            model_2->item(i)->appendRow(new QStandardItem(tr("半径")+CirPoint_v.at(i)));
        //        }
    }

    imshow("output", myworkdst); // 查看图
    dst.copyTo(Work_LineQCImage);
    // 先把直线全部切除
    if(!ReleaseIsEnt)   // 当按下的时候就不要显示了
    {
        QImage img = cvMat2QImage(Work_LineQCImage);

        QSize IMAGE_SIZE(ui->widget_4->size());
        ui->widget_4->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img).scaled(IMAGE_SIZE)));
        ui->widget_4->setPalette(palette);
    }
}



void MainWindow::on_pushButton_clicked()
{
# if 0
    QString OpenFile, OpenFilePath;
    OpenFile = QFileDialog::getOpenFileName(this,
                                            "please choose an image file",
                                            "",
                                            "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    openFileName = OpenFile;
    OldFilename = openFileName;
    filename = OpenFile;
    openFileName.replace("/","\\");
    img_old = new QImage;
    qDebug()<<"filename"<<filename;
    if (OpenFile != "")
    {
        if (img_old->load(OpenFile))
        {
            //仅仅只是导入之后的图片仍然是原来的大小，这个时候我们需要缩放
            //            ui->temImgView->setScaledContents(true);
            //            ui->temImgView->setPixmap(QPixmap::fromImage(image));//将图片显示在QLabel上
#if 0
            QSize IMAGE_SIZE(ui->widget_4->size());
            ui->widget_4->setAutoFillBackground(true);
            QPalette palette;
            palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(*img_old).scaled(IMAGE_SIZE)));
            ui->widget_4->setPalette(palette);
#else
            //m_imageBox.Init(ui->verticalLayout);
            //connect(&m_imageBox,&HI_ImageBox::ImageClick,this,&MainWindow::ActImageClick);

            //    connect(ui->pushButtonOpenCamera,&QPushButton::pressed,[this]{
            //                QString filename1 = QFileDialog::getOpenFileName();
            //                qDebug()<<filename1<<filename;
            //                if(OpenFile.isEmpty())
            //                    return;
            //                m_imageBox.SetImage(OpenFile);

#endif
            //所有bool都先清空
            ReleaseIsEnt = false;    //按下重现
            WorkImageIsOk = false;  //工作区域重现
            LineIsshow = false; // 判断是否显示拉大后的图片重现
            GetWorkImageSize = false;// 得到工作区域大小
            //init();
            cv::Mat src= cv::imread(openFileName.toLocal8Bit().toStdString());

            oldPicX = src.rows;//高度 4678
            oldPicY = src.cols; // 宽度 3309


            cv::Mat dst, cdst;
            //    Canny(src, dst, GrayNum, BinarizationNum, 3);
            //    cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
            cv::Canny(src, cdst, 80, 180, 3, false);
            //threshold(cdst, cdst, 170, 255, THRESH_BINARY);

            // 矩阵相减 将选中部分变为空白
            cv::Mat srcImg = cv::imread(openFileName.toLocal8Bit().toStdString());
            if (srcImg.empty())
            {
                cout<<"Read Image Failed!"<<endl;
                return;
            }
            //imshow("srcImg", srcImg);
            cv::Mat image1 = srcImg.clone();
            cv::Mat image2 =cv::Mat::zeros(500, 500, CV_8UC3);// cdst.clone();//Mat::zeros(500, 500, CV_8UC3);   //  34 200 126 200
            for(int i=0;i<image2 .rows;i++)     // 高度 i
            { for(int j=0;j<image2 .cols;j++)   // 宽度 j
                { if(i ==200  && j>=34 && j <= 160)
                    {
                        image2 .at<cv::Vec3b>(i,j)[0]=255;
                        image2 .at<cv::Vec3b>(i,j)[1]=255;
                        image2 .at<cv::Vec3b>(i,j)[2]=255;
                    }
                }
            }
        }
    }

#endif

}

cv::Mat MainWindow:: QImage2cvMat(QImage image)
{
    cv::Mat mat;
    qDebug() << image.format();
    switch(image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}

QImage MainWindow:: cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

void MainWindow::on_horizontalSlider_Gray_valueChanged(int value)
{

}

void MainWindow::on_horizontalSlider_Binarization_valueChanged(int value)
{
    //ui->ldt_Gray->setText(QString::number(value));
}

void MainWindow::on_horizontalSlider_LinearStrength_valueChanged(int value)
{

}

void MainWindow::on_horizontalSlider_LinearLength_valueChanged(int value)
{

}

void MainWindow::on_horizontalSlider_LinearIntervalLength_valueChanged(int value)
{

}

// 抬起时的值
void MainWindow::on_horizontalSlider_Gray_sliderReleased()
{
    GrayNum = ui->horizontalSlider_Gray->value();
    ui->ldt_Gray->setText(QString::number(GrayNum));
    init();
}

void MainWindow::on_horizontalSlider_Binarization_sliderReleased()
{
    BinarizationNum = ui->horizontalSlider_Binarization->value();
    ui->ldt_Binarization->setText(QString::number(BinarizationNum));
    init();
}

void MainWindow::on_horizontalSlider_LinearStrength_sliderReleased()
{
    LinearStrengthNum = ui->horizontalSlider_LinearStrength->value();
    ui->ldt_LinearStrength->setText(QString::number(ui->horizontalSlider_LinearStrength->value()));
    init();
}

void MainWindow::on_horizontalSlider_LinearLength_sliderReleased()
{
    LinearLengthNum = ui->horizontalSlider_LinearLength->value();
    ui->ldt_LinearLength->setText(QString::number(LinearLengthNum));
    init();
}

void MainWindow::on_horizontalSlider_LinearIntervalLength_sliderReleased()
{
    LinearIntervalLengthNum = ui->horizontalSlider_LinearIntervalLength->value();
    ui->ldt_LinearIntervalLength->setText(QString::number(ui->horizontalSlider_LinearIntervalLength->value()));
    init();
}

// 鼠标选择自动获取零点 所有点位变化
void MainWindow::on_pushButton_2_clicked()
{
#if 0
    if(MouseChose ==0)
    {
        HeightThisForm = ui->widget_4->height();
        widthThisForm = ui->widget_4->width();
        form = new MouseSize(NULL,HeightThisForm,widthThisForm);
        connect(form,SIGNAL(sendPoint(QPoint,QPoint,QPoint,QPoint)),this,SLOT(getCirPointClide(QPoint,QPoint,QPoint,QPoint)));
        connect(form,SIGNAL(CirIsClied(int)),this,SLOT(getCirIsClied(int)));

        //ui->verticalLayout->addWidget(form); // 不添加form
        COUT<<HeightThisForm<<widthThisForm;
        ui->Lbl_CMD->setText("获取鼠标");
        MouseChose =1;
    }
    else
    {
        form->deleteLater();
        MouseChose = 0;
    }
    //form->show();
    //    isCir = true;

#endif

    //当选点按下后就选择为当前坐标系
}


/***************************************
 * 函数名：initSerial
 * 槽函数
 * 功能://鼠标按下时执行的事件处理函数
****************************************/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
}

QPoint pint;
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent * event){
}
void MainWindow::on_horizontalSlider_MinHCir_sliderReleased()
{
    MinHcir = ui->horizontalSlider_MinHCir->value();
    ui->ldt__MinHCir->setText(QString::number(MinHcir));
    init_cir();
}

void MainWindow::on_horizontalSlider_CirH_sliderReleased()
{
    CirH = ui->horizontalSlider_CirH->value();
    ui->ldt_CirH->setText(QString::number(CirH));
    init_cir();
}

void MainWindow::on_horizontalSlider_CirL_sliderReleased()
{
    CirL = ui->horizontalSlider_CirL->value();
    ui->ldt_CirL->setText(QString::number(CirL));
    init_cir();
}

void MainWindow::on_horizontalSlider_Mincir_sliderReleased()
{
    Mincir = ui->horizontalSlider_Mincir->value();
    ui->ldt_Mincir->setText(QString::number(Mincir));
    init_cir();
}

void MainWindow::on_horizontalSlider_Maxcir_sliderReleased()
{
    Maxcir = ui->horizontalSlider_Maxcir->value();
    ui->ldt__Maxcir->setText(QString::number(Maxcir));
    init_cir();
}

// 实时得到圆的四个点位
void MainWindow::getCirPointClide(QPoint x1, QPoint y1, QPoint x2, QPoint y2)
{
    QString x1_text =QString::number(x1.x())+"," +QString::number(x1.y());
    QString y1_text =QString::number(y1.x())+"," +QString::number(y1.y());
    QString x2_text =QString::number(x2.x())+"," +QString::number(x2.y());
    QString y2_text =QString::number(y2.x())+"," +QString::number(y2.y());
    ui->lineEdit_start_x->setText(x1_text);
    ui->lineEdit_start_y->setText(y1_text);
    ui->lineEdit_start_x_2->setText(x2_text);
    ui->lineEdit_start_y_2->setText(y2_text);
}

/**
 * @brief MainWindow::getCirIsClied 得到识别的id 按下的点击事件
 * @param value
 */
void MainWindow::getCirIsClied(int value)
{
    qDebug()<<"left is enter" << value;
    //    LinearStrengthNum = value;
    //    LinearLengthNum = value;
    ui->ldt_Gray->setText(QString::number(GrayNum));
    ui->ldt_Binarization->setText(QString::number(BinarizationNum));
    ui->ldt_LinearStrength->setText(QString::number(LinearStrengthNum));
    ui->ldt_LinearLength->setText(QString::number(LinearLengthNum));
    ui->ldt_LinearIntervalLength->setText(QString::number(LinearIntervalLengthNum));

    QString text = ui->lineEdit_start_x->text();
    QString text_y = ui->lineEdit_start_y_2->text();
    QStringList y_list = text_y.split(",");
    QStringList localSplit = text.split(",");  // 截图上左边顶点的 xy
    QString text_t = localSplit.at(0);
    QString text_t2 = localSplit.at(1);
    CirXp = text_t; // 当前圆的点击后x的值
    CirYp = text_t2 ;   // 当前圆 点击后y的点

    QString text_y1 = y_list.at(0);
    QString text_y2 = y_list.at(1);
    double y1 = text_y1.toDouble();
    double y2 = text_y2.toDouble();
    Px =text_t.toDouble() ;
    Py =text_t2.toDouble() ;
    // Px Py是当前点击实时的位置

    QImage image;
    image.load(openFileName);  // 打开文件名
    oldPicY = image.width();  // 2000
    oldPicX = image.height(); // 1000
    COUT<<height1<<width1<<NewHeight<<NewWidth;  // src的高宽
    if(NewHeight ==0 || NewWidth ==0)
    {
        NewWidth = height1;
        NewHeight = width1;
    }
    double beishux = double(width1) / double(NewHeight);  //   原始宽度 / 当前宽度  得到倍数
    double beishuy = double(height1) / double(NewWidth);  // 高度
    //  px py 为左上角截图的顶点
    Px = beishux * Px;      //
    Py = beishuy * Py;
    y1 = y1*beishux;
    y2 = y2*beishuy;
    COUT<<Px<<Py;
    COUT<<y1<<y1;
    int NowPx,NowPy;
    NowPx = (y1-Px);  //落点
    NowPy = (y2-Py);
    pointRect_x = Px;//(m_x*beishux);
    pointRect_y = Py;//(m_y*beishuy);
    //COUT<<Px<<Py<<NowPx<<NowPy<<pointRect_x<<pointRect_y;
    QImage newImage = image.copy(Px,Py, NowPx, NowPy);

    CirPressPointx= pointRect_x+NowPx/2;   // 圆的xy
    CirPressPointy= pointRect_y+NowPy/2;
    CirPressPointr= NowPx/2;

    COUT<<CirPressPointx<< CirPressPointy<<CirPressPointr;
    QString newImageName = QDir::currentPath() + "/2Image.png";

    //m_select = cv::Rect(Px,Py, NowPx, NowPy);
    //Rol = src(m_select);
    //cv::imshow("Cai_Jian",Rol);

    newImage.save(newImageName);

    QString PicImageName = QDir::currentPath() + "/tmpcircap.png";
    newImage.save(PicImageName);
    FangDapicX = Px;  // 记录下放大图片的大小
    FangDapicY = Py;
    ReleaseFileName = newImageName;
    ReleaseIsEnt = true;

    if(isFANGDa)
    {
        QString newImageName = QApplication::applicationDirPath() + "/3Image.png";
        newImage.save(newImageName);
        WorkImage = newImageName;
        QImage img_old;
        COUT<<"WorkImage"<<WorkImage;
        FangDafilenameNew = WorkImage;
        openFileName = FangDafilenameNew;
        if (img_old.load(FangDafilenameNew))
        {
            isFANGDa = false;
            QSize IMAGE_SIZE(ui->widget_4->size());
            ui->widget_4->setAutoFillBackground(true);
            QPalette palette;
            palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img_old).scaled(IMAGE_SIZE)));
            ui->widget_4->setPalette(palette);
            WorkImageIsOk = true;
            GetWorkImageSize = true;
        }
    }
    else
    {
        if(ModelChose == 1)
        {
            init();
            //NewInitLine();
            // NewNewInitLine();
        }
        else if(ModelChose ==2 )
        {
            //init_cir();  抛弃原始的  // 新方法调用python的exe
            ui->pushButton_5->click();

        }
        else if (ModelChose == 3)
        {
            if(pressThreeP==1)
            {
                if(CirFangDA = false)
                {
                    //                    CirX = CirXp.toInt()+ cirx.toInt()+FangDapicX; // x点
                    //                    CirY = CirYp.toInt()+ ciry.toInt() + FangDapicY;  // y点 相对于图片
                    pointpress1.setX(threePointPlanCir(1, 2, 3).x  +CirXp.toInt());
                    pointpress1.setY(threePointPlanCir(1, 2, 3).y +CirYp.toInt());
                    COUT<<"xiao";
                }
                else
                {
                    pointpress1.setX(threePointPlanCir(1, 2, 3).x  +FangDapicX);
                    pointpress1.setY(threePointPlanCir(1, 2, 3).y  + FangDapicY);
                    COUT<<"fangda";
                }
                pressThreeP = 2;

                COUT<<pointpress1;
            }
            else if(pressThreeP==2)
            {
                if(CirFangDA = false)
                {
                    //                    CirX = CirXp.toInt()+ cirx.toInt()+FangDapicX; // x点
                    //                    CirY = CirYp.toInt()+ ciry.toInt() + FangDapicY;  // y点 相对于图片
                    pointpress2.setX(threePointPlanCir(1, 2, 3).x  +CirXp.toInt());
                    pointpress2.setY(threePointPlanCir(1, 2, 3).y +CirYp.toInt());
                    COUT<<"xiao";
                }
                else
                {
                    pointpress2.setX(threePointPlanCir(1, 2, 3).x  +FangDapicX);
                    pointpress2.setY(threePointPlanCir(1, 2, 3).y  + FangDapicY);
                    COUT<<"fangda";
                }
                pressThreeP =3;
                COUT<<pointpress2;
            }
            else if(pressThreeP ==3)
            {
                if(CirFangDA = false)
                {
                    //                    CirX = CirXp.toInt()+ cirx.toInt()+FangDapicX; // x点
                    //                    CirY = CirYp.toInt()+ ciry.toInt() + FangDapicY;  // y点 相对于图片
                    pointpress3.setX(threePointPlanCir(1, 2, 3).x  +CirXp.toInt());
                    pointpress3.setY(threePointPlanCir(1, 2, 3).y +CirYp.toInt());
                    COUT<<"xiao";
                }
                else
                {
                    pointpress3.setX(threePointPlanCir(1, 2, 3).x  +FangDapicX);
                    pointpress3.setY(threePointPlanCir(1, 2, 3).y  + FangDapicY);
                    COUT<<"fangda";
                }

                pressThreeP = 1;
                double radios = 0;
                QPointF localTcircle = tcircle(pointpress3,pointpress2,pointpress1,radios);
                COUT<<localTcircle.x()<<localTcircle.y()<<&radios<<radios;
                COUT<<pointpress3;
                HuaYuan(localTcircle,radios);
            }
        }
        else if (ModelChose == 4)
        {
            NewCirChosee(PicImageName,QPoint(CirPressPointx,CirPressPointy),CirPressPointr,Px,Py, NowPx, NowPy);
        }
        else if(ModelChose ==5)
        {
            QPoint(CirPressPointx,CirPressPointy); // 当前点位
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(WorkImageIsOk)
    {
        ReleaseIsEnt = true;
    }
    else {
        ReleaseIsEnt = false;
    }
    COUT<<ReleaseIsEnt<<WorkImageIsOk;
    init();
    //NewInitLine();  // 直线检测
    WorkImageIsOk = false;
    ModelChose = 1;
    ui->Lbl_CMD->setText("直线选择-L");
}

void MainWindow::on_pushButton_4_clicked()
{
#if 1
    if(WorkImageIsOk)
    {
        ReleaseIsEnt = true;
    }
    else {
        ReleaseIsEnt = false;
    }
    //init_cir();
    WorkImageIsOk = false;

    ModelChose = 2;
    ui->Lbl_CMD->setText("圆选择-C");
#endif

}

/**
 * @brief MainWindow::on_pushButton_5_clicked 调用第三方算圆
 */
void MainWindow::on_pushButton_5_clicked()
{
    QProcess process;   //pyexe/dist/reTest.exe
    QString Filename = QApplication::applicationDirPath() +"/thrptget.exe";  // QString curPath = QDir::currentPath(); 当前路径
    COUT<<Filename;
    QFile file(Filename);
    if(file.exists())
    {
        COUT<<Filename;
        process.start(Filename,QStringList());
        process.waitForFinished();
        COUT<<"Call over";
    }
    else
    {
        return;
    }
    // 读文件
    QStringList CirXYC; //得到圆的xy 和圆中心
    QList<QString> localReadFile = readFile(QDir::currentPath() + "/tmpcircap.txt");
    COUT<<localReadFile.at(0)<<localReadFile.at(1)<<localReadFile.size()<<localReadFile.at(2);
    QStringList localSplit = localReadFile.at(0).split(".");
    CirXYC.append(localSplit.at(0));
    localSplit = localReadFile.at(1).split(".");
    CirXYC.append(localSplit.at(0));  //得到圆的xy 和圆中心
    localSplit = localReadFile.at(2).split(".");
    CirXYC.append(localSplit.at(0));  //得到圆的xy 和圆中心
    COUT<<CirXYC;
    QString cirx = CirXYC.at(0);
    QString ciry = CirXYC.at(1);
    QString cirp = CirXYC.at(2);
    COUT<<cirx.toInt()<<ciry.toInt()<<cirp.toInt()<<CirXp<<CirYp;
    int CirX,CirY;
    if(CirFangDA = false)
    {
        CirX = CirXp.toInt()+ cirx.toInt()+FangDapicX; // x点
        CirY = CirYp.toInt()+ ciry.toInt() + FangDapicY;  // y点 相对于图片
    }
    else
    {
        CirX = FangDapicX+ cirx.toInt(); // x点
        CirY = FangDapicY+ ciry.toInt();  // y点 相对于图片
    }

    int CirPointC = cirp.toInt();   // 圆心 相对于图片
    COUT<<CirX<<CirY<<CirPointC;

    if(isFDtrue)
    {
        //需要比例缩放 得到的点位
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        circle(src,cv::Point(CirX,CirY),CirPointC,cv::Scalar(255,0,0),2,cv::LINE_AA);    // 这个是切割后的图
        double x = double(NewWidth)/double(src.rows); // 得到全局的当前显示的大小
        double y = double(NewHeight)/double(src.cols);
        if(x<=0 || y<=0 || NewHeight<=0 || NewWidth<=0)
        {
            return;
        }
        cv::resize(src, zoomImg, cv::Size(0,0), x, y);//使用默认的双线性插值缩放图像
        cv::imshow("lena", zoomImg);
    }
    else
    {
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        circle(src,cv::Point(CirX,CirY),CirPointC,cv::Scalar(255,0,0),2,cv::LINE_AA);    // 这个是切割后的图
        cv::imshow("lena", src);
    }
    ui->lineEdit_size_w->setText(QString::number(CirPointC));  // 半径
    ui->lineEdit_CirPoint->setText(QString::number(CirX)+","+QString::number(CirY));
    setTextCirandLine(2);
}

void MainWindow::TCS()
{
    // 不可用
    cv::Mat img = cv::imread(openFileName.toLocal8Bit().toStdString());
    if (img.empty())
    {
        qDebug() << "输入图像为空";
    }
    cv::Mat edge;
    //Canny(原图， 新图， 阈值， 阈值， 卷积核大小， 梯度)
    cv::Canny(img, edge, 80, 180, 3, false);
    //threshold(原图，新图， 阈值， 超过阈值变成255， 类型（二值化）)
    cv::threshold(edge, edge, 170, 255, cv::THRESH_BINARY);
    vector<cv::Vec4i> lines1, lines2;
    //HoughLinesp（原图， 向量， r的单位长度， theta单位长度， 阈值（大于该阈值认定为直线）， 直线最小长度阈值， 直线相邻两点最大距离）
    cv::HoughLinesP(edge, lines1, 1, CV_PI / 180, 150, 30, 10);
    //HoughLinesP(edge, lines2, 1, CV_PI / 180, 150, 30, 30);
    cv::HoughLinesP(edge, lines2, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );
    cv::Mat img1;
    img.copyTo(img1);
    //连接计算出来的直线
    for (size_t i = 0; i < lines1.size(); i++)
    {
        line(img, cv::Point(lines1[i][0], lines1[i][1]), cv::Point(lines1[i][2], lines1[i][3]), cv::Scalar(255), 3 );
    }
    for (size_t i = 0; i < lines2.size(); i++)
    {
        line(img1, cv::Point(lines2[i][0], lines2[i][1]), cv::Point(lines2[i][2], lines2[i][3]), cv::Scalar(255), 3 );
    }
    cv::imshow("img", img);
    cv::imshow("img1", img1);
    cv::waitKey(0);
}
//寻找所有canny 弧

QPointF MainWindow::getVector() {
    return QPointF(_ptEnd.x() - _ptStart.x(), _ptEnd.y() - _ptStart.y());
}

double MainWindow::getLength() {
    return sqrt((_ptEnd.x() - _ptStart.x())*(_ptEnd.x() - _ptStart.x()) + (_ptEnd.y() - _ptStart.y())*(_ptEnd.y() - _ptStart.y()));
}


/**
 * @brief MainWindow::newcdst_show 直线重新显示 填入直线的数
 * @param linesPset
 */
void MainWindow::newcdst_show(vector<cv::Vec4i> linesPset)
{
    COUT<<linesPset.size();
    if(linesPset.size()==0)
    {
        return;
    }

    if(isFDtrue)
    {
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        cv::Mat dst, cdst;
        cv::Canny(src, dst, GrayNum, BinarizationNum, 3);
        cv::cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
        vector<cv::Vec4i> lines;
        cv::HoughLinesP(dst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );
        for (size_t i = 0; i < linesPset.size(); i++)
        {
            //line(img1, Point(linesPset[i][0], linesPset[i][1]), Point(linesPset[i][2], linesPset[i][3]), Scalar(255), 3 );
            cv::line(src, cv::Point(linesPset[i][0],linesPset[i][1]), cv::Point(linesPset[i][2], linesPset[i][3]), cv::Scalar(255),3);  // 颜色变白裁剪
        }
        //需要比例缩放 得到的点位
        double x = double(NewWidth)/double(src.rows); // 得到全局的当前显示的大小
        double y = double(NewHeight)/double(src.cols);
        if(x<=0 || y<=0 || NewHeight<=0 || NewWidth<=0)
        {
            return;
        }
        cv::resize(src, zoomImg, cv::Size(0,0), x, y);//使用默认的双线性插值缩放图像
        cv::imshow("lena", zoomImg);
    }
    else
    {
        cv::Mat dst, cdst;
        cv::Canny(src, dst, GrayNum, BinarizationNum, 3);
        cv::cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
        vector<cv::Vec4i> lines;
        cv::HoughLinesP(dst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );
        cv::Mat img1;
        src.copyTo(img1);
        for (size_t i = 0; i < linesPset.size(); i++)
        {
            //line(img1, Point(linesPset[i][0], linesPset[i][1]), Point(linesPset[i][2], linesPset[i][3]), Scalar(255), 3 );
            cv::line(src, cv::Point(linesPset[i][0],linesPset[i][1]), cv::Point(linesPset[i][2], linesPset[i][3]), cv::Scalar(255),3);  // 颜色变白裁剪
        }
        cv::imshow("lena", src);
    }
}

/**
 * @brief MainWindow::newcdstCir_show 显示圆
 */
void MainWindow::newcdstCir_show(cv::Point x, double y)
{
    cv::Mat src;
    if(LineIsshow)
    {
        src = cv::imread(WorkImage.toLocal8Bit().toStdString());
        COUT<<FangDafilenameNew<<WorkImage;
    }
    else
    {
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        COUT<<openFileName;
    }
    cv::Mat dst, cdst;
    cv::Canny(src, dst, GrayNum, BinarizationNum, 3);
    cv::cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
    cv::circle(src,cv::Point(x.x,x.y),y,cv::Scalar(0,0,255),1,cv::LINE_AA);
    cv::Mat img1;
    src.copyTo(img1);
    QImage img = cvMat2QImage(img1);
    QSize IMAGE_SIZE(ui->widget_4->size());
    ui->widget_4->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img).scaled(IMAGE_SIZE)));
    ui->widget_4->setPalette(palette);
}

// 预备用圆的
void MainWindow::newcdst_Pshow(QPoint x, QPoint y)
{
    cv::Mat src;
    src = cv::imread(openFileName.toLocal8Bit().toStdString());
    cv::Mat dst, cdst;
    Canny(src, dst, GrayNum, BinarizationNum, 3);
    cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
    vector<cv::Vec4i> lines;
    cv::HoughLinesP(dst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );
    cv::Mat img1;
    src.copyTo(img1);

    cv::line(img1,cv::Point(x.x(),x.y()),cv::Point(y.x(),y.y()), cv::Scalar(0,0,255), 3,cv::LINE_AA ); //LINE_AA CV_AA
    //imshow("detected lines", img1); //显示直线图片

    QImage img = cvMat2QImage(img1);
    QSize IMAGE_SIZE(ui->widget_4->size());
    ui->widget_4->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img).scaled(IMAGE_SIZE)));
    ui->widget_4->setPalette(palette);
    // ui->label_2->setPixmap(QPixmap::fromImage(img).scaled(ui->label_2->size()));
}

void MainWindow::findConTours()
{
    if(openFileName.isEmpty())
    {
        return;
    }
#if 0
    IplImage* src = cvLoadImage(openFileName.toLocal8Bit().toStdString().c_str(), CV_LOAD_IMAGE_GRAYSCALE);
    IplImage* dst = cvCreateImage(cvGetSize(src), 8, 3);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contour = 0;
    cvThreshold(src, src,100, 255, CV_THRESH_BINARY);	// 二值化
    cvNamedWindow("Source", 1);
    cvShowImage("Source", src);
    // 提取轮廓
    //int contour_num = cvFindContours(src, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); //CV_CHAIN_APPROX_NONE
    int contour_num = cvFindContours(src, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
    cvZero(dst);		// 清空数组
    CvSeq *_contour = contour;

    double maxarea = 0;
    double minarea = 100;
    int m = 0;
    int colornum = 0;
    for( ; contour != 0; contour = contour->h_next )
    {
        double tmparea = fabs(cvContourArea(contour));
        //        if(tmparea < minarea)
        //        {
        //            cvSeqRemove(contour, 0); // 删除面积小于设定值的轮廓
        //            continue;
        //        }
        CvRect aRect = cvBoundingRect(contour,0);
        COUT<<aRect.height<<aRect.width<<aRect.y<<aRect.x;
        if ((aRect.width/aRect.height)<1)
        {
            //                cvSeqRemove(contour, 0); //删除宽高比例小于设定值的轮廓
            //                continue;
        }
        if(tmparea > maxarea)
        {
            maxarea = tmparea;
        }
        m++;
        // 创建一个色彩值
        CvScalar color = CV_RGB( 0, 10+colornum, 255 );
        colornum+= 10;
        //max_level 绘制轮廓的最大等级。如果等级为0，绘制单独的轮廓。如果为1，绘制轮廓及在其后的相同的级别下轮廓
        //如果值为2，所有的轮廓。如果等级为2，绘制所有同级轮廓及所有低一级轮廓，诸此种种
        //如果值为负数，函数不绘制同级轮廓，但会升序绘制直到级别为abs(max_level)-1的子轮廓

        //  内部轮廓为主
        cvDrawContours(dst, contour, color, color, -1, 1, 8);	//绘制外部和内部的轮廓

        float radius;
        Point2f center;
        //        minEnclosingCircle(Mat(contour[1]), center, radius);
        //        circle(dst, Point(center), static_cast<int>(radius), Scalar(255), 2);
    }
    // cv2.rectangle(image, (x,y), (x+w,y+h), (153,153,0), 5);
    COUT<<"m = "<<m;
    contour = _contour;
    int count = 0;
    for(; contour != 0; contour = contour->h_next)
    {
        count++;
        double tmparea = fabs(cvContourArea(contour));
        if (tmparea == maxarea)
        {
            CvScalar color = CV_RGB( 255, 0, 0); // 外轮廓识别
            cvDrawContours(dst, contour, color, color, -1, 1, 8);
        }
        CvRect aRect = cvBoundingRect(contour,0);
        COUT<<aRect.height<<aRect.width<<aRect.y<<aRect.x;
    }

    COUT<<"The total number of contours is"<<count;
    cvNamedWindow("Components", 1);
    cvShowImage("Components", dst);
    cvWaitKey(0);
    cvDestroyWindow("Source");
    cvReleaseImage(&src);
    cvDestroyWindow("Components");
    cvReleaseImage(&dst);
#elif 0
    string file_name(openFileName.toLocal8Bit().toStdString());//路径，改成自己的
    cv::Mat image = imread(file_name, 0);
    cv:: Mat imageShold;
    cv::threshold(image, imageShold, 100, 255, THRESH_BINARY);//二值化

    cv::Mat labels;
    int n_comps = connectedComponents(imageShold, labels, 4, CV_16U);
    COUT << "轮廓数" << n_comps << endl;

    //draw
    int rows = image.rows;
    int cols = image.cols;
    Mat src_color;// = Mat::zeros(imageShold.size(), CV_8UC3);
    src_color.create(rows, cols, CV_8UC3);
    src_color = Scalar::all(0);
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            int label = labels.at<__int16>(x, y);//注意labels是CV_16U类型
            if (label == 0)
            {
                src_color.at<Vec3b>(x, y) = Vec3b(255, 255, 255);
                continue;
            }
            src_color.at<Vec3b>(x, y)[0] = (label*10*10*10) % 255;
            src_color.at<Vec3b>(x, y)[1] = (label*10*10) % 255;
            src_color.at<Vec3b>(x, y)[2] = (label*10) % 255;
        }
    }

    imwrite("C:/Users/XXXXXXX.png", src_color);//路径，改成自己的
    imshow("detected lines", src_color); //显示直线图片
    //cvShowImage("Components", src_color);

#elif 0
    IplImage* img;
    img = cvLoadImage(openFileName.toLocal8Bit().toStdString().c_str());
    IplImage* gray = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    cvCvtColor(img,gray,CV_BGR2GRAY);
    cvThreshold(gray,gray,128,255,CV_THRESH_BINARY);
    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq * first_contour = NULL;
    int Ncontour = cvFindContours(gray,storage,&first_contour,sizeof(CvContour),CV_RETR_LIST);
    //Ncontour为cvFindContours函数返回的轮廓个数
    COUT<<Ncontour;
    for(CvSeq* c = first_contour;c!= NULL;c=c->h_next)
    {
        //        cvDrawContours(img,c,cvScalar(255,255,0),cvScalar(255,0,255),0,2,8);
        cvNamedWindow("contours",CV_WINDOW_AUTOSIZE);
        //        cvShowImage("contours",img);
        for(int k = 0;k <c->total;++k)
        {
            CvPoint* p = CV_GET_SEQ_ELEM(CvPoint,c,k);
            printf("(%d,%d)\n",p->x,p->y);

        }
        CvRect rect;
        rect = cvBoundingRect(c,0);
        cvFloodFill(img,cvPoint(img->width/2,img->height/2),cvScalar(255,255,255),cvScalar(20),cvScalar(20),NULL,4,NULL);
        cvShowImage("contours",img);

        int Num[500][500];
        for (int i=0;i<(img->height-5);i++)
            for (int j=0;j<(img->width-5);j++)
            {
                CvScalar S0;
                S0=cvGet2D(img,i,j);
                if(S0.val[0] == 255)
                    Num[i][j]=1;
                else
                    Num[i][j]=0;
                // printf("(%d,%d)\n",i,j);
            }


    }
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvReleaseImage(&gray);
    cvDestroyWindow("contours");


    cv::Mat src = imread(openFileName.toLocal8Bit().toStdString(),0);
    cv::Mat result = src.clone();
    cv::Mat th1;
    // 最大类间差法，也称大津算法
    threshold(result, th1, 0, 255, THRESH_OTSU);
    // 反相
    th1 = 255 - th1;
    // 确定连通区轮廓
    std::vector<std::vector<cv::Point> > contours;  // 创建轮廓容器
    std::vector<cv::Vec4i> 	hierarchy;
    cv::findContours(th1, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE, cv::Point());
    // 遍历轮廓显示矩形框
    for (int i = 0; i < contours.size(); ++i)
    {
        cv::Rect rect = cv::boundingRect(cv::Mat(contours[i]));
        cv::rectangle(result, rect, Scalar(255), 1);
    }

    imshow("original", src);
    imshow("thresh", th1);
    imshow("result", result);
    waitKey(0);


#endif

}

void MainWindow::init_cirH()
{
#if 0
    //load edge image
    cv::Mat color = cv::imread(openFileName.toLocal8Bit().toStdString());

    // convert to grayscale
    cv::Mat gray;
    cv::cvtColor(color, gray, CV_RGB2GRAY);

    // get binary image
    cv::Mat mask = gray > 0;
    //erode the edges to obtain sharp/thin edges (undo the blur?)
    cv::erode(mask, mask, cv::Mat());

    //    std::vector<cv::Point2f> edgePositions;
    //    edgePositions = getPointPositions(mask);

    // create distance transform to efficiently evaluate distance to nearest edge
    cv::Mat dt;
    cv::distanceTransform(255-mask, dt,CV_DIST_L1, 3);
    unsigned int nIterations = 0;
    char quitKey = 'q';
    std::cout << "press " << quitKey << " to stop" << std::endl;
    while(cv::waitKey(-1) != quitKey)
    {
        //RANSAC: randomly choose 3 point and create a circle:
        //TODO: choose randomly but more intelligent,
        //so that it is more likely to choose three points of a circle.
        //For example if there are many small circles, it is unlikely to randomly choose 3 points of the same circle.
        unsigned int idx1 = rand()%edgePositions.size();
        unsigned int idx2 = rand()%edgePositions.size();
        unsigned int idx3 = rand()%edgePositions.size();

        // we need 3 different samples:
        if(idx1 == idx2) continue;
        if(idx1 == idx3) continue;
        if(idx3 == idx2) continue;

        // create circle from 3 points:
        cv::Point2f center; float radius;
        getCircle(edgePositions[idx1],edgePositions[idx2],edgePositions[idx3],center,radius);

        float minCirclePercentage = 0.4f;

        // inlier set unused at the moment but could be used to approximate a (more robust) circle from alle inlier
        std::vector<cv::Point2f> inlierSet;

        //verify or falsify the circle by inlier counting:
        float cPerc = verifyCircle(dt,center,radius, inlierSet);

        if(cPerc >= minCirclePercentage)
        {
            std::cout << "accepted circle with " << cPerc*100.0f << " % inlier" << std::endl;
            // first step would be to approximate the circle iteratively from ALL INLIER to obtain a better circle center
            // but that's a TODO

            std::cout << "circle: " << "center: " << center << " radius: " << radius << std::endl;
            cv::circle(color, center,radius, cv::Scalar(255,255,0),1);

            // accept circle => remove it from the edge list
            cv::circle(mask,center,radius,cv::Scalar(0),10);

            //update edge positions and distance transform
            edgePositions = getPointPositions(mask);
            cv::distanceTransform(255-mask, dt,CV_DIST_L1, 3);
        }

        cv::Mat tmp;
        mask.copyTo(tmp);

        // prevent cases where no fircle could be extracted (because three points collinear or sth.)
        // filter NaN values
        if((center.x == center.x)&&(center.y == center.y)&&(radius == radius))
        {
            cv::circle(tmp,center,radius,cv::Scalar(255));
        }
        else
        {
            std::cout << "circle illegal" << std::endl;
        }

        ++nIterations;
        cv::namedWindow("RANSAC"); cv::imshow("RANSAC", tmp);
    }

    std::cout << nIterations <<  " iterations performed" << std::endl;


    cv::namedWindow("edges"); cv::imshow("edges", mask);
    cv::namedWindow("color"); cv::imshow("color", color);

    cv::imwrite("detectedCircles.png", color);
    cv::waitKey(-1);
#endif

}

/**
 * @brief MainWindow::getAllPoint
 * @param maxCorners
 * @param minbit
 * @param ql
 * @param minDistance
 */
void MainWindow::getAllPoint(int maxCorners, int minbit, double ql, int minDistance) //得到所有点
{

}

// 新得到点
void MainWindow::newgetCirPointClide(QPoint x1, QPoint y1, QPoint x2, QPoint y2, int model)
{
    QString x1_text =QString::number(x1.x())+"," +QString::number(x1.y());
    QString y1_text =QString::number(y1.x())+"," +QString::number(y1.y());
    QString x2_text =QString::number(x2.x())+"," +QString::number(x2.y());
    QString y2_text =QString::number(y2.x())+"," +QString::number(y2.y());

    myClassA->sendPoint(x1_text,y1_text,x2_text,y2_text);
    if(model == 1) // 当1 为点击信号
    {
        myClassA->LeftIsClied(CirNumPir);  // 鼠标左键点击
    }
    //emit sendPoint(x1_text,y1_text,x2_text,y2_text);
}

void MainWindow::getpoint(QString x1, QString y1, QString x2, QString y2)
{
    ui->lineEdit_start_x->setText(x1);
    ui->lineEdit_start_y->setText(y1);
    ui->lineEdit_start_x_2->setText(x2);
    ui->lineEdit_start_y_2->setText(y2);
}



float verifyCircle(cv::Mat dt, cv::Point2f center, float radius, std::vector<cv::Point2f> & inlierSet)
{
    unsigned int counter = 0;
    unsigned int inlier = 0;
    float minInlierDist = 2.0f;
    float maxInlierDistMax = 100.0f;
    float maxInlierDist = radius/25.0f;
    if(maxInlierDist<minInlierDist) maxInlierDist = minInlierDist;
    if(maxInlierDist>maxInlierDistMax) maxInlierDist = maxInlierDistMax;

    // choose samples along the circle and count inlier percentage
    for(float t =0; t<2*3.14159265359f; t+= 0.05f)
    {
        counter++;
        float cX = radius*cos(t) + center.x;
        float cY = radius*sin(t) + center.y;

        if(cX < dt.cols)
            if(cX >= 0)
                if(cY < dt.rows)
                    if(cY >= 0)
                        if(dt.at<float>(cY,cX) < maxInlierDist)
                        {
                            inlier++;
                            inlierSet.push_back(cv::Point2f(cX,cY));
                        }
    }

    return (float)inlier/float(counter);
}


inline void getCircle(cv::Point2f& p1,cv::Point2f& p2,cv::Point2f& p3, cv::Point2f& center, float& radius)
{
    float x1 = p1.x;
    float x2 = p2.x;
    float x3 = p3.x;

    float y1 = p1.y;
    float y2 = p2.y;
    float y3 = p3.y;

    // PLEASE CHECK FOR TYPOS IN THE FORMULA :)
    center.x = (x1*x1+y1*y1)*(y2-y3) + (x2*x2+y2*y2)*(y3-y1) + (x3*x3+y3*y3)*(y1-y2);
    center.x /= ( 2*(x1*(y2-y3) - y1*(x2-x3) + x2*y3 - x3*y2) );

    center.y = (x1*x1 + y1*y1)*(x3-x2) + (x2*x2+y2*y2)*(x1-x3) + (x3*x3 + y3*y3)*(x2-x1);
    center.y /= ( 2*(x1*(y2-y3) - y1*(x2-x3) + x2*y3 - x3*y2) );

    radius = sqrt((center.x-x1)*(center.x-x1) + (center.y-y1)*(center.y-y1));
}



std::vector<cv::Point2f> getPointPositions(cv::Mat binaryImage)
{
    std::vector<cv::Point2f> pointPositions;

    for(unsigned int y=0; y<binaryImage.rows; ++y)
    {
        //unsigned char* rowPtr = binaryImage.ptr<unsigned char>(y);
        for(unsigned int x=0; x<binaryImage.cols; ++x)
        {
            //if(rowPtr[x] > 0) pointPositions.push_back(cv::Point2i(x,y));
            if(binaryImage.at<unsigned char>(y,x) > 0) pointPositions.push_back(cv::Point2f(x,y));
        }
    }

    return pointPositions;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    {
        CirNumPir++;
    }
    else
    {
        CirNumPir--;
        if(CirNumPir <=1)
        {
            CirNumPir = 1;
        }
    }
    if ((QApplication::keyboardModifiers() == Qt::ControlModifier))
    {
        //Mat src;
        QPoint numDegrees;                                     // 定义指针类型参数numDegrees用于获取滚轮转角
        numDegrees = event->angleDelta();                      // 获取滚轮转角
        int step = 0;                                          // 设置中间参数step用于将获取的数值转换成整数型
        if (!numDegrees.isNull())                              // 判断滚轮是否转动
        {
            step = numDegrees.y();                             // 将滚轮转动数值传给中间参数step
        }
        event->accept();       //h = img.rows;
        // w = img.cols;                                // 获取事件
        static double currentWidth = src.rows;                  // 获取当前图像的宽
        static double currentHeight = src.cols;                // 获取当前图像的高
        double OldWidth = src.rows;
        double OldHeight = src.cols;
        double bei = double(OldWidth)/double(OldHeight);
        // 对当前图像的宽累加
        if (step > 0)                                          // 判断图像是放大还是缩小
        {
            currentWidth +=  step;       // 按照线性比例 缩小放大
            double D;
            double allNUm = currentWidth;
            D = double(allNUm)/double(bei) - currentHeight;
            currentHeight += D;
            QString imgsize = QString("图像放大,尺寸为：%1 * %2")
                    .arg(currentWidth).arg(currentHeight);                             // 打印放大后的图像尺寸
        }
        else
        {
            currentWidth +=  step;       //
            double D;
            double allNUm = currentWidth;
            D = double(allNUm)/double(bei) - currentHeight;
            currentHeight += D;
            QString imgsize = QString("图像缩小,尺寸为：%1 * %2")
                    .arg(currentWidth).arg(currentHeight);                             // 打印缩小后的图像尺寸
        }

        //ui->label_2->resize(currentWidth, currentHeight);          // 通过更新图像显示控件的大小来更新图像大小
        double x = double(currentWidth)/double(src.rows);
        double y = double(currentHeight)/double(src.cols);
        if(x<=0 || y<=0 || currentHeight<=0 || currentHeight<=0)
        {
            return;
        }
        NewHeight = currentHeight;  // 得到全局的当前显示的大小
        NewWidth = currentWidth;
        qDebug()<<currentWidth<<currentHeight<<src.rows<<src.cols<<"x y "<<x,y;
        cv::resize(src, zoomImg, cv::Size(0,0), x, y);//使用默认的双线性插值缩放图像
        //cv::imshow("zoom", zoomImg);
        isFDtrue = true;
    }
}

// OpenCV鼠标事件
void on_MouseHandle(int event, int x, int y, int flags, void *param)
{
    static cv::Point pt1, pt2;
    static int start = 0;
    cv::Mat img;
    cv::Mat image;// *(Mat*)param; 放大的图
    static cv::Point p0;
    static int xrect_img; //左键按下时，窗口显示图像左上角在源图像中x、y
    static int yrect_img;

    src.copyTo(image);  // 原图
    if(isFDtrue)
    {
        zoomImg.copyTo(img);
        zoomImg.copyTo(image_Move);//image_Move
    }
    else
    {
        src.copyTo(img);   //这样复制两个变量不会使用同一幅图像
    }
    //
    // static声明静态局部变量，值在函数调用结束后不消失而保留原值，
    //即其占用的存储单元不释放，在下次该函数调用时，该变量保留上一次函数调用结束时的值
#if 0
    {
        if(event==CV_EVENT_RBUTTONDOWN)
        {
            p0=cv::Point(x,y); //获取鼠标左键按下时的起始点
            xrect_img=rect_img.x;
            yrect_img=rect_img.y;
            COUT<<p0.x<<p0.y;
        }
        if(event==CV_EVENT_MOUSEMOVE&& (flags & CV_EVENT_RBUTTONDOWN)) //右键键按下，鼠标移动时
        {
            int dx=x-p0.x;
            int dy=y-p0.y;
            COUT<<x<<y<<" mose move and lift "<<dx<<dy;
            if(x>=0 && x<=win_width-1 && y>=0 && y<=win_height-1) //判断鼠标是否在窗口图像区域内
            {
                rect_img=cv::Rect(xrect_img-dx,yrect_img-dy,rect_img.width,rect_img.height); //窗口显示图像移动dx、dy（相对于鼠标左键按下时）
                if(rect_img.x<0)
                {
                    rect_img.x=0;
                }
                if(rect_img.y<0)
                {
                    rect_img.y=0;
                }
                if(rect_img.x > image_Move.cols-rect_img.width-1)
                {
                    rect_img.x=image_Move.cols-rect_img.width-1;
                }
                if(rect_img.y > image_Move.rows - rect_img.height-1)
                {
                    rect_img.y=image_Move.rows - rect_img.height-1;
                }
                moveImage();
            }
        }
    }
#endif
    switch (event)
    {
    case cv::EVENT_LBUTTONDOWN:		//左键按下消息
    {
        start = 1;
        pt1 = cv::Point(x, y);
        double NowImageHeight = img.cols;
        double NowImagewidth = img.rows;

        double HeiBili = double(src.cols)/double(NowImageHeight);   // 当前的图像的大小和 原图大小得到比例
        double WidBili = double(src.rows)/double(NowImagewidth);
        //pint=QPoint(event->pos().x(),event->pos().y());
        //qDebug()<<"pint:"<<pint;
        QPoint x1 = QPoint(x-CirNumPir,y-CirNumPir);
        QPoint y1 = QPoint(x-CirNumPir,y+CirNumPir);
        QPoint x2 = QPoint(x+CirNumPir,y-CirNumPir);
        QPoint y2 = QPoint(x+CirNumPir,y+CirNumPir);
        MainWindow::newgetCirPointClide(x1,y1,x2,y2,1);   //得到圆的四个点
        //sendPoint(x1,y1,x2,y2);
        std::cout << "start: (" << pt1.x << ", " << pt1.y << ")"<<"now imghigwid"<<NowImageHeight<<NowImagewidth<<"bili = "<<HeiBili<<WidBili << std::endl;
        break;
    }
    case cv::EVENT_MOUSEMOVE:		//鼠标移动事件
    {
        pt2 = cv::Point(x, y);
        //cv::rectangle(img, pt1, pt2, cv::Scalar(0, 0, 255), 10, 80, 0);
        QPoint x1 = QPoint(x-CirNumPir,y-CirNumPir);
        QPoint y1 = QPoint(x-CirNumPir,y+CirNumPir);
        QPoint x2 = QPoint(x+CirNumPir,y-CirNumPir);
        QPoint y2 = QPoint(x+CirNumPir,y+CirNumPir);
        MainWindow::newgetCirPointClide(x1,y1,x2,y2,0);   //得到圆的四个点
        cv::circle(img, pt2, CirNumPir, (0, 0, 255));  // 100 是圆的半径
        //cv::circle(src, pt2, 100, (255, 0, 0), -1);  // 100 是圆的半径
        imshow("lena", img);  //显示当前已画矩形的图片
        break;
    }
    case cv::EVENT_LBUTTONUP:		//鼠标左键弹起事件
    {
        start = 0;
        pt2 = cv::Point(x, y);
        std::cout << "end: (" << pt2.x << ", " << pt2.y << ")" << std::endl;
        break;
    }
        //  case cv::EVENT_MOUSEWHEEL:
    }

}


vector<float> MainWindow::get_lines_arctan(vector<cv::Vec4i> lines)
{
    //输入一堆直线，返回每条直线与水平直线的角度，为弧度
    float k=0; //直线斜率
    vector <float> lines_arctan;//直线斜率的反正切值
    for (unsigned int i = 0; i<lines.size(); i++)
    {

        k = (double)(lines[i][3] - lines[i][1]) / (double)(lines[i][2] - lines[i][0]); //求出直线的斜率
        lines_arctan.push_back(atan(k));
    }
    return lines_arctan;
}

bool MainWindow::xiangjiao(int x1, int y1, int r1, int x2, int y2, int r2)
{

    double s;
    //s = (double((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
    s = sqrt(double((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)));
    if(int(s)<r2+r1&&int(s)>abs(r2-r1))
        //if(int(s)<r2+r1)
        return true;
    else
        return false;
}

void MainWindow::writeXMLInfo()
{
    double x_1= ui->lineEdit_Dpointx->text().toDouble();
    double y_1= ui->lineEdit_Dpointy->text().toDouble();
    double x_2= ui->lineEdit_Dpointx_2->text().toDouble();
    double y_2= ui->lineEdit_Dpointy_2->text().toDouble();
    double Lenth = ui->lineEdit_Lenth->text().toDouble();
    double angle = ui->lineEdit_angle->text().toDouble();
    cv::Mat matrix_eye = cv::Mat::eye(3, 3, CV_64F);

    cv::FileStorage fs("",cv::FileStorage::WRITE | cv::FileStorage::APPEND);//会覆盖当前文件，不存在则新建文件
    if(fs.isOpened())
    {
        fs << "x_1" << x_1 << "y_1" << y_1 << "x_2" << x_2 << "y_2" << y_2 << "Lenth" << Lenth << "angle" << angle;//可以连续写入
        fs << "matrix_eye" << matrix_eye;//也可以依次写入
        fs.release();//release after used
    }
}

/**
 * @brief MainWindow::writeTxtInfo 将直线圆信息写入到txt文件
 */
void MainWindow::writeTxtInfo()
{
    //QFile file("./LineInfo.txt");
    QFile *file = new QFile(QDir::currentPath()+"/"+"LineInfo.txt");//此路径下没有就会自己创建一个
    //while(!file->open(QIODevice::ReadWrite | QIODevice::Append));//以读写切追加写入的方式操作文本
    if(writeIsAdd)
    {
        if (file->open(QIODevice::Truncate | QIODevice::WriteOnly))   // 刚进入就清空
        {
            QTextStream stream(file);
            if(!CirDate.isEmpty())  // 直线为空 加入圆
            {
                for(int i =0; i <CirDate.size()/2; i++)  // 两个string 为一行数据 圆的 前面是点的半径 后面是大小
                {
                    // 写入圆的文件
                    QString localText;// = ui->lineEdit_size_w->text();  // 半径
                    QString localText2;// = ui->lineEdit_CirPoint->text();//ui->lineEdit_CirPoint->text();
                    localText = CirDate.at(i*2);   // 0
                    localText2 = CirDate.at(1 + i*2); // 1
                    QString text =QString("Cir") + ","+ localText2+","+localText + "\n";
                    stream <<text;
                    SaveDate.append(text);
                }
            }

            if(!LineDate.isEmpty())
            {
                for(int i = 0; i<LineDate.size()/4; i++)
                {
                    QString X_1Y1;
                    QString X_2Y2;
                    QString Lenth;// = ui->lineEdit_Lenth->text();
                    QString angle; //= ui->lineEdit_angle->text();
                    X_1Y1 = LineDate.at(i*4);
                    X_2Y2 = LineDate.at(1+i*4);
                    Lenth = LineDate.at(2+i*4);
                    angle = LineDate.at(3+i*4);
                    QString text = QString("Line") +","+X_1Y1+","+ X_2Y2+","+ Lenth+","+angle+"," + "\n";
                    stream <<text;
                    SaveDate.append(text);
                }
            }
            stream<< QString("FileSize") + "," + QString::number(OpenImageheight) + "," +  QString::number(OpenImagewidth) + "\n";
            //writeIsAdd = false;
        }
    }
#if 0
    else
    {
        if (file->open(QIODevice::ReadWrite | QIODevice::Append))
        {
            if(ui->Ldt_Jdu->text().isEmpty())  // 直线为空 加入圆
            {
                QTextStream stream(file);
                QString text =QString("Cir") + ","+ localText2+","+localText + "\n";
                stream <<text;
                SaveDate.append(text);
            }
            else if(ui->Ldt_cirPi->text().isEmpty())
            {
                QTextStream stream(file);
                QString text = QString("Line") +","+ X_1Y1+","+ X_2Y2+","+ Lenth+","+angle+"," + "\n";
                stream <<text;
                SaveDate.append(text);
            }
        }
    }
#endif
    file->close();
}


/**
 * @brief MainWindow::readTxtInfo 读取数据重新画出线条
 */
void MainWindow::readTxtInfo()
{
    QString fileName = QDir::currentPath()+"/"+"LineInfo.txt";
    cv::Mat img1;
    if(!TxtFilename.isEmpty())
    {
        fileName = TxtFilename;
    }
    COUT<<fileName;
    if (fileName.isEmpty())     //如果未选择文件便确认，即返回
        return;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line_1 = file.readLine();
            QString str(line_1);
            COUT<<str;
            QStringList localSplit = str.split(",");
            QString cccc = localSplit.at(0);
            if(cccc == "Line")
            {
                // 直线 得到
                QString cccc2 = localSplit.at(1);
                QString cccc3 = localSplit.at(2);
                QString cccc4 = localSplit.at(3);
                QString cccc5 = localSplit.at(4);
                QPoint x(cccc2.toDouble(),cccc3.toDouble());
                QPoint y(cccc4.toDouble(),cccc5.toDouble());
                vectLineXPoint.append( x);
                vectLineYPoint.append( y);
            }
            else if(cccc == "Cir")  // 圆的到
            {
                QString cccc2 = localSplit.at(1);   // 1.2 为 xy
                QString cccc3 = localSplit.at(2);  // 3 是 pi
                QString cccc4 = localSplit.at(3);  // 3 是 pi
                QPoint x(cccc2.toDouble(),cccc3.toDouble());
                cirPi.append(cccc4.toDouble());
                VectCirPoint.append( x);
            }
            else if(cccc == "FileSize")
            {
                QString cccc2 = localSplit.at(1);   // 1.2 为 xy
                QString cccc3 = localSplit.at(2);  // 3 是 pi
                OpenImageheightLing = cccc2.toDouble();
                OpenImagewidthLing = cccc3.toDouble();
                COUT<<OpenImageheightLing<<OpenImagewidthLing;
            }
            //line(img1, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines [i][3]), Scalar(255), 3 );
        }
        COUT<<vectLineYPoint.size();
        file.close();
    }

    if(!TxtFilename.isEmpty())
    {
        img1= cv::Mat::zeros(OpenImageheightLing, OpenImagewidthLing, CV_8UC3);
        cv::bitwise_not(img1, img1);
    }
    else
    {
        img1= cv::Mat::zeros(OpenImageheight, OpenImagewidth, CV_8UC3);
        cv::bitwise_not(img1, img1);
    }

    for(int i = 0; i <vectLineYPoint.size(); i++)
    {
        line(img1, cv::Point(vectLineXPoint.at(i).x(),vectLineXPoint.at(i).y()), cv::Point(vectLineYPoint.at(i).x(),vectLineYPoint.at(i).y()), cv::Scalar(255,0,0), 1);
    }
    for(int i = 0; i <cirPi.size(); i++)
    {
        circle(img1,cv::Point(VectCirPoint.at(i).x(),VectCirPoint.at(i).y()),cirPi.at(i),cv::Scalar(255,0,0),2,cv::LINE_AA);    // 这个是切割后的图
    }
    img1.copyTo(src);
    cv::imshow("lena",src);
}

void MainWindow::getFuSHi()
{
#if 0
    Mat myMat = imread(openFileName.toLocal8Bit().toStdString());
    //进行腐蚀操作
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    Mat dstImage;
    erode(myMat, dstImage, element);
    //显示效果图
    imshow("F", dstImage);
#endif
}

/**
 * @brief MainWindow::getPenZhang 膨胀
 */
void MainWindow::getPenZhang()
{
#if 0
    COUT << "Hello OpenCV " << CV_VERSION << endl;
    // 载入图像
    Mat myMat = imread(WorkImage.toLocal8Bit().toStdString());
    if(myMat.empty()){
    }
    //进行膨胀操作
    Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
    Mat out;
    dilate(myMat, out, element);
    //显示效果图
    imshow("P", out);
#endif
}

// 三点定圆
cv::Point MainWindow::threePointPlanCir(double a, double b, double c)
{
    cv::Mat img = cv::imread(ReleaseFileName.toLocal8Bit().toStdString());

    cv::Mat img1;
    //circle(img1,Point(circles[0],circles[1]),circles[2],Scalar(0,0,255),1,LINE_AA);  // 显示图方便看到是否是圆
    //imshow("imgjietu", img); // 查看图

    COUT<<ReleaseFileName;
    cv::Mat img_gray;
    cv::cvtColor(img,img_gray,cv::COLOR_BGR2GRAY);

    int x,y;
    int row,col;
    row = img.rows;
    col = img.cols;

    cv::Vec3b intensity;
    uchar blue,green,red;
    cv::Point Temp;
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            x = i;
            y = j;
            intensity = img.at<cv::Vec3b>(y,x);
            blue = intensity[0];
            green = intensity[1];
            red = intensity[2];
            COUT << "The point(" << x << "," << y <<") rgb_val: "<< (unsigned int)blue
                 << "," << (unsigned int)green << "," << (unsigned int)red << endl;
            COUT << "Gray pixel there is:" << (unsigned int)img_gray.at<uchar>(y,x)  << endl;
            if(blue!=255 && green!=255 && red!=255)
            {

                Temp.x = x;
                Temp.y = y;
                COUT<<Temp.x<<Temp.y;
                return Temp;
            }
        }
    }

}

// 人工标注
void MainWindow::on_pushButton_6_clicked()
{
    //findConTours(); // 找轮廓 暂时不要
    readTxtInfo();
    ui->Lbl_CMD->setText("读出直线");
}

void MainWindow::on_pushButton_7_clicked()
{
    IsBigPicK = true;
    FangDafilename = openFileName;
    isFANGDa = true;
    LineIsshow = true;
    ReleaseIsEnt = true;
    ui->Lbl_CMD->setText("框选区域放大-O");
}

void MainWindow::on_pushButton_8_clicked()
{
    QImage img_old;
    qDebug()<<"FangDafilename"<<FangDafilename<<OldFilename;
    openFileName=OldFilename;
    if (img_old.load(OldFilename))
    {
        isFANGDa = false;
        LineIsshow = false;
        QSize IMAGE_SIZE(ui->widget_4->size());
        ui->widget_4->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img_old).scaled(IMAGE_SIZE)));
        ui->widget_4->setPalette(palette);
    }
    WorkImageIsOk = false;
    GetWorkImageSize = false;// 得到工作区域大小
    ui->Lbl_CMD->setText("返回原图");
}

void MainWindow::on_action_2_triggered()
{
    ui->pushButton->clicked();
}

void MainWindow::on_action_3_triggered()
{
    ui->Btn_SaveFile->clicked();
}

void MainWindow::on_action_4_triggered()
{
    ui->Btn_SaveOther->clicked();
}

/**
 * @brief MainWindow::on_pushButton_11_clicked  导航栏出现
 */
void MainWindow::on_pushButton_11_clicked()
{
    ui->dockWidget->show();
}

/**
 * @brief MainWindow::on_Btn_Save_clicked 保存数据
 */
void MainWindow::on_Btn_Save_clicked()
{
    LineDate.clear();
    CirDate.clear();  // 清除重复数据
    for(int i = 0;i < model->rowCount() ;i++)
    {
        QStandardItem *item = model->item(i);

        COUT <<"item = " << item->text();
        GetItem(model->item(i),0 );
    }
    COUT<<LineDate<<LineDate.size();

    for(int i = 0;i < model_2->rowCount() ;i++)
    {
        QStandardItem *item = model_2->item(i);

        COUT <<"item = " << item->text();
        GetItem(model_2->item(i),1 );  // 直线选0 圆保存为1
    }
    COUT<<CirDate<<CirDate.size();
    writeTxtInfo();
}

void MainWindow::GetItem(QStandardItem *item,int mode)
{
    if(mode == 0)
    {
        Q_ASSERT(item);
        if(item->hasChildren())
        {
            COUT<<item->rowCount()<<item->columnCount() ;
            for(int i = 0;i < item->rowCount() ;i++)
            {
                for(int j = 1;j < item->columnCount() ;j++)  // 只保存后面的信息 即 点位坐标等长度信息
                {
                    QStandardItem * childitem = item->child(i,j);
                    COUT << "childitem = " << childitem->text();
                    LineDate.append(childitem->text());
                    GetItem(childitem,0);
                }
            }
        }
    }
    else
    {
        Q_ASSERT(item);
        if(item->hasChildren())
        {
            COUT<<item->rowCount()<<item->columnCount() ;
            for(int i = 0;i < item->rowCount() ;i++)
            {
                for(int j = 1;j < item->columnCount() ;j++)  // 只保存后面的信息 即 点位坐标等长度信息
                {
                    QStandardItem * childitem = item->child(i,j);
                    COUT << "childitem = " << childitem->text();
                    CirDate.append(childitem->text());
                    GetItem(childitem,1);
                }
            }
        }
    }

}
/**
 * @brief MainWindow::on_Btn_SaveFile_clicked 文件保存
 */
void MainWindow::on_Btn_SaveFile_clicked()
{
    TxtFilename = QFileDialog::getOpenFileName(this,"open file","",tr("文本文件(*.txt)"));//tr("文本文件(*.txt)"));
    COUT<<TxtFilename;
    readTxtInfo();
}

/**
 * @brief MainWindow::on_Btn_SaveOther_clicked 另存为
 */
void MainWindow::on_Btn_SaveOther_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("另存"),tr(""),tr("文本文件(*.txt)"));
    if(filePath == "")
        return;
    CurrentFilePath = filePath;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        ShowWarning_WhenSaveFailed();
        CurrentFilePath = "";
        return;
    }
    QTextStream textStream(&file);
    COUT<<OpenImageheight<<OpenImagewidth;
    textStream<< QString("FileSize") + "," + QString::number(OpenImageheight) + "," +  QString::number(OpenImagewidth) + "\n";
    for(int i =0 ; i<SaveDate.size(); i++)
    {
        textStream<<SaveDate.at(i);
    }
    file.close();
}


int MainWindow::ShowWarning_BeforeNewOpenClose()
{
    return QMessageBox::warning(this,tr("警告"),tr("还未保存"),QMessageBox::Save|QMessageBox::Ignore|QMessageBox::Cancel);
}

int MainWindow::ShowWarning_WhenOpenFailed()
{
    return QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
}
int MainWindow::ShowWarning_WhenSaveFailed()
{
    return QMessageBox::warning(this,tr("错误"),tr("保存文件失败"));
}

/**
 * @brief MainWindow::on_treeView_doubleClicked  双击就会将线条显示
 * @param index
 */
void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
#if 0
    COUT<<index;
    int dex = index.row();   // row 为行 第0行
    COUT<<index.row()<<index.column();//<<index.child();
    QAbstractItemModel* m=(QAbstractItemModel*)index.model();
    for(int columnIndex = 0; columnIndex < m->columnCount(); columnIndex++)
    {
        QModelIndex x=m->index(index.row(),columnIndex);
    }

    if(dex == 0)
    {
        QImage img_old;
        if (img_old.load(openFileName))
        {
            QSize IMAGE_SIZE(ui->widget_4->size());
            ui->widget_4->setAutoFillBackground(true);
            QPalette palette;
            palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img_old).scaled(IMAGE_SIZE)));
            ui->widget_4->setPalette(palette);
        }

        for(int i = 0; i <Point_StrVect.size(); i++)
        {
            const QString localAt = Point_StrVect.at(i);
            COUT<<localAt;
            QStringList localSplit = localAt.split(",");
            QString x1 = localSplit.at(0);
            QString y1 = localSplit.at(1);
            QString x2 = localSplit.at(2);
            QString y2 = localSplit.at(3);

        }
    }
    else
    {
        const QString localAt = Point_StrVect.at(dex);
        COUT<<localAt;
        QStringList localSplit = localAt.split(",");
        QString x1 = localSplit.at(0);
        QString y1 = localSplit.at(1);
        QString x2 = localSplit.at(2);
        QString y2 = localSplit.at(3);
        Mat src;
        Mat dst, cdst;
        Canny(src, dst, GrayNum, BinarizationNum, 3);
        cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
        vector<Vec4i> lines;
        HoughLinesP(dst, lines, 1, CV_PI/180, LinearStrengthNum, LinearLengthNum, LinearIntervalLengthNum );
        Mat img1;
        Work_LineQCImage.copyTo(img1);
        Mat dstImg = src.clone();
        line(img1, Point(x1.toDouble(), y1.toDouble()), Point(x2.toDouble(), y2.toDouble()), Scalar(0,0,0), 2 );  // 颜色变白裁剪
        img1.copyTo(Work_LineQCImage);
        QImage img = cvMat2QImage(img1);
        //    ui->label_2->setPixmap(QPixmap::fromImage(img).scaled(ui->label_2->size()));

        QSize IMAGE_SIZE(ui->widget_4->size());
        ui->widget_4->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img).scaled(IMAGE_SIZE)));
        ui->widget_4->setPalette(palette);
    }
#endif

}

/**
 * @brief MainWindow::on_Btn_SetCir_clicked 直线检测完 将圆检测 设置圆为当前的工作区
 */
void MainWindow::on_Btn_SetCir_clicked()
{

#if 0
    Mat img1;
    Work_LineQCImage.copyTo(img1);
    QImage img = cvMat2QImage(img1);
    //    ui->label_2->setPixmap(QPixmap::fromImage(img).scaled(ui->label_2->size()));

    QSize IMAGE_SIZE(ui->widget_4->size());
    ui->widget_4->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img).scaled(IMAGE_SIZE)));
    ui->widget_4->setPalette(palette);
    QString newImageName = QApplication::applicationDirPath() + "/5Image.png";
    WorkImageIsOk = true;
    WorkImage = newImageName;
    COUT<<img;
    img.save(newImageName);

    Mat myMat = imread(WorkImage.toLocal8Bit().toStdString());
    if(myMat.empty()){
    }
    //进行膨胀操作
    Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
    Mat element2 = getStructuringElement(MORPH_RECT, Size(5, 5));
    Mat element3 = getStructuringElement(MORPH_RECT, Size(7, 7));

    Mat out;
    dilate(myMat, out, element); // out 输出

    //显示效果图
    //进行腐蚀操作
    Mat element_p = getStructuringElement(MORPH_RECT, Size(3, 3));
    Mat dstImage_P;
    erode(out, dstImage_P, element_p); // dst_P为输出
    imshow("P", out);
    imshow("F", dstImage_P);
    //imshow("one", one);
    //    dilate(dstImage_P, out, element);
    //    imshow("P2", out);
    //    erode(out, dstImage_P, element2);
    //    imshow("F2", dstImage_P);

    //    dilate(dstImage_P, out, element);
    //    imshow("P3", out);
    //    erode(out, dstImage_P, element2);
    //    imshow("F3", dstImage_P);
    //显示效果图
    //    getPenZhang(); // 膨胀
    //    getFuSHi();   // 腐蚀
#endif
}


QList<QString> MainWindow::readFile(QString fileAllPath)
{
    QList<QString> list;

    QFileInfo fileinfo(fileAllPath);
    COUT<<fileAllPath;
    QFile file(fileAllPath);//fileinfo.absoluteFilePath());
    //    qDebug() << fileinfo.absoluteFilePath(); qDebug() << "fileinfo.absoluteFilePath()";
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray line = file.readAll();
        //QString str = codec->toUnicode(line);
        QString str = QString(line);
        QStringList localSplit = str.split(",");
        QString x1 = localSplit.at(0);
        QString y1 = localSplit.at(1);
        QString x2 = localSplit.at(2);
        list.append(x1);
        list.append(y1);
        list.append(x2);
        file.close();
    }
    return list;
}


/**
 * @brief MainWindow::on_Btn_HuaYuan_clicked  三点花园
 */
void MainWindow::on_Btn_HuaYuan_clicked()
{
    ModelChose  = 3;
    ui->Lbl_CMD->setText("三点定圆-C");
}

QPointF MainWindow::tcircle(QPointF pt1, QPointF pt2, QPointF pt3, double &radius)
{
    double x1 = pt1.x(), x2 = pt2.x(), x3 = pt3.x();
    double y1 = pt1.y(), y2 = pt2.y(), y3 = pt3.y();
    double a = x1 - x2;
    double b = y1 - y2;
    double c = x1 - x3;
    double d = y1 - y3;
    double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
    double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
    double det = b * c - a * d;
    if( fabs(det) < 1e-5)
    {
        radius = -1;
        return QPointF(0,0);
    }

    double x0 = -(d * e - b * f) / det;
    double y0 = -(a * f - c * e) / det;
    radius = hypot(x1 - x0, y1 - y0);
    return QPointF(x0, y0);
}

void MainWindow::HuaYuan(QPointF localTcircle,double pi)
{
    if(isFDtrue)
    {
        //需要比例缩放 得到的点位
        src = cv::imread(openFileName.toLocal8Bit().toStdString());
        COUT<<openFileName;
        //COUT<<openFileName;
        cv::Mat img1;
        src.copyTo(img1);
        cv::circle(src,cv::Point(localTcircle.x(),localTcircle.y()),pi,cv::Scalar(255,0,0),2,cv::LINE_AA);    // 这个是切割后的图
        //circle(img1,Point(circles[0],circles[1]),circles[2],Scalar(0,0,255),1,LINE_AA);  // 显示图方便看到是否是圆
        ui->lineEdit_size_w->setText(QString::number(pi));
        ui->lineEdit_CirPoint->setText(QString::number(localTcircle.x()) + "," +QString::number(localTcircle.y()));
        setTextCirandLine(2);
        double x = double(NewWidth)/double(src.rows); // 得到全局的当前显示的大小
        double y = double(NewHeight)/double(src.cols);
        if(x<=0 || y<=0 || NewHeight<=0 || NewWidth<=0)
        {
            return;
        }
        cv::resize(src, zoomImg, cv::Size(0,0), x, y);//使用默认的双线性插值缩放图像
        cv::imshow("lena", zoomImg);
        return;
    }
    src = cv::imread(openFileName.toLocal8Bit().toStdString());
    COUT<<openFileName;
    //COUT<<openFileName;
    cv::Mat img1;
    src.copyTo(img1);
    cv::circle(src,cv::Point(localTcircle.x(),localTcircle.y()),pi,cv::Scalar(255,0,0),2,cv::LINE_AA);    // 这个是切割后的图
    //circle(img1,Point(circles[0],circles[1]),circles[2],Scalar(0,0,255),1,LINE_AA);  // 显示图方便看到是否是圆
    cv::imshow("lena", src); // 查看图
    ui->lineEdit_size_w->setText(QString::number(pi));
    ui->lineEdit_CirPoint->setText(QString::number(localTcircle.x()) + "," +QString::number(localTcircle.y()));
    setTextCirandLine(2);

}

void MainWindow::setTextCirandLine(int model1)
{
    if(model1 ==1)
    {
        ui->Ldt_Jdu->setText( ui->lineEdit_angle->text());
        ui->Ldt_CD->setText( ui->lineEdit_Lenth->text());
        ui->Ldt_cirPi->clear();
        ui->Ldt_CirPoint->clear();
        if(treeisclear)
        {
            model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
        }
        LineNumTsize++;
        QStandardItem * item1 = new QStandardItem(tr("直线")+QString::number(LineNumTsize));
        QStandardItem * item2 = new QStandardItem(tr("2——班"));
        QStandardItem * item1_1 = new QStandardItem(tr("角度"));
        QStandardItem * item1_2 = new QStandardItem(tr("长度"));
        QStandardItem * item1_3 = new QStandardItem(tr("起点"));
        QStandardItem * item1_4 = new QStandardItem(tr("终点"));
        QString x_1= ui->lineEdit_Dpointx->text();   // 端点起始点
        QString y_1= ui->lineEdit_Dpointy->text();   //
        QString x_2= ui->lineEdit_Dpointx_2->text();
        QString y_2= ui->lineEdit_Dpointy_2->text(); // 端点结束点
        QStandardItem * item1_11 = new QStandardItem(ui->lineEdit_angle->text());
        QStandardItem * item1_21 = new QStandardItem(ui->lineEdit_Lenth->text());
        QStandardItem * item1_31 = new QStandardItem(x_1+","+y_1);
        QStandardItem * item1_41 = new QStandardItem(x_2 + ","+y_2);
        model->appendRow(item1);
        //model_2->appendRow(item2);
        QList<QStandardItem *> one,two,three,four;
        one<<item1_1<<item1_11;
        two<<item1_2<<item1_21;
        three<<item1_3<<item1_31;
        four<<item1_4<<item1_41;
        item1->appendRow(three);
        item1->appendRow(four);
        item1->appendRow(two);
        item1->appendRow(one);
    }
    else
    {
        if(tree2isclear)
        {
            model_2->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("类型")<<QStringLiteral("相关信息1")<<QStringLiteral("相关信息2"));
        }
        //                ui->Ldt_cirPi->setText(ui->lineEdit_size_w->text());
        ui->Ldt_CirPoint->setText(ui->lineEdit_CirPoint->text());
        ui->Ldt_Jdu->clear();
        ui->Ldt_CD->clear();
        CirNumTsize++;
        QStandardItem * item1 = new QStandardItem(tr("圆")+QString::number(CirNumTsize));
        QStandardItem * item2 = new QStandardItem(tr("2——班"));
        QStandardItem * item1_1 = new QStandardItem(tr("圆心"));
        QStandardItem * item1_2 = new QStandardItem(tr("半径"));
        QStandardItem * item1_11 = new QStandardItem(ui->lineEdit_CirPoint->text());
        QStandardItem * item1_21 = new QStandardItem(ui->lineEdit_size_w->text());
        model_2->appendRow(item1);
        //model_2->appendRow(item2);
        QList<QStandardItem *> one,two;
        one<<item1_1<<item1_11;
        two<<item1_2<<item1_21;
        item1->appendRow(two);
        item1->appendRow(one);
    }
}

/**
 * @brief MainWindow::on_Btn_CirNewChosse_clicked 新圆选
 */
void MainWindow::on_Btn_CirNewChosse_clicked()
{
    ModelChose  = 4;
    ui->Lbl_CMD->setText("圆框选定圆-C");
}

//新圆选 将原图copy 清空 然后画出内切圆 外切圆
void MainWindow::NewCirChosee(QString PicImageName,QPoint CirP,int Pinum,int stax,int stay,int endx,int endy)  // 得到圆点 和半径
{
    cv::Mat src1;
    src1 = cv::imread(openFileName.toLocal8Bit().toStdString());
    COUT<<openFileName;
    cv::Mat image2 =cv::Mat::zeros(height1, width1, CV_8UC3);// cdst.clone();//Mat::zeros(500, 500, CV_8UC3);   //  34 200 126 200

    for(int i=0;i<image2 .rows;i++)     // 高度 i
    { for(int j=0;j<image2 .cols;j++)   // 宽度 j
        {
            image2 .at<cv::Vec3b>(i,j)[0]=255;
            image2 .at<cv::Vec3b>(i,j)[1]=255;
            image2 .at<cv::Vec3b>(i,j)[2]=255;
        }
    }
    //然后画园

    cv::Mat image = cv::imread(openFileName.toLocal8Bit().toStdString());
    cv::Mat image1(image.rows, image.cols, image.type(), cv::Scalar(0, 0, 0));
    cv::Mat image3(image.rows, image.cols, image.type(), cv::Scalar(180, 120, 50));
    cv::Point center(CirP.x(),CirP.y());
    int radius = Pinum;

    // huayuan
    cv::circle(image, center, Pinum+1, cv::Scalar(255, 255, 255), 2, 8, 0);
    cv::circle(image, center, Pinum-10, cv::Scalar(0,0,0),-1);
    for (int x = 0; x < image.cols; x++)
    {
        for (int y = 0; y < image.rows; y++)
        {
            int temp = ((x - center.x) * (x - center.x) + (y - center.y) *(y - center.y));
            if (temp < (radius * radius)) // 圆内
            {
                image1.at<cv::Vec3b>(cv::Point(x, y))[0] = image.at<cv::Vec3b>(cv::Point(x, y))[0];
                image1.at<cv::Vec3b>(cv::Point(x, y))[1] = image.at<cv::Vec3b>(cv::Point(x, y))[1];
                image1.at<cv::Vec3b>(cv::Point(x, y))[2] = image.at<cv::Vec3b>(cv::Point(x, y))[2];
            }
            else //圆外
            {
            }
            image3.at<cv::Vec3b>(cv::Point(x, y))[0] = image.at<cv::Vec3b>(cv::Point(x, y))[0];
            image3.at<cv::Vec3b>(cv::Point(x, y))[1] = image.at<cv::Vec3b>(cv::Point(x, y))[1];
            image3.at<cv::Vec3b>(cv::Point(x, y))[2] = image.at<cv::Vec3b>(cv::Point(x, y))[2];
        }
    }
    //imshow("image1", image1);  // image1 就是想要的图片
    //然后取反
    cv::Mat wkarea_rs3;
    cv::bitwise_not(image1,wkarea_rs3); //取反
    //cv::imshow("wkarea_rs3 Cir image2", wkarea_rs3);   // 原始 全部清空变为空
    cv::circle(wkarea_rs3, center, Pinum-10, cv::Scalar(0,0,0), -1); // 内圆填充黑色
    //外圆填充
    //cv::imshow("wkarea_rs3 Cir image3new", wkarea_rs3);
    cv::Mat image5(wkarea_rs3.rows, wkarea_rs3.cols, wkarea_rs3.type(), cv::Scalar(0, 0, 0));
    cv::Mat image6(wkarea_rs3.rows, wkarea_rs3.cols, wkarea_rs3.type(), cv::Scalar(0, 0, 0));
    cv::Point center1(CirP.x(),CirP.y());
    int radius1 = 200;
    cv::circle(wkarea_rs3, center1, radius1, cv::Scalar(0, 0, 0), 2, 8, 0);
    for (int x = 0; x < wkarea_rs3.cols; x++)
    {
        for (int y = 0; y < wkarea_rs3.rows; y++)
        {
            int temp = ((x - center1.x) * (x - center1.x) + (y - center1.y) *(y - center1.y));
            if (temp < (radius * radius)) // 圆内
            {
                image5.at<cv::Vec3b>(cv::Point(x, y))[0] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[0];
                image5.at<cv::Vec3b>(cv::Point(x, y))[1] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[1];
                image5.at<cv::Vec3b>(cv::Point(x, y))[2] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[2];
            }
            else //圆外
            {
                image6.at<cv::Vec3b>(cv::Point(x, y))[0] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[0];
                image6.at<cv::Vec3b>(cv::Point(x, y))[1] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[1];
                image6.at<cv::Vec3b>(cv::Point(x, y))[2] = wkarea_rs3.at<cv::Vec3b>(cv::Point(x, y))[2];
            }
        }
    }
    //imshow("image5", image5);  // img5 最终反置就是最终结果


    //        cv::Mat wkarea_rs_img;
    cv::Mat resize_img5;
    cv::bitwise_not(image5,resize_img5); //取反
    //cv::imshow("resize_img5",resize_img5);
    //cv::imwrite("tmpicrcap.png",resize_img5);  //写入图片
    QImage localCvMat2QImage = cvMat2QImage(resize_img5);
    QImage newImage = localCvMat2QImage.copy(stax,stay, endx, endy);  // stax,int stay,int endx,int endy
    QString PicImageName = QDir::currentPath() + "/tmpcircap.png";
    newImage.save(PicImageName);
    //调用方法
    on_pushButton_5_clicked();
}

// 直线导航栏显示
void MainWindow::on_pushButton_12_clicked()
{
    ui->dockWidget_2->show();
}

// 删除直线导航栏的一行
void MainWindow::on_Btn_Remove_2_clicked()
{
    QStandardItem *currentItem;

    QStandardItemModel *model1 = static_cast<QStandardItemModel*>(ui->treeView->model());
    QModelIndex currentindex = ui->treeView->currentIndex();
    if(currentindex.row()==-1)
    {
        int war = QMessageBox::warning(NULL,"warning","Please select a deletion item !",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(war == QMessageBox::Yes || war == QMessageBox::No)
            return;
    }

    int rb = QMessageBox::warning(NULL,"warning","Are you sure to delete !",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        currentItem = model1->itemFromIndex(currentindex);
        if(!currentItem->parent())
        {
            model1->removeRow(currentindex.row());
            //currentItem->removeRows(0,currentItem->rowCount());
            //delete currentItem->takeRow(currentindex.row());
            return;
        }

        QStandardItem *parent = currentItem->parent();
        parent->removeRow(currentindex.row());
        //delete parent->takeChild(currentindex.row());
    }
}

// 删除圆导航栏的一行
void MainWindow::on_Btn_Remove_clicked()
{
    QStandardItem *currentItem;

    QStandardItemModel *model1 = static_cast<QStandardItemModel*>(ui->treeView_2->model());
    QModelIndex currentindex = ui->treeView_2->currentIndex();
    if(currentindex.row()==-1)
    {
        int war = QMessageBox::warning(NULL,"warning","Please select a deletion item !",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(war == QMessageBox::Yes || war == QMessageBox::No)
            return;
    }

    int rb = QMessageBox::warning(NULL,"warning","Are you sure to delete !",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        currentItem = model1->itemFromIndex(currentindex);
        if(!currentItem->parent())
        {
            model1->removeRow(currentindex.row());
            //currentItem->removeRows(0,currentItem->rowCount());
            //delete currentItem->takeRow(currentindex.row());
            return;
        }

        QStandardItem *parent = currentItem->parent();
        parent->removeRow(currentindex.row());
        //delete parent->takeChild(currentindex.row());
    }
}

void MainWindow::on_Btn_DeAll_clicked()
{
    model->clear();
    treeisclear = true;
}

void MainWindow::on_Btn_DeAll_2_clicked()
{
    model_2->clear();
    tree2isclear = true;
}
