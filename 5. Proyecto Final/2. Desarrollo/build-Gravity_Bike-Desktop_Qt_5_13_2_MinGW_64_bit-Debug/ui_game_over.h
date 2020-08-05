/********************************************************************************
** Form generated from reading UI file 'game_over.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_H
#define UI_GAME_OVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_over
{
public:
    QPushButton *restartbutton;
    QPushButton *loadbutton;
    QPushButton *menubutton;

    void setupUi(QWidget *game_over)
    {
        if (game_over->objectName().isEmpty())
            game_over->setObjectName(QString::fromUtf8("game_over"));
        game_over->resize(565, 340);
        restartbutton = new QPushButton(game_over);
        restartbutton->setObjectName(QString::fromUtf8("restartbutton"));
        restartbutton->setGeometry(QRect(210, 80, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        restartbutton->setFont(font);
        loadbutton = new QPushButton(game_over);
        loadbutton->setObjectName(QString::fromUtf8("loadbutton"));
        loadbutton->setGeometry(QRect(210, 150, 121, 31));
        loadbutton->setFont(font);
        menubutton = new QPushButton(game_over);
        menubutton->setObjectName(QString::fromUtf8("menubutton"));
        menubutton->setGeometry(QRect(210, 220, 121, 31));
        menubutton->setFont(font);

        retranslateUi(game_over);

        QMetaObject::connectSlotsByName(game_over);
    } // setupUi

    void retranslateUi(QWidget *game_over)
    {
        game_over->setWindowTitle(QCoreApplication::translate("game_over", "Form", nullptr));
        restartbutton->setText(QCoreApplication::translate("game_over", "Restart", nullptr));
        loadbutton->setText(QCoreApplication::translate("game_over", "Load Game", nullptr));
        menubutton->setText(QCoreApplication::translate("game_over", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_over: public Ui_game_over {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_H
