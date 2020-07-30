#ifndef PLANET_H
#define PLANET_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QObject>
#include <QDebug>
#include <vector>
#include <QTimer>
#include <tgmath.h>
#include <QLabel>

// Corpus object, this object contains the atributies to simulate a physical movements according to newton laws

class planet:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    planet(int xi, int yi, double vx, double vy, double mi, int radio, QColor);
    void set_real_coordinates(int xi, int yi);
    double get_mass();
    int get_virtual_x();
    int get_virtual_y();
    void set_velocity(double vxi,double vyi);
    void setmass(double mi);

private:
    double xp;
    double yp;
    double vx0;
    double vy0;
    double m;
    int cradio;
    double a;


    double vo;
public slots:
    void move();
};

#endif // PLANET_H
