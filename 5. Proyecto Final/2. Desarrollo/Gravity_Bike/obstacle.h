#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QBrush>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <tgmath.h>
#include <random>


class obstacle:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    obstacle(std::map<double, std::vector<double>>line, double Xo,  std::string type);
    void field(int xp0, int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3);

    std::map<double, std::vector<double>> lines;
    //std::string type = "";
};

#endif // OBSTACLE_H
