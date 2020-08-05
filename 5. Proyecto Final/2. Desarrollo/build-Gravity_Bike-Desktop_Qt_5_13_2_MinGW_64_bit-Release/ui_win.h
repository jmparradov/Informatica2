/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_win
{
public:
    QPushButton *restartbutton;
    QPushButton *menubutton;
    QPushButton *loadgamebutton;
    QLabel *label;

    void setupUi(QWidget *win)
    {
        if (win->objectName().isEmpty())
            win->setObjectName(QString::fromUtf8("win"));
        win->resize(763, 585);
        restartbutton = new QPushButton(win);
        restartbutton->setObjectName(QString::fromUtf8("restartbutton"));
        restartbutton->setGeometry(QRect(290, 210, 181, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        restartbutton->setFont(font);
        menubutton = new QPushButton(win);
        menubutton->setObjectName(QString::fromUtf8("menubutton"));
        menubutton->setGeometry(QRect(290, 290, 181, 41));
        menubutton->setFont(font);
        loadgamebutton = new QPushButton(win);
        loadgamebutton->setObjectName(QString::fromUtf8("loadgamebutton"));
        loadgamebutton->setGeometry(QRect(290, 370, 181, 41));
        loadgamebutton->setFont(font);
        label = new QLabel(win);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 50, 471, 101));

        retranslateUi(win);

        QMetaObject::connectSlotsByName(win);
    } // setupUi

    void retranslateUi(QWidget *win)
    {
        win->setWindowTitle(QCoreApplication::translate("win", "Form", nullptr));
        restartbutton->setText(QCoreApplication::translate("win", "Play again", nullptr));
        menubutton->setText(QCoreApplication::translate("win", "Menu", nullptr));
        loadgamebutton->setText(QCoreApplication::translate("win", "Load Game", nullptr));
        label->setText(QCoreApplication::translate("win", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; color:#f8f8f8;\">Player 1 Wins</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class win: public Ui_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
