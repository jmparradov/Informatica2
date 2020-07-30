#ifndef BIKER_H
#define BIKER_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <tgmath.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

class biker:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // Methods
    biker();
    bool checkColliding(int xp0,int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3, double dx);
    void keyPressEvent(QKeyEvent *event);

    // Attibutes
    int width;
    int height;
    double teta = 90;
    double teta_aux = 0;

    // booleans
    bool jump;
    bool speed;
    bool Break;
    bool flying;

public slots:
    void move();


private:
    double vo;
};

#endif // WHEEL_H
