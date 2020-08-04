#include "pause.h"
#include "ui_pause.h"

pause::pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pause)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/pause.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

pause::~pause()
{
    delete ui;
}

void pause::on_continuebutton_clicked()
{
    this->close();

}

void pause::on_savebutton_clicked()
{

}

void pause::on_loadbutton_clicked()
{

}

void pause::on_exitbutton_clicked()
{

}
