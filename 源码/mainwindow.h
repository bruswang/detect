#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <mousesize.h>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>
#include <cmath>
#include <qstandarditemmodel.h>
#include <QMessageBox>
#include <QPainter>
#include <QRect>
//#include <QtPicT/hi_imagebox.h>

//using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStringList LineDate;
    QStringList CirDate;

    bool isCir;
    void init();     // 直线检测
    void NewInitLine(); // 最新直线选择
    void NewNewInitLine(); // 最新直线选择

    void init_cir(); // 圆检测
    void init_cirH(); // 无用
    void getAllPoint(int maxCorners = 500,int minbit = 172,double ql = 0.01, int minDistance = 5); // 得到所有点

    static void  newgetCirPointClide(QPoint x1, QPoint y1, QPoint x2, QPoint y2, int model);


    QList<QString> readFile(QString fileAllPath); // 读文件
    cv::Mat QImage2cvMat(QImage image);    // image转为cvmat
    QImage cvMat2QImage(const cv::Mat& mat); //cv mat矩阵转为 image
    void mousePressEvent(QMouseEvent *event);  // 重写鼠标按下事件
    //void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);   //重写鼠标移动事件
    void paintEvent(QPaintEvent * event);      //重画
    bool m_drag;                               // 判断是否
    QPoint m_pos;

    double oldPicX;
    double oldPicY;
    void wheelEvent(QWheelEvent *event);        // 用鼠标滚轮事件实现图像放大缩小
    //输入一堆直线，返回每条直线与水平直线的角度，为弧度
    vector <float> get_lines_arctan(vector<cv::Vec4i> lines);
    //判断圆是否跟我相交
    bool xiangjiao(int x1,int y1,int r1,int x2,int y2,int r2);

    int ShowWarning_BeforeNewOpenClose();  // 文件打开 另存失败报错
    int ShowWarning_WhenOpenFailed();
    int ShowWarning_WhenSaveFailed();

    void writeXMLInfo();   // 写入xml信息 暂时不需要 需求为写入txt
    void writeTxtInfo();   // 写入txt信息
    void readTxtInfo();    // 读取 txt信息 并且画出来
    bool writeIsAdd; //判断程序是否刚开始 已确定是否为追加写
    bool isFANGDa;   // 判断是否是放大的图片，为真则打开的图都为
    void getFuSHi();  // 腐蚀
    void getPenZhang() ; // 膨胀
    cv::Point threePointPlanCir(double a,double b, double c );  // 三点hua 圆
    QPointF tcircle(QPointF pt1, QPointF pt2, QPointF pt3, double &radius);
    void HuaYuan(QPointF localTcircle,double pi); // 开始画圆
    void setTextCirandLine(int model1);
    void GetItem(QStandardItem *item, int mode);

signals:
    void sendPoint(QString x1,QString y1,QString x2,QString y2);
    void sendPointCir(QString x1,QString Pi);
    void LeftIsClied(int value);  // 左键按下

