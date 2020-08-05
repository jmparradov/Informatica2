/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainmenu
{
public:
    QGroupBox *groupBox;
    QPushButton *CreateUserButton;
    QPushButton *LoginButton;
    QPushButton *HowToButton;

    void setupUi(QWidget *mainmenu)
    {
        if (mainmenu->objectName().isEmpty())
            mainmenu->setObjectName(QString::fromUtf8("mainmenu"));
        mainmenu->resize(1212, 655);
        groupBox = new QGroupBox(mainmenu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(750, 250, 301, 211));
        CreateUserButton = new QPushButton(groupBox);
        CreateUserButton->setObjectName(QString::fromUtf8("CreateUserButton"));
        CreateUserButton->setGeometry(QRect(80, 30, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        CreateUserButton->setFont(font);
        LoginButton = new QPushButton(groupBox);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(80, 90, 141, 31));
        LoginButton->setFont(font);
        HowToButton = new QPushButton(groupBox);
        HowToButton->setObjectName(QString::fromUtf8("HowToButton"));
        HowToButton->setGeometry(QRect(80, 150, 141, 31));
        HowToButton->setFont(font);
        HowToButton->setCursor(QCursor(Qt::ArrowCursor));

        retranslateUi(mainmenu);

        QMetaObject::connectSlotsByName(mainmenu);
    } // setupUi

    void retranslateUi(QWidget *mainmenu)
    {
        mainmenu->setWindowTitle(QCoreApplication::translate("mainmenu", "Gravity Bike", nullptr));
        groupBox->setTitle(QString());
        CreateUserButton->setText(QCoreApplication::translate("mainmenu", "Create New User", nullptr));
        LoginButton->setText(QCoreApplication::translate("mainmenu", "Log in", nullptr));
        HowToButton->setText(QCoreApplication::translate("mainmenu", "How to play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainmenu: public Ui_mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
