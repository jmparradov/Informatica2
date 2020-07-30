#include "planet.h"

#define scenex 1500
#define sceney 1000

#define DP 10e9 // Escala de simulación 1px = 10^9 m
#define G 6.67384e-11   // Constante gravitacional m3/kg*s2
#define t 10             // unidad de tiempo en ms
#define PI 3.14159265

#define MR 1e26    // relación de masas Kg/(masa virutal)
#define VR 3.8e3   // relación de velocidades m/(s*velocidad virtual)
#define PR 0.09    // relación pixeles reales con virtuales
#define RR 0.5     // relación radios reales con virtuales

planet::planet(int xi, int yi, double vx, double vy, double mi,  int radio, QColor color){

    set_real_coordinates(xi*PR,yi*PR);
    radio = radio*RR;

    //draw it and locate
    setRect(0,0,radio,radio);

    // define body mass
    setmass(mi*MR);

    // set inicial velocity:
    set_velocity(vx*VR,vy*VR);

    // convert to virtual variables
    xi = get_virtual_x();
    yi = get_virtual_y();


    // draw the body
    setPos(xi-radio/2,yi-radio/2);
    setBrush(QBrush(color));

    //make corpus focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(t);

}

void planet::move(){

    // Function to apply the physis movement of the model
    double dx = 0;
    double dy = 0;
    double ti = t*10e4; // time scale of simulation

    double ax = 0; // x axis acceleration
    double ay = 0; // y axis acceleration

    double vx = 0; // x axis velocity
    double vy = 0; // y axis velocity


    foreach(QGraphicsItem *item, scene()->items()){
        if (item->type() == planet::Type){
            if (this != qgraphicsitem_cast<planet*>(item)){
               double xi = qgraphicsitem_cast<planet*>(item)->xp;
               double yi = qgraphicsitem_cast<planet*>(item)->yp;
               double mi = qgraphicsitem_cast<planet*>(item)->get_mass(); // get body mass

               //qDebug() << yi;

               double r = sqrt(pow((xi-xp),2) + pow((yi-yp),2));    // distance between bodies

               // condition for collision
               if (r<= 10e10 && m <= mi){
                    scene()->removeItem(qgraphicsitem_cast<planet*>(this));
                    delete qgraphicsitem_cast<planet*>(this);

                    mi += m;
                    qgraphicsitem_cast<planet*>(item)->setmass(mi);
               }

               double ydif = yi-yp;
               double xdif = xi-xp;
               double teta = 0;

               teta = atan2(ydif,xdif)*(180/PI);    // angle between bodies

               //qDebug() << "Distance :" <<r;
               //qDebug() << "teta " <<teta;

               // acceleration components
               ax += (G*mi*cos(teta*PI/180))/pow(r,2);
               ay += (G*mi*sin(teta*PI/180))/pow(r,2);

               // Magnitud acceleration
               a = sqrt(pow(ax,2)+ pow(ay,2));
            }
       }
    }

    vx = vx0 + (ax*ti);
    vy = vy0 + (ay*ti);
    set_velocity(vx,vy);

    dx = (vx*ti) + (ax*pow(ti,2)/2);
    dy = (vy*ti) + (ay*pow(ti,2)/2);

    xp += dx;
    yp += dy;

    dx = dx/DP; // virtual displacement x
    dy = dy/DP; // virtual displacement y

    setPos(x()+dx,y()+dy);
}


void planet::set_real_coordinates(int xi,int yi){
    //Function to set physic coordinates
    xp = xi*DP; // distance in m x
    yp = yi*DP; // distance in m y
}

double planet::get_mass(){
    // Get mass Value
    return m;
}

int planet::get_virtual_x(){
    // Get virtual X Coordinate (px)
    int xv = (xp/DP) + (scenex/2);
    return xv;
}

int planet::get_virtual_y(){
    // Get virtual Y Coordinate (px)
    int yv = (yp/DP) + (sceney/2);
    return yv;
}

void planet::set_velocity(double vxi,double vyi){
    //Set velocity m/s
    vx0 = vxi;
    vy0 = vyi;
}

void planet::setmass(double mi){
    //Set Mass Kg
    m = mi;
}
