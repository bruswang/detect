/********************************************************************************
** Form generated from reading UI file 'mousesize.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSESIZE_H
#define UI_MOUSESIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseSize
{
public:
    QLabel *label_29;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QWidget *MouseSize)
    {
        if (MouseSize->objectName().isEmpty())
            MouseSize->setObjectName(QStringLiteral("MouseSize"));
        MouseSize->resize(1531, 701);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MouseSize->sizePolicy().hasHeightForWidth());
        MouseSize->setSizePolicy(sizePolicy);
        MouseSize->setMinimumSize(QSize(1531, 701));
        MouseSize->setMaximumSize(QSize(1531, 701));
        label_29 = new QLabel(MouseSize);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(30, 10, 81, 31));
        label_29->setStyleSheet(QLatin1String("font-family: PingFang SC;\n"
"font-style: normal;\n"
"font-weight: normal;\n"
"font-size: 16px;\n"
"line-height: 22px;\n"
"\n"
"color: #333333;"));
        label_29->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(MouseSize);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 10, 191, 31));
        comboBox_2 = new QComboBox(MouseSize);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 10, 71, 31));

        retranslateUi(MouseSize);

        QMetaObject::connectSlotsByName(MouseSize);
    } // setupUi

    void retranslateUi(QWidget *MouseSize)
    {
        MouseSize->setWindowTitle(QApplication::translate("MouseSize", "Form", Q_NULLPTR));
        label_29->setText(QApplication::translate("MouseSize", "\351\200\211\345\214\272\345\215\212\345\276\204", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MouseSize", "\345\234\206\345\275\242", Q_NULLPTR)
         << QApplication::translate("MouseSize", "\346\255\243\346\226\271\345\275\242", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MouseSize: public Ui_MouseSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSESIZE_H
