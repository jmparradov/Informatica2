#include "road.h"

road::road(){


}

void road::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,QWidget * widget){
    QPainterPath path;
    path.cubicTo(250, 600,  300, 200,  scenex, sceney);

    painter->setPen(QPen(Qt::green, 4));
    painter->drawPath(path);
}

QRectF road::boundingRect() const
{
    // outer most edges
    return QRectF();
}
