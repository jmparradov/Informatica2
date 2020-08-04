#include "obstacle.h"
#include "road.h"

#define worldx 15024
#define worldy 6736
#define rel 0.5

obstacle::obstacle(std::map<double, std::vector<double>> line, double Xo, std::string type)
{
    lines = line;
    double height = 0;
    std::map<double, std::vector<double>>::iterator it;

    it = lines.lower_bound (Xo*worldx);
    double Yo = it->second[0];

    if (type == "barrel"){
        height = 71*rel;
        QPixmap pim(":/sources/objects/barrel.png");
        setPixmap(pim);
    }

    else if(type == "bush1"){
        height = 60*rel;
        QPixmap pim(":/sources/objects/bush1.png");
        setPixmap(pim);
    }

    else if(type == "rock1"){
        height = 60*rel;
        QPixmap pim(":/sources/objects/rock1.png");
        setPixmap(pim);
    }

    else if(type == "rock3"){
        height = 60*rel;
        QPixmap pim(":/sources/objects/rock3.png");
        setPixmap(pim);
    }

    else if(type == "rock2"){
        height = 52*rel;
        QPixmap pim(":/sources/objects/rock2.png");
        setPixmap(pim);
    }

    else if(type == "wood"){
        height = 52*rel;
        QPixmap pim(":/sources/objects/wood.png");
        setPixmap(pim);
    }






    setPos(it->first,Yo-height);
    qDebug() << Xo;

}
