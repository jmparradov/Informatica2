#include "wheel.h"
#include "road.h"

#define PI 3.14159265
#define M 80         // Peso Bicicleta kg
#define G 9.89       // gravity m/s^2
#define E 150        // px/m
#define T 1.5          // unidad de tiempo en ms

wheel::wheel()
{
    width = 119;
    height = 78;

    //draw it and locate
    QPixmap pim("../Gravity_Bike/sources/character/c1.png");
    setPixmap(pim);
    setTransformOriginPoint(width/2,height/2);


    //setRect(0,0,radio,radio);
    setPos(0,0);

    qDebug() << "x :" <<x();
    qDebug() << "y :" <<y();


    // color
    //setBrush(QBrush(Qt::black));

    vo = 0;

    //make item  focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(T);
}

void wheel::move(){

    // acceleration components
    double a = G*sin(teta*PI/180);

    double tp = (1e-3)*T;
    double yp = (vo*tp)+(0.5*a*tp*tp);

    double dx = yp*cos(teta*PI/180)*E;
    double dy = yp*sin(teta*PI/180)*E;

    vo += a*(tp);
    //qDebug() << "vo "<<vo;

    setPos(x()+dx,y()+dy);
    QList<QGraphicsView *> views = scene()->views();
    views.at(0)->centerOn(this);

    foreach(QGraphicsItem *item, scene()->items()){
        //qDebug() << item->type();
        if (item->type() == 65536){//road::Type){
            int xp0 = qgraphicsitem_cast<road*>(item)->xp0;
            int yp0 = qgraphicsitem_cast<road*>(item)->yp0;

            int xp1 = qgraphicsitem_cast<road*>(item)->xp1;
            int yp1 = qgraphicsitem_cast<road*>(item)->yp1;

            int xp2 = qgraphicsitem_cast<road*>(item)->xp2;
            int yp2 = qgraphicsitem_cast<road*>(item)->yp2;

            int xp3 = qgraphicsitem_cast<road*>(item)->xp3;
            int yp3 = qgraphicsitem_cast<road*>(item)->yp3;

            int id = qgraphicsitem_cast<road*>(item)->id;


            bool coll = checkColliding(xp0,yp0,xp1,yp1,xp2,yp2,xp3,yp3,dx);

            if (coll){

                //setPos(x()-dx,y()-dy);
                vo -= a*(tp);
                // set character rotation
                setRotation(teta);

            }
            else{
                if (teta<90){
                    teta += 50*tp;
                }

            }
            qgraphicsitem_cast<road*>(item)->update();
        }
    }
}

bool wheel::checkColliding(int xp0,int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3, double dx){

    if (x()>xp3 && x()< xp0 && y()>yp3 && y()< yp0){
        return false;
    }

    bool collided = false;
    double tolerance = 3;

    double tt_min = 0.00;
    double Bx_min = 0.00;
    double By_min = 0.00;
    double r_min = 1e6;
    double px_min = 0.00;
    double py_min = 0.00;

    for(int i = 0;i<=100;i++){

        double tt = i*(1e-2);
        double Bx = (pow((1-tt),3)*xp0) +(3*(pow((1-tt),2))*tt*xp1) +(3*(1-tt)*pow(tt,2)*xp2)+(pow(tt,3)*xp3);
        double By = (pow((1-tt),3)*yp0) +(3*(pow((1-tt),2))*tt*yp1) +(3*(1-tt)*pow(tt,2)*yp2)+(pow(tt,3)*yp3);


        double px = x() + (width/2);
        double py = y() + (height/2);

        double r = sqrt(pow((Bx-px),2) + pow((By-py),2));

        if (r < r_min){
            r_min = r;
            Bx_min = Bx;
            By_min = By;

            px_min = px;
            py_min = py;

            tt_min = tt;
        }

    }

        if (abs(r_min - height/2) < tolerance){
            double tt_1 = 0;
            double tt1 = 0;

            int i = tt_min*100;

            if (i== 0){
                tt_1 = (i+1)*(1e-2);
                tt1 =  (i+2)*(1e-2);
            }

            else {
                tt_1 = (i-1)*(1e-2);
                tt1 =  (i+1)*(1e-2);
            }


            double Bx_1 = (pow((1-tt_1),3)*xp0) +(3*(pow((1-tt_1),2))*tt_1*xp1) +(3*(1-tt_1)*pow(tt_1,2)*xp2)+(pow(tt_1,3)*xp3);
            double By_1 = (pow((1-tt_1),3)*yp0) +(3*(pow((1-tt_1),2))*tt_1*yp1) +(3*(1-tt_1)*pow(tt_1,2)*yp2)+(pow(tt_1,3)*yp3);

            double Bx1 = (pow((1-tt1),3)*xp0) +(3*(pow((1-tt1),2))*tt1*xp1) +(3*(1-tt1)*pow(tt1,2)*xp2)+(pow(tt1,3)*xp3);
            double By1 = (pow((1-tt1),3)*yp0) +(3*(pow((1-tt1),2))*tt1*yp1) +(3*(1-tt1)*pow(tt1,2)*yp2)+(pow(tt1,3)*yp3);

            teta = atan2((By1 - By_1),(Bx1 - Bx_1))*(180/PI);

            /*
            qDebug() <<"collision";
            qDebug() <<" y-1"<<By1;
            qDebug() <<" y+1"<<By_1;

            qDebug() <<"id: "<<id;
            qDebug() <<"teta: "<<teta;
            qDebug() <<"distance: "<<r_min;
            qDebug() <<"Bx: "<<Bx_min;
            qDebug() <<"By: "<<By_min;
            qDebug() <<"Set xi: "<<x()+radio/2;
            qDebug() <<"Set yi: "<<y()+radio/2; */

            setPos(x()+dx,By_min-(height+tolerance));

            /*
            qDebug() <<"Set x: "<<x()+radio/2;
            qDebug() <<"Set y: "<<y()+radio/2;

            */

            qDebug() <<"dx: "<<dx;

            QList<QGraphicsView *> views = scene()->views();
            views.at(0)->centerOn(this);

            if (i==0){
                //qDebug() <<"edge";
                //setPos(Bx + radio/2, By- radio/2);
            }

            return true;

    }

    return collided;
}
