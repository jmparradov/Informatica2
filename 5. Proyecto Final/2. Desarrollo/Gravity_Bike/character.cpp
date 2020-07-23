#include "character.h"

character::character()
{

    QPixmap pim("../Gravity_Bike/sources/character/c1.png");
    setPixmap(pim);
    setPos(100,100);
    //setRotation(60);

    QGraphicsEllipseItem *w1  = new QGraphicsEllipseItem();
    QGraphicsEllipseItem *w2  = new QGraphicsEllipseItem();



}
