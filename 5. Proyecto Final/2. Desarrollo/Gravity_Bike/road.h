#ifndef ROAD_H
#define ROAD_H
#include <QPainterPath>
#include <QGraphicsItem>
#include <QPainter>


#define scenex 1300
#define sceney  600

class road: public QGraphicsItem
{


public:
    road();
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);
    QRectF boundingRect() const;

public slots:
    void move();


};

#endif // ROAD_H
