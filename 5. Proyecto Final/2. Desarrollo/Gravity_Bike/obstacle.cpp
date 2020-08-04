#include "obstacle.h"
#include "road.h"

#define worldx 15024
#define worldy 6736

obstacle::obstacle(std::map<double, std::vector<double>> line, double Xo, std::string type)
{
    lines = line;
    double height = 0;
    std::map<double, std::vector<double>>::iterator it;

    it = lines.lower_bound (Xo*worldx);
    double Yo = it->second[0];

    if (type == "barrel"){
        height = 71*0.9;
        QPixmap pim(":/sources/objects/barrel.png");
        setPixmap(pim);
    }

    else if(type == "bush1"){
        height = 60*0.9;
        QPixmap pim(":/sources/objects/bush1.png");
        setPixmap(pim);
    }

    else if(type == "rock3"){
        height = 60*0.8;
        QPixmap pim(":/sources/objects/rock3.png");
        setPixmap(pim);
    }


    setPos(it->first,Yo-height);
    qDebug() << Xo;

}
