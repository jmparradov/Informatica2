/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pause
{
public:
    QPushButton *continuebutton;
    QPushButton *savebutton;
    QPushButton *loadbutton;
    QPushButton *exitbutton;

    void setupUi(QWidget *pause)
    {
        if (pause->objectName().isEmpty())
            pause->setObjectName(QString::fromUtf8("pause"));
        pause->resize(462, 368);
        continuebutton = new QPushButton(pause);
        continuebutton->setObjectName(QString::fromUtf8("continuebutton"));
        continuebutton->setGeometry(QRect(160, 130, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        continuebutton->setFont(font);
        savebutton = new QPushButton(pause);
        savebutton->setObjectName(QString::fromUtf8("savebutton"));
        savebutton->setGeometry(QRect(160, 180, 121, 31));
        savebutton->setFont(font);
        loadbutton = new QPushButton(pause);
        loadbutton->setObjectName(QString::fromUtf8("loadbutton"));
        loadbutton->setGeometry(QRect(160, 220, 121, 31));
        loadbutton->setFont(font);
        exitbutton = new QPushButton(pause);
        exitbutton->setObjectName(QString::fromUtf8("exitbutton"));
        exitbutton->setGeometry(QRect(160, 280, 121, 31));
        exitbutton->setFont(font);

        retranslateUi(pause);

        QMetaObject::connectSlotsByName(pause);
    } // setupUi

    void retranslateUi(QWidget *pause)
    {
        pause->setWindowTitle(QCoreApplication::translate("pause", "Form", nullptr));
        continuebutton->setText(QCoreApplication::translate("pause", "Continue", nullptr));
        savebutton->setText(QCoreApplication::translate("pause", "Save", nullptr));
        loadbutton->setText(QCoreApplication::translate("pause", "Load", nullptr));
        exitbutton->setText(QCoreApplication::translate("pause", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pause: public Ui_pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
