#include "falling.h"

#define E 150        // px/m
#define T 1          // unidad de tiempo en ms
#define PI 3.14159265
#define scenex 1500
#define sceney 1000

falling::falling()
{
    int radio = 20;
    auto Go = bind(std::uniform_int_distribution<>(5,20),std::default_random_engine());
    //auto Xo = bind(std::uniform_int_distribution<>(0,10),std::default_random_engine());
    double Xo =  qrand() / (sceney);
    qDebug() <<Xo;
    G = Go();
    vo = 0;
    teta = 90;

    qDebug() << "starting falling";

    //draw it and locate
    setRect(Xo*30,0,radio,radio);
    setPos(Xo*30,0);

    //make item  focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    setBrush(QBrush(Qt::white));
    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(T);
}


void falling::move(){

    // acceleration components
    double a = G*sin(teta*PI/180);

    double tp = (1e-3)*T;
    double yp = (vo*tp)+(0.5*a*tp*tp);

    double dx = yp*cos(teta*PI/180)*E;
    double dy = yp*sin(teta*PI/180)*E;

    vo += a*(tp);
    setPos(x()+dx,y()+dy);

    if(y()>sceney){
        teta = -90;
        vo *= 0.5;
    }

}


void falling::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_W){
        falling * object1 = new falling();
        scene()->addItem(object1);
        qDebug() <<"falling again";
    }
}
