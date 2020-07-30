#include "biker.h"
#include "road.h"

#define PI 3.14159265
#define M 80         // Peso Bicicleta kg
#define G 9.89       // gravity m/s^2
#define E 150        // px/m
#define T 1          // unidad de tiempo en ms

biker::biker()
{
    width = 119;
    height = 78;
    Break = false;
    flying = false;
    jump = false;
    speed = false;
    vo = 0;

    //draw it and locate
    QPixmap pim("../Gravity_Bike/sources/character/c1.png");
    setPixmap(pim);
    setTransformOriginPoint(width/2,height/2);
    setPos(0,0);

    qDebug() << "x :" <<x();
    qDebug() << "y :" <<y();

    //make item  focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(T);
}

void biker::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_W){
        // Up action - jump
        if(!flying){
            jump = true;
        }
    }

    else if (event->key() == Qt::Key_D){
        // Right action - speed up
        if(!flying){
            speed = true;
        }
        else {
            teta_aux += 5;
            setRotation(teta_aux);
        }
    }

    else if (event->key() == Qt::Key_A){
        // Left Action - Break
        if(!flying){
            Break = true;
        }
        else {
            teta_aux -= 5;
            setRotation(teta_aux);
        }
    }
}

void biker::move(){

    // acceleration components
    double a = G*sin(teta*PI/180);

    double tp = (1e-3)*T;
    double yp = (vo*tp)+(0.5*a*tp*tp);

    double dx = yp*cos(teta*PI/180)*E;
    double dy = yp*sin(teta*PI/180)*E;

    int tries = 0;

    vo += a*(tp);


    setPos(x()+dx,y()+dy);
    QList<QGraphicsView *> views = scene()->views();
    views.at(0)->centerOn(this);

    foreach(QGraphicsItem *item, scene()->items()){

        if (item->type() == 65536){//road::Type){
            int xp0 = qgraphicsitem_cast<road*>(item)->xp0;
            int yp0 = qgraphicsitem_cast<road*>(item)->yp0;

            int xp1 = qgraphicsitem_cast<road*>(item)->xp1;
            int yp1 = qgraphicsitem_cast<road*>(item)->yp1;

            int xp2 = qgraphicsitem_cast<road*>(item)->xp2;
            int yp2 = qgraphicsitem_cast<road*>(item)->yp2;

            int xp3 = qgraphicsitem_cast<road*>(item)->xp3;
            int yp3 = qgraphicsitem_cast<road*>(item)->yp3;


            bool coll = checkColliding(xp0,yp0,xp1,yp1,xp2,yp2,xp3,yp3,dx);
            if (coll){
                tries += 1;
            }
        }

        if (tries >0){

            // velocity
            vo -= a*(tp);

            // set character rotation
            setRotation(teta);
            teta_aux = teta;
        }
        else{

            if (teta<90){
                teta += 50*tp;
            }
        }
    }
}

bool biker::checkColliding(int xp0,int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3, double dx){

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


        if (!jump){
            if (Break){
                vo -= 1;
                qDebug() <<"break";
                Break = false;
            }

            if (speed){
                vo += 1;
                qDebug() <<"speed up";
                speed = false;
            }

            setPos(x()+dx,By_min-(height+tolerance));
            flying = false;
        }
        else {
            flying = true;
            setRotation(teta);
            teta_aux = teta;

            teta = -30;
            jump = false;
            qDebug() <<"jumping ";

            return false;
        }

        QList<QGraphicsView *> views = scene()->views();
        views.at(0)->centerOn(this);
        return true;

    }

    return collided;
}
