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

    QRect geo = this->geometry();
    this->setFixedSize(geo.width(),geo.height());

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

    this->close();
    mainW->close();

    MainWindow *ww = new MainWindow(difficult, world,players);
    ww->show();
}

void game_over::on_loadbutton_clicked()
{
    this->close();
    mainW->close();

    load *ww = new load();
    ww->show();
}

void game_over::on_menubutton_clicked()
{
    mainW->close();
    this->close();
    game_options *ww = new game_options();
    ww->show();
}
