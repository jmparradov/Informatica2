#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "road.h"
#include "biker.h"
#include "obstacle.h"
#include "QMovie"
#include "QLabel"

#define scenex 1300
#define sceney  600

#define worldx 15024
#define worldy 6736

#define PI 3.14159265

MainWindow::MainWindow(QString difficult, QString world, int  players, double x1, double y1,
                       double x2, double y2, double v01, double v02):ui(new Ui::MainWindow){
    ui->setupUi(this);
    view->setScene(scene);

    // Insert background

    if (world == "montains"){
        QPixmap pim(":/sources/worlds/world1A.png");
        bool loaded = pim.load(":/sources/worlds/world1A.png");
        if (loaded){
            scene->setBackgroundBrush(pim);}
        else {
             qDebug() << "bk image not laoded";
        }
    }

    if (world == "desert"){
        QPixmap pim(":/sources/worlds/world2.png");
        bool loaded = pim.load(":/sources/worlds/world2.png");
        if (loaded){
            scene->setBackgroundBrush(pim);}
        else {
             qDebug() << "bk image not laoded";
        }
    }


    if (world == "acid"){
        QPixmap pim(":/sources/worlds/world3.png");
        bool loaded = pim.load(":/sources/worlds/world3.png");
        if (loaded){
            scene->setBackgroundBrush(pim);}
        else {
             qDebug() << "bk image not laoded";
        }
    }


    // insert road for all worlds
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

    // set up lines world
    set_up();

    //Player 1
    biker * player1 = new biker(lines, difficult, world, players, this, 1,x1,y1,v01);
    scene->addItem(player1);

    if (players == 2){
        biker * player2 = new biker(lines, difficult, world, players, this, 2,x2,y2,v02);
        scene->addItem(player2);
    }

    // insert obstacles
    obstacle *barrel1  = new obstacle(lines, 0.1, "bush1");
    scene->addItem(barrel1);

    obstacle *barrel2  = new obstacle(lines, 0.2, "barrel");
    scene->addItem(barrel2);

    obstacle *brush1  = new obstacle(lines, 0.25, "barrel");
    scene->addItem(brush1);

    obstacle *rock1  = new obstacle(lines, 0.33, "rock3");
    scene->addItem(rock1);

    obstacle *rock2  = new obstacle(lines, 0.48, "rock1");
    scene->addItem(rock2);

    obstacle *rock3  = new obstacle(lines, 0.06, "rock2");
    scene->addItem(rock3);

    obstacle *brush2  = new obstacle(lines, 0.4, "bush1");
    scene->addItem(brush2);

    obstacle *brush3  = new obstacle(lines, 0.5, "bush1");
    scene->addItem(brush3);

    obstacle *brush4  = new obstacle(lines, 0.6, "bush1");
    scene->addItem(brush4);

    obstacle *brush5  = new obstacle(lines, 0.7, "bush1");
    scene->addItem(brush5);

    obstacle *brush6  = new obstacle(lines, 0.8, "bush1");
    scene->addItem(brush6);

    obstacle *brush7  = new obstacle(lines, 0.9, "bush1");
    scene->addItem(brush7);

    obstacle *wood1  = new obstacle(lines, 0.12, "wood");
    scene->addItem(wood1);

    if (difficult == "normal"){

        obstacle *barrel2  = new obstacle(lines, 0.24, "barrel");
        scene->addItem(barrel2);

        obstacle *brush1  = new obstacle(lines, 0.3, "barrel");
        scene->addItem(brush1);

        obstacle *rock1  = new obstacle(lines, 0.35, "rock3");
        scene->addItem(rock1);

        obstacle *rock2  = new obstacle(lines, 0.6, "rock1");
        scene->addItem(rock2);

        obstacle *rock3  = new obstacle(lines, 0.06, "rock2");
        scene->addItem(rock3);

        obstacle *brush3  = new obstacle(lines, 0.54, "bush1");
        scene->addItem(brush3);

        obstacle *brush4  = new obstacle(lines, 0.65, "bush1");
        scene->addItem(brush4);

        obstacle *brush5  = new obstacle(lines, 0.79, "bush1");
        scene->addItem(brush5);

        obstacle *brush6  = new obstacle(lines, 0.95, "bush1");
        scene->addItem(brush6);

        obstacle *brush7  = new obstacle(lines, 0.94, "bush1");
        scene->addItem(brush7);

    }

    if (difficult == "leyend"){
        obstacle *barrel1  = new obstacle(lines, 0.24, "bush1");
        scene->addItem(barrel1);

        obstacle *barrel2  = new obstacle(lines, 0.34, "barrel");
        scene->addItem(barrel2);

        obstacle *brush1  = new obstacle(lines, 0.45, "barrel");
        scene->addItem(brush1);

        obstacle *rock1  = new obstacle(lines, 0.49, "rock3");
        scene->addItem(rock1);

        obstacle *rock2  = new obstacle(lines, 0.75, "rock1");
        scene->addItem(rock2);

        obstacle *rock3  = new obstacle(lines, 0.16, "rock2");
        scene->addItem(rock3);

        obstacle *brush2  = new obstacle(lines, 0.23, "bush1");
        scene->addItem(brush2);

        obstacle *brush3  = new obstacle(lines, 0.64, "bush1");
        scene->addItem(brush3);

        obstacle *wood1  = new obstacle(lines, 0.83, "wood");
        scene->addItem(wood1);
    }

    //Add View and define its characteristics
    scene->setSceneRect(0,0,worldx,worldy);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->resize(scenex,sceney);
    this->resize(scenex,sceney);
    view->setFixedSize(scenex,sceney);
    view->show();

}

