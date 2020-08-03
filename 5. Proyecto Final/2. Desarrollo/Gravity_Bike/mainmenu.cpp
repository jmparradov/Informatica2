#include "mainmenu.h"
#include "createuser.h"
#include "ui_mainmenu.h"
#include "login_form.h"

mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_CreateUserButton_clicked()
{
    this->close();
    createuser *ww = new createuser();
    ww->show();

}

void mainmenu::on_LoginButton_clicked()
{
    qDebug() << "Log in";
    this->close();
    login_form *ww = new login_form();
    ww->show();
}

void mainmenu::on_HowToButton_clicked()
{
    qDebug() << "How to";
}
