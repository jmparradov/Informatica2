#include "mainwindow.h"
#include "game_options.h"
#include "ui_game_over.h"

game_over::game_over(QString difficult_i, QString world_i, int  players_i, QMainWindow *mainW_s) :ui(new Ui::game_over)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/falling.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    difficult = difficult_i;
    world = world_i;
    players = players_i;
    mainW = mainW_s;
}

game_over::~game_over()
{
    delete ui;
}

void game_over::on_restartbutton_clicked()
{
    qDebug() << "1";
    this->close();
    qDebug() << "2";
    mainW->close();
    qDebug() << "3";

    MainWindow *ww = new MainWindow(difficult, world,players);
    qDebug() << "4";
    ww->show();
    qDebug() << "5";
}

void game_over::on_loadbutton_clicked()
{

}

void game_over::on_menubutton_clicked()
{
    mainW->close();
    this->close();
    game_options *ww = new game_options();
    ww->show();
}
