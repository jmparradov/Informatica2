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
#include <pause.h>
#include <game_over.h>
#include <QMainWindow>

class biker:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // Methods
    biker(std::map<double, std::vector<double>> lines, QString difficult, QString world, int  players, QMainWindow *mainW, int n_player);
    bool checkrolling(double dx);
    bool checkColliding();
    void keyPressEvent(QKeyEvent *event);
    void append_users_info(std::string input);
    std::string strToBinary(std::string s);
    std::string p_encriptado(std::string text);

    // Attibutes
    int width;
    int height;
    double teta = 90;
    double teta_aux = 0;
    int n_player;

    QMainWindow *mainW;

    // booleans
    bool paused;
    bool jump;
    bool speed;
    bool Break;
    bool flying;
    std::map<double, std::vector<double>> lines;
    QString difficult;
    QString world;
    int  players;
    QTimer *timer = new QTimer();

public slots:
    void move();


private:
    double vo;
};

#endif // WHEEL_H
