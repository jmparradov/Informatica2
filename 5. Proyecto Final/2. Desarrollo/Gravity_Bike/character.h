#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QDebug>

#define M 80         // Peso Bicicleta kg

class character:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    character();


public slots:

};

#endif // BACKGROUND_H

