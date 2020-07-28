#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "road.h"
#include "wheel.h"
#include "QMovie"
#include "QLabel"

#define scenex 1300
#define sceney  600

#define worldx 1300*4
#define worldy  600*4

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();

    // Insert background
    QPixmap pim("../Gravity_Bike/sources/night_city.png");
    bool loaded = pim.load("../Gravity_Bike/sources/test1.png");

    if (loaded){
        scene->setBackgroundBrush(pim); }
    else {
         qDebug() << "bk image not laoded";
    }


    // insert road
    road *sect1  = new road(0,0,0,600,500,0,scenex, sceney);
    road *sect2  = new road(1300,600,1600,900,2600,800,3000,1500);

    scene->addItem(sect1);
    scene->addItem(sect2);


    // insert character
    //character *biker  = new character();
    //scene->addItem(biker);

    //Testing
    wheel * star = new wheel();
    scene->addItem(star);

    //scene->addItem(g_item)       // body


    //Add View and define its characteristics
    QGraphicsView * view = new QGraphicsView(scene);
    scene->setSceneRect(0,0,worldx,worldy);
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->resize(scenex,sceney);
    //view->setFixedSize(scenex,sceney);
    view->show();
    //view->centerOn(rects.at(0)->x(),rects.at(0)->y());
}

MainWindow::~MainWindow()
{
    delete ui;
}

