/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createuser
{
public:
    QGroupBox *groupBox;
    QLineEdit *username_input;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *password_input;
    QPushButton *addUserButton;
    QLabel *label_3;

    void setupUi(QWidget *createuser)
    {
        if (createuser->objectName().isEmpty())
            createuser->setObjectName(QString::fromUtf8("createuser"));
        createuser->resize(1245, 651);
        groupBox = new QGroupBox(createuser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(690, 270, 451, 261));
        username_input = new QLineEdit(groupBox);
        username_input->setObjectName(QString::fromUtf8("username_input"));
        username_input->setGeometry(QRect(190, 90, 211, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(46, 90, 131, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 91, 21));
        password_input = new QLineEdit(groupBox);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setGeometry(QRect(190, 150, 211, 21));
        addUserButton = new QPushButton(groupBox);
        addUserButton->setObjectName(QString::fromUtf8("addUserButton"));
        addUserButton->setGeometry(QRect(160, 200, 141, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 30, 131, 31));

        retranslateUi(createuser);

        QMetaObject::connectSlotsByName(createuser);
    } // setupUi

    void retranslateUi(QWidget *createuser)
    {
        createuser->setWindowTitle(QCoreApplication::translate("createuser", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("createuser", "<html><head/><body><p><span style=\" font-size:12pt;\">User Name</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("createuser", "<html><head/><body><p><span style=\" font-size:12pt;\">Password</span></p></body></html>", nullptr));
        addUserButton->setText(QCoreApplication::translate("createuser", "Add User", nullptr));
        label_3->setText(QCoreApplication::translate("createuser", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">New User</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createuser: public Ui_createuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
