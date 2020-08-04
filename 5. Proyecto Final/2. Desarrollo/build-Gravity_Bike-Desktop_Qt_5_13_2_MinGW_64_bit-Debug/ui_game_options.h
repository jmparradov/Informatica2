/********************************************************************************
** Form generated from reading UI file 'game_options.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OPTIONS_H
#define UI_GAME_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_options
{
public:
    QGroupBox *groupBox;
    QWidget *picture2;
    QWidget *picture3;
    QWidget *picture1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *world1;
    QRadioButton *world2;
    QRadioButton *world3;
    QGroupBox *groupBox_2;
    QRadioButton *normal;
    QRadioButton *amateur;
    QRadioButton *leyend;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *playbutton;
    QPushButton *backbutton;

    void setupUi(QWidget *game_options)
    {
        if (game_options->objectName().isEmpty())
            game_options->setObjectName(QString::fromUtf8("game_options"));
        game_options->resize(1298, 676);
        groupBox = new QGroupBox(game_options);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(700, 220, 501, 181));
        picture2 = new QWidget(groupBox);
        picture2->setObjectName(QString::fromUtf8("picture2"));
        picture2->setGeometry(QRect(190, 60, 120, 80));
        picture3 = new QWidget(groupBox);
        picture3->setObjectName(QString::fromUtf8("picture3"));
        picture3->setGeometry(QRect(350, 60, 120, 80));
        picture1 = new QWidget(groupBox);
        picture1->setObjectName(QString::fromUtf8("picture1"));
        picture1->setGeometry(QRect(30, 60, 120, 80));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 30, 101, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 30, 101, 16));
        world1 = new QRadioButton(groupBox);
        world1->setObjectName(QString::fromUtf8("world1"));
        world1->setGeometry(QRect(80, 150, 16, 17));
        world2 = new QRadioButton(groupBox);
        world2->setObjectName(QString::fromUtf8("world2"));
        world2->setGeometry(QRect(240, 150, 16, 17));
        world3 = new QRadioButton(groupBox);
        world3->setObjectName(QString::fromUtf8("world3"));
        world3->setGeometry(QRect(410, 150, 16, 17));
        groupBox_2 = new QGroupBox(game_options);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(700, 420, 501, 171));
        normal = new QRadioButton(groupBox_2);
        normal->setObjectName(QString::fromUtf8("normal"));
        normal->setGeometry(QRect(250, 70, 16, 17));
        amateur = new QRadioButton(groupBox_2);
        amateur->setObjectName(QString::fromUtf8("amateur"));
        amateur->setGeometry(QRect(90, 70, 16, 17));
        leyend = new QRadioButton(groupBox_2);
        leyend->setObjectName(QString::fromUtf8("leyend"));
        leyend->setGeometry(QRect(400, 70, 16, 17));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 40, 101, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 40, 101, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 30, 101, 31));
        playbutton = new QPushButton(groupBox_2);
        playbutton->setObjectName(QString::fromUtf8("playbutton"));
        playbutton->setGeometry(QRect(380, 120, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        playbutton->setFont(font);
        backbutton = new QPushButton(groupBox_2);
        backbutton->setObjectName(QString::fromUtf8("backbutton"));
        backbutton->setGeometry(QRect(50, 120, 81, 31));
        backbutton->setFont(font);

        retranslateUi(game_options);

        QMetaObject::connectSlotsByName(game_options);
    } // setupUi

    void retranslateUi(QWidget *game_options)
    {
        game_options->setWindowTitle(QCoreApplication::translate("game_options", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#550000;\">Montains</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#550000;\">Montains</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Montains</span></p></body></html>", nullptr));
        world1->setText(QString());
        world2->setText(QString());
        world3->setText(QString());
        groupBox_2->setTitle(QString());
        normal->setText(QString());
        amateur->setText(QString());
        leyend->setText(QString());
        label_4->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#00ff00;\">Amateur</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ffff00;\">Normal</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("game_options", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">Leyend</span></p></body></html>", nullptr));
        playbutton->setText(QCoreApplication::translate("game_options", "Play", nullptr));
        backbutton->setText(QCoreApplication::translate("game_options", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_options: public Ui_game_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OPTIONS_H
