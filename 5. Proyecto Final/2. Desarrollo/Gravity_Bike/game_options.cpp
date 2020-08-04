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

    QPixmap sample1(":/sources/worlds/sample1.png");
    sample1 = sample1.scaled(ui->picture1->size(), Qt::IgnoreAspectRatio);
    QPalette palette_s1;
    palette_s1.setBrush(QPalette::Background, sample1);
    ui->picture1->setPalette(palette_s1);
    ui->picture1->show();

    QPixmap sample2(":/sources/worlds/sample2.png");
    sample2 = sample2.scaled(ui->picture2->size(), Qt::IgnoreAspectRatio);
    QPalette palette_s2;
    palette_s2.setBrush(QPalette::Background, sample2);
    ui->picture2->setPalette(palette_s2);
    ui->picture3->show();

    QPixmap sample3(":/sources/worlds/sample3.png");
    sample3 = sample3.scaled(ui->picture3->size(), Qt::IgnoreAspectRatio);
    QPalette palette_s3;
    palette_s3.setBrush(QPalette::Background, sample3);
    ui->picture3->setPalette(palette_s3);
    ui->picture3->show();
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
    QString difficult = "NA";
    QString world = "NA";
    int players = 0;

    if(ui->world1->isChecked()){
        world = "montains";
    }

    if(ui->world2->isChecked()){
        world = "desert";
    }

    if(ui->world3->isChecked()){
        world = "acid";
    }

    if (ui->amateur->isChecked()){
        difficult = "amateur";
    }

    if (ui->normal->isChecked()){
        difficult = "normal";
    }

    if (ui->leyend->isChecked()){
        difficult = "leyend";
    }

    if (ui->player1->isChecked()){
        players = 1;
    }

    if (ui->player2->isChecked()){
        players = 2;
    }

    if (difficult == "NA" || world == "NA" || players == 0){

    }
    else{
        this->close();
        MainWindow *ww = new MainWindow(difficult, world,players);
        ww->show();
    }
}
