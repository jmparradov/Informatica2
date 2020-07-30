#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "road.h"
#include "biker.h"
#include "QMovie"
#include "QLabel"

#define scenex 1300
#define sceney  600

#define worldx 15024
#define worldy 6736

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();

    // Insert background
    QPixmap pim("../Gravity_Bike/sources/test1.png");
    bool loaded = pim.load("../Gravity_Bike/sources/world1.png");

    if (loaded){
        scene->setBackgroundBrush(pim); }
    else {
         qDebug() << "bk image not laoded";
    }


    // insert road
    road *sect1  = new road(0,0,0,600,500,0,scenex, sceney, 1);
    road *sect2  = new road(scenex,sceney,1600,900,2600,800,3000,1500, 2);
    road *sect3  = new road(3000,1500,3300,2000,4200,2200,4600,2000, 3);
    road *sect4  = new road(4600,2000,4710,1953,5038,2700,6000,2630, 4);
    road *sect5  = new road(6000,2630,6369,2650,7200,3000,7600,3161, 5);
    road *sect6  = new road(7600,3161,7853,3301,8277,3916,9348,3954, 6);
    road *sect7  = new road(9348,3954,9664,3982,10761,4818,11185,5292, 7);
    road *sect8  = new road(11185,5292,11554,5833,12102,6627,12584,6383, 8);
    road *sect9  = new road(12867,6367,13168,6419,13532,6711,14078,6715, 9);
    road *sect10  = new road(14078,6715,14488,6638,14746,6597,worldx,worldy, 10);


    scene->addItem(sect1);
    scene->addItem(sect2);
    scene->addItem(sect3);
    scene->addItem(sect4);
    scene->addItem(sect5);
    scene->addItem(sect6);
    scene->addItem(sect7);
    scene->addItem(sect8);
    scene->addItem(sect9);
    scene->addItem(sect10);


    //Player 1
    biker * star = new biker();
    scene->addItem(star);


    //Add View and define its characteristics
    QGraphicsView * view = new QGraphicsView(scene);
    scene->setSceneRect(0,0,worldx,worldy);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->resize(scenex,sceney);
    //view->setFixedSize(scenex,sceney);
    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

