#ifndef WHEEL_H
#define WHEEL_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <tgmath.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class wheel:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    wheel();
    bool checkColliding(int xp0,int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3);
    int radio;
    double teta = 90;

public slots:
    void move();


private:
    double vo;
};

#endif // WHEEL_H
