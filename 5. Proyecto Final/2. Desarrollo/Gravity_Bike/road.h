#ifndef ROAD_H
#define ROAD_H

#include <QPainterPath>
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>


#define scenex 1300
#define sceney  600

class road:public QObject, public QGraphicsItem
{


public:
    road(int xp0,int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3, int id);
    virtual void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QRectF boundingRect() const;

    int xp0;
    int yp0;
    int xp1;
    int yp1;
    int xp2;
    int yp2;
    int xp3;
    int yp3;

    int id;

public slots:
    void move();


};

#endif // ROAD_H
