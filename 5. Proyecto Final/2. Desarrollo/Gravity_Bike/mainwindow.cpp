#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "road.h"
#include "QMovie"
#include "QLabel"

#define scenex 1300
#define sceney  600

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();

    // Insert background
    QPixmap pim("../Gravity_Bike/sources/night_city.png");
    bool loaded = pim.load("../Gravity_Bike/sources/night_city.png");

    if (loaded){
        scene->setBackgroundBrush(pim); }
    else {
         qDebug() << "bk image not laoded";
    }


    // insert road
    road *item  = new road();
    scene->addItem(item);


    // insert character
    character *biker  = new character();
    scene->addItem(biker);



    //scene->addItem(g_item)       // body


    //Add View and define its characteristics
    QGraphicsView * view = new QGraphicsView(scene);
    scene->setSceneRect(0,0,scenex,sceney);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(scenex,sceney);
    view->maximumSize();
    view->show();
    //view->centerOn(rects.at(0)->x(),rects.at(0)->y());
}

MainWindow::~MainWindow()
{
    delete ui;
}