void MainWindow::set_up(){

    foreach(QGraphicsItem *item, scene->items()){
        if (item->type() == 65536){//road::Type){
            int xp0 = qgraphicsitem_cast<road*>(item)->xp0;
            int yp0 = qgraphicsitem_cast<road*>(item)->yp0;

            int xp1 = qgraphicsitem_cast<road*>(item)->xp1;
            int yp1 = qgraphicsitem_cast<road*>(item)->yp1;

            int xp2 = qgraphicsitem_cast<road*>(item)->xp2;
            int yp2 = qgraphicsitem_cast<road*>(item)->yp2;

            int xp3 = qgraphicsitem_cast<road*>(item)->xp3;
            int yp3 = qgraphicsitem_cast<road*>(item)->yp3;


            field(xp0,yp0,xp1,yp1,xp2,yp2,xp3,yp3);

        }
    }
}

void MainWindow::field(int xp0, int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3){

    for(int i = 0;i<=100;i++){

        double tt = i*(1e-2);
        double t_1 = (i-1)*(1e-2);
        double t1 = (i+1)*(1e-2);

        double Bx = (pow((1-tt),3)*xp0) +(3*(pow((1-tt),2))*tt*xp1) +(3*(1-tt)*pow(tt,2)*xp2)+(pow(tt,3)*xp3);
        double By = (pow((1-tt),3)*yp0) +(3*(pow((1-tt),2))*tt*yp1) +(3*(1-tt)*pow(tt,2)*yp2)+(pow(tt,3)*yp3);

        double Bx_1 = (pow((1-t_1),3)*xp0) +(3*(pow((1-t_1),2))*t_1*xp1) +(3*(1-t_1)*pow(t_1,2)*xp2)+(pow(t_1,3)*xp3);
        double By_1 = (pow((1-t_1),3)*yp0) +(3*(pow((1-t_1),2))*t_1*yp1) +(3*(1-t_1)*pow(t_1,2)*yp2)+(pow(t_1,3)*yp3);

        double Bx1 = (pow((1-t1),3)*xp0) +(3*(pow((1-t1),2))*t1*xp1) +(3*(1-t1)*pow(t1,2)*xp2)+(pow(t1,3)*xp3);
        double By1 = (pow((1-t1),3)*yp0) +(3*(pow((1-t1),2))*t1*yp1) +(3*(1-t1)*pow(t1,2)*yp2)+(pow(t1,3)*yp3);

        lines[Bx].push_back(By);

        double teta = atan2((By1 - By_1),(Bx1 - Bx_1))*(180/PI);
        lines[Bx].push_back(teta);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



