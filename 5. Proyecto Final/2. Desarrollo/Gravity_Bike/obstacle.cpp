#include "obstacle.h"
#include "road.h"

#define worldx 15024
#define worldy 6736

obstacle::obstacle(std::map<double, std::vector<double>> line, double Xo, std::string type)
{
    lines = line;
    double height = 85;

    std::map<double, std::vector<double>>::iterator it;

    it = lines.lower_bound (Xo);
    double Yo = it->second[0];

    if (type == "barrel"){
        height = 70;
    }

    //draw it and locate
    QPixmap pim(":/sources/objects/barrel.png");
    setPixmap(pim);
    setPos(it->first,Yo-height);
    qDebug() << Xo;

}
