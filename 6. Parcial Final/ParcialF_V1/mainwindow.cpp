#include "mainwindow.h"
#include "ui_mainwindow.h"

#define scenex 1500
#define sceney 1000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);


    //Insert background
    QPixmap pim("../ParcialF_V1/images/background.jpg");
    bool loaded = pim.load("../ParcialF_V1/images/background.jpg");

    if (loaded){
        scene->setBackgroundBrush(pim); }
    else {
         qDebug() << "bk image not laoded";
    }

    // Bodies creation //////

    // planet(int xi, int yi, double vx, double vy, double mi,  int radio, QColor color)

    //Create frist body
    planet * star = new planet(0,0,0,0,50000, 200,Qt::yellow);
    scene->addItem(star);

    //Create second body
    planet * planet1 = new planet(-5000,0,0,-2,70, 70, Qt::blue);
    scene->addItem(planet1);       // body

    //Create third body
    planet * planet2 = new planet(5000,0,0,2,70, 70, Qt::green);
    scene->addItem(planet2);       // body


    //Create forth body
    planet * planet3 = new planet(0,-5000,2,0,70, 70, Qt::red);
    scene->addItem(planet3);       // body


    //Create fifth body
    planet * planet4 = new planet(0,5000,-2,0,70, 70, Qt::magenta);
    scene->addItem(planet4);


    // create falling object
    falling * object1 = new falling();
    scene->addItem(object1);

    //Add View and define its characteristics

    scene->setSceneRect(0,0,scenex,sceney);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setFixedSize(scenex,sceney);
    view->maximumSize();
    view->show();

}

/*
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        falling * object1 = new falling();
        scene->addItem(object1);
        qDebug() << "adding object";
    }
} */

MainWindow::~MainWindow()
{
    delete ui;
}

