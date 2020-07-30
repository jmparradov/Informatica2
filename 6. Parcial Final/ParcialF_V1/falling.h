#ifndef FALLING_H
#define FALLING_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QDebug>
#include <QGraphicsView>
#include <stdlib.h>
#include <random>


class falling:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    falling();

    double teta;
    double G;

public slots:
    void move();


private:
    double vo;
};

#endif // FALLING_H
