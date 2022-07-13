#include "mainwindow.h"
#include <QApplication>
#include "mousesize.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //MouseSize w;
    w.show();

    return a.exec();
}
