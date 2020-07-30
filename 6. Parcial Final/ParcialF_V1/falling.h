#ifndef FALLING_H
#define FALLING_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QDebug>
#include <QGraphicsView>
#include <stdlib.h>
#include <random>
#include <QKeyEvent>

class falling:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    falling();
    void keyPressEvent(QKeyEvent *event);

    double teta;
    int G;

public slots:
    void move();


private:
    double vo;
};

#endif // FALLING_H
