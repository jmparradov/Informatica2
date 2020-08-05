/********************************************************************************
** Form generated from reading UI file 'load.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_H
#define UI_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_load
{
public:
    QListWidget *SavedList;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *backbutton;

    void setupUi(QWidget *load)
    {
        if (load->objectName().isEmpty())
            load->setObjectName(QString::fromUtf8("load"));
        load->resize(937, 536);
        SavedList = new QListWidget(load);
        SavedList->setObjectName(QString::fromUtf8("SavedList"));
        SavedList->setGeometry(QRect(510, 190, 361, 231));
        label = new QLabel(load);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(510, 150, 111, 31));
        pushButton = new QPushButton(load);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(770, 470, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        backbutton = new QPushButton(load);
        backbutton->setObjectName(QString::fromUtf8("backbutton"));
        backbutton->setGeometry(QRect(30, 470, 101, 31));
        backbutton->setFont(font);

        retranslateUi(load);

        QMetaObject::connectSlotsByName(load);
    } // setupUi

    void retranslateUi(QWidget *load)
    {
        load->setWindowTitle(QCoreApplication::translate("load", "Form", nullptr));
        label->setText(QCoreApplication::translate("load", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#550000;\">Load Game</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("load", "Load", nullptr));
        backbutton->setText(QCoreApplication::translate("load", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class load: public Ui_load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_H
