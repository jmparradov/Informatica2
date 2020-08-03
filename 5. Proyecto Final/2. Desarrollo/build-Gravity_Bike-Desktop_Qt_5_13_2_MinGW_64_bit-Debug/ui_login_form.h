/********************************************************************************
** Form generated from reading UI file 'login_form.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FORM_H
#define UI_LOGIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_form
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *LoginButton;
    QLineEdit *username_input;
    QLineEdit *password_input;

    void setupUi(QWidget *login_form)
    {
        if (login_form->objectName().isEmpty())
            login_form->setObjectName(QString::fromUtf8("login_form"));
        login_form->resize(1244, 649);
        groupBox = new QGroupBox(login_form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(720, 250, 431, 291));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 71, 31));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 160, 81, 31));
        label_3->setFont(font);
        LoginButton = new QPushButton(groupBox);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(160, 230, 121, 31));
        username_input = new QLineEdit(groupBox);
        username_input->setObjectName(QString::fromUtf8("username_input"));
        username_input->setGeometry(QRect(170, 110, 171, 21));
        password_input = new QLineEdit(groupBox);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setGeometry(QRect(170, 160, 171, 21));

        retranslateUi(login_form);

        QMetaObject::connectSlotsByName(login_form);
    } // setupUi

    void retranslateUi(QWidget *login_form)
    {
        login_form->setWindowTitle(QCoreApplication::translate("login_form", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("login_form", "<html><head/><body><p align=\"center\">Log in</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("login_form", "<html><head/><body><p><span style=\" font-size:12pt;\">Username</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("login_form", "<html><head/><body><p><span style=\" font-size:12pt;\">Password</span></p></body></html>", nullptr));
        LoginButton->setText(QCoreApplication::translate("login_form", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_form: public Ui_login_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FORM_H
