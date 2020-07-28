#include "road.h"

road::road(int xp_0,int yp_0,int xp_1,int yp_1,int xp_2,int yp_2,int xp_3,int yp_3){
xp0 = xp_0;
yp0 = yp_0;
xp1 = xp_1;
yp1 = yp_1;
xp2 = xp_2;
yp2 = yp_2;
xp3 = xp_3;
yp3 = yp_3;


}


void road::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,QWidget * widget){
    QPainterPath path;
    path.moveTo(xp0,yp0);

    path.cubicTo(xp1, yp1, xp2, yp2, xp3, yp3);
    painter->setPen(QPen(Qt::black, 4));
    painter->drawPath(path);
}

QRectF road::boundingRect() const
{
    return QRectF();
}
