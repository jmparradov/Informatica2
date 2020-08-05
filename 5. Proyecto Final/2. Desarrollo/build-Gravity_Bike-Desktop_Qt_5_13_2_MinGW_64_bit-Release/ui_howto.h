/********************************************************************************
** Form generated from reading UI file 'howto.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTO_H
#define UI_HOWTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Howto
{
public:
    QPushButton *backbutton;

    void setupUi(QWidget *Howto)
    {
        if (Howto->objectName().isEmpty())
            Howto->setObjectName(QString::fromUtf8("Howto"));
        Howto->resize(1214, 659);
        backbutton = new QPushButton(Howto);
        backbutton->setObjectName(QString::fromUtf8("backbutton"));
        backbutton->setGeometry(QRect(1030, 590, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        backbutton->setFont(font);

        retranslateUi(Howto);

        QMetaObject::connectSlotsByName(Howto);
    } // setupUi

    void retranslateUi(QWidget *Howto)
    {
        Howto->setWindowTitle(QCoreApplication::translate("Howto", "Form", nullptr));
        backbutton->setText(QCoreApplication::translate("Howto", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Howto: public Ui_Howto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTO_H
