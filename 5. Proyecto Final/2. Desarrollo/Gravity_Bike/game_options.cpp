#include "login_form.h"
#include "ui_game_options.h"
#include "mainwindow.h"

game_options::game_options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_options)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

game_options::~game_options()
{
    delete ui;
}

void game_options::on_backbutton_clicked()
{
    this->close();
    login_form *ww = new login_form();
    ww->show();

}

void game_options::on_playbutton_clicked()
{
    if(ui->world1->isChecked() && ui->normal->isChecked()){
        this->close();
        MainWindow *ww = new MainWindow();
        ww->show();
    }
}