private slots:

    void getpoint(QString x1, QString y1, QString x2, QString y2); // 得到正方形四个点位

    void on_pushButton_clicked();

    void on_horizontalSlider_Gray_valueChanged(int value);

    void on_horizontalSlider_Binarization_valueChanged(int value);

    void on_horizontalSlider_LinearStrength_valueChanged(int value);

    void on_horizontalSlider_LinearLength_valueChanged(int value);

    void on_horizontalSlider_LinearIntervalLength_valueChanged(int value);

    void on_horizontalSlider_Gray_sliderReleased();

    void on_horizontalSlider_Binarization_sliderReleased();

    void on_horizontalSlider_LinearStrength_sliderReleased();

    void on_horizontalSlider_LinearLength_sliderReleased();

    void on_horizontalSlider_LinearIntervalLength_sliderReleased();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_MinHCir_sliderReleased();

    void on_horizontalSlider_CirH_sliderReleased();

    void on_horizontalSlider_CirL_sliderReleased();

    void on_horizontalSlider_Mincir_sliderReleased();

    void on_horizontalSlider_Maxcir_sliderReleased();

    void getCirPointClide(QPoint x1,QPoint y1,QPoint x2,QPoint y2);

    void getCirIsClied(int value);  // 得到识别的id 按下的点击事件
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void TCS();
    QPointF getVector();//获取线段的向量
    double getLength();//获取线段的长度

    void newcdst_show(vector<cv::Vec4i> linesPset); //选中则显示直线
    void newcdstCir_show(cv::Point x,double y); //选中则显示圆

    void newcdst_Pshow(QPoint x, QPoint y);

    void findConTours(); //找到连通域
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_pushButton_11_clicked();

    void on_Btn_Save_clicked();

    void on_Btn_SaveFile_clicked();

    void on_Btn_SaveOther_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_Btn_SetCir_clicked();

    void on_Btn_HuaYuan_clicked();

    void on_Btn_CirNewChosse_clicked(); //新圆选

    void NewCirChosee(QString PicImageName, QPoint CirP, int Pinum,int stax,int stay,int endx,int endy);  // 新选法
    void on_pushButton_12_clicked();

    void on_Btn_Remove_2_clicked();

    void on_Btn_Remove_clicked();

    void on_Btn_DeAll_clicked();

    void on_Btn_DeAll_2_clicked();

private:
    Ui::MainWindow *ui;

    bool treeisclear;
    bool tree2isclear;

    static MainWindow *myClassA;     //它在内存中只占一份空间
    QLabel *cirLabel;
    QStandardItemModel *model;
    QStandardItemModel *model_2;
    QString FangDafilename;     //放大前文件
    QString FangDafilenameNew;  //放大后文件

    QString ReleaseFileName;  //按下后 打开的文件

    QString OldFilename;
    QString CurrentFilePath; //当前文件路径
    QStringList SaveDate;
    MouseSize *form;
    int MouseChose;
    bool ReleaseIsEnt;
    bool LineIsshow;


    int GrayNum;
    int BinarizationNum;
    int LinearStrengthNum;
    int LinearLengthNum;
    int LinearIntervalLengthNum;

    int MinHcir;
    int CirH;
    int CirL;
    int Mincir;
    int Maxcir;

    double pointRect_x;
    double pointRect_y;
    QPointF _ptStart;//线段的起点
    QPointF _ptEnd;//线段的终点

    bool ZoomIsTrue;  // 是否放大

    QString WorkImage; // 工作区域的图片
    bool WorkImageIsOk;
    bool GetWorkImageSize; // 得到工作区域大小
    cv::Mat Work_LineQCImage;   // 首先直线被切除后的工作区

    QString CirXp;   // 当前圆的点击后x的值
    QString CirYp;   // 当前圆 点击后y的点

    int FangDapicX;   // 当前圆的点击后x的值
    int FangDapicY;   // 当前圆 点击后y的点
    bool CirFangDA;    // cir 放大
    int pressThreeP; // 选中三个点
    QPoint pointpress1;  //  1  2 3dian1
    QPoint pointpress2;
    QPoint pointpress3;
    QStringList pointBlack;

    int HeightThisForm;  // 显示的高度
    int widthThisForm;  // 显示的宽度

    QVector<QPoint> vectLineXPoint;  // 线的x点
    QVector<QPoint> vectLineYPoint;  // 线的y点

    QVector<QPoint> VectCirPoint;  // 圆的点 vector
    QVector<double> cirPi;    // 圆的半径 直径
    int OpenImageheight;
    int OpenImagewidth;  // 得到保存后的图片的大小

    // 另存为文件打开后
    int OpenImageheightLing;
    int OpenImagewidthLing;  // 得到保存后的图片的大小
    QString TxtFilename;

   // HI_ImageBox m_imageBox;
};

#endif // MAINWINDOW_H
