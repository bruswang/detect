#-------------------------------------------------
#
# Project created by QtCreator 2022-03-09T14:56:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = line
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mousesize.cpp #\
#    streewidgetitem.cpp \
#    tooltreewidgetitem.cpp \
#    droptreewidget.cpp \
#    dragtreewidget.cpp

HEADERS  += mainwindow.h \
    mousesize.h #\
#    droptreewidget.h \
#    streewidgetitem.h \
#    tooltreewidgetitem.h \
#    dragtreewidget.h

FORMS    += mainwindow.ui \
    mousesize.ui
win32{

    contains(QT_ARCH, i386) {
        message("32-bit")
        INCLUDEPATH += D:\work\opencv\build\include  \
                       D:\work\opencv\build\include


    } else {
        message("64-bit")
        INCLUDEPATH += D:\work\opencv\build\include  \
                       D:\work\opencv\build\include

    }

}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lopencv_ts300
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lopencv_ts300d

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lopencv_ts300
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lopencv_ts300d

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lopencv_world300
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lopencv_world300d
else:unix: LIBS += -L$$PWD/./ -lopencv_world300

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lopencv_world300
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lopencv_world300d
else:unix: LIBS += -L$$PWD/./ -lopencv_world300



INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


RESOURCES += \
    qrc.qrc

#win32: LIBS += -L$$PWD/QtPicT/release/ -lHI_ImageBox1
win32::LIBS += -luser32

INCLUDEPATH += $$PWD/QtPicT/release
DEPENDPATH += $$PWD/QtPicT/release
