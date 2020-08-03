#include "game_options.h"
#include "ui_game_options.h"

game_options::game_options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_options)
{
    ui->setupUi(this);
}

game_options::~game_options()
{
    delete ui;
}
