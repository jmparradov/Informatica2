#include "mainwindow.h"
#include "ui_win.h"
#include "game_options.h"

win::win(QMainWindow *mainW_s, int n_player, QString difficult_s, QString world_s, int  players_s) : ui(new Ui::win)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/win.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QRect geo = this->geometry();
    this->setFixedSize(geo.width(),geo.height());
    mainW =mainW_s;
    player = n_player;
    difficult = difficult_s;
    world = world_s;
    players =  players_s;
}

win::~win()
{
    delete ui;
}

void win::on_restartbutton_clicked()
{
    this->close();
    mainW->close();

    MainWindow *ww = new MainWindow(difficult, world,players);
    ww->show();
}

void win::on_menubutton_clicked()
{
    this->close();
    mainW->close();

    game_options *ww = new game_options();
    ww->show();
}

void win::on_loadgamebutton_clicked()
{
    this->close();
    mainW->close();

    load *ww = new load();
    ww->show();
}
