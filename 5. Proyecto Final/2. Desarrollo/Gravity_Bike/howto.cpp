#include "mainmenu.h"
#include "ui_howto.h"

Howto::Howto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Howto)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/howto.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QRect geo = this->geometry();
    this->setFixedSize(geo.width(),geo.height());
}

Howto::~Howto()
{
    delete ui;
}

void Howto::on_backbutton_clicked()
{
    this->close();
    mainmenu *ww = new mainmenu();
    ww->show();
}
