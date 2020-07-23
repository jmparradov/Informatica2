#ifndef WHEEL_H
#define WHEEL_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <tgmath.h>
#include <QTimer>
#include <QDebug>

class wheel:public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    wheel();

public slots:
    void move();

private:
    double vo;
};

#endif // WHEEL_H
