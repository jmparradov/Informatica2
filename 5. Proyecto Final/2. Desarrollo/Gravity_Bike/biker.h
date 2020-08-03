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
    biker(std::map<double, std::vector<double>> lines);
    bool checkrolling(double dx);
    bool checkColliding();
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
    std::map<double, std::vector<double>> lines;

public slots:
    void move();


private:
    double vo;
};

#endif // WHEEL_H
