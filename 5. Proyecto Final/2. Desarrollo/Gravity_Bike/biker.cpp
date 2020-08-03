#include "biker.h"
#include "road.h"

#define PI 3.14159265
#define M 80         // Peso Bicicleta kg
#define G 9.89       // gravity m/s^2
#define E 150        // px/m
#define T 1          // unidad de tiempo en ms

biker::biker(std::map<double, std::vector<double>> line)
{
    width = 119;
    height = 78;
    Break = false;
    flying = false;
    jump = false;
    speed = false;
    vo = 0;
    lines = line;

    //qDebug() << "lines" <<lines;

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
    bool collision = checkColliding();
    qDebug() << "coll :" <<collision;

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

    bool coll = checkrolling(dx);
    //qDebug() << "coll :" <<coll;
    if (coll){
        tries += 1;
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
            teta += 500*tp;
        }
    }

}

bool biker::checkColliding(){
    bool collided = false;
    for(QGraphicsItem* item: collidingItems()) {
        if (item->type() == 7){
            qDebug() <<item->type();
            collided = true;
        }
    }
    return collided;
}

bool biker::checkrolling(double dx){

    bool collided = false;
    double tolerance = 3;

    double Bx_min = 0.00;
    double By_min = 0.00;
    double r_min = 1e6;

    double px_min = 0.00;
    double py_min = 0.00;

    //qDebug() << "lines" <<lines;
    for (std::map<double, std::vector<double>>::iterator it = lines.begin(); it != lines.end(); it++ ){
        double Bx = it->first;
        double By = it->second[0];
        double px = x() + (width/2);
        double py = y() + (height/2);

        double r = sqrt(pow((Bx-px),2) + pow((By-py),2));
        //qDebug() << "r i" <<r;
        if (r < r_min){
            r_min = r;

            Bx_min = Bx;
            By_min = By;

            px_min = px;
            py_min = py;
        }
    }

    //qDebug() << "r min :" <<r_min;

    if (abs(r_min - height/2) < tolerance){

        teta = lines[Bx_min][1];

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
