#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "game_over.h"
#include "load.h"
#include "win.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString difficult = "amateur", QString world = "montains", int  players = 1, double x1 = 0, double y1 = 0,
               double x2 = 0, double y2=0, double v01=0, double v02 = 0);
    void append_users_info(std::string input);
    std::string strToBinary(std::string s);
    std::string p_encriptado(std::string text);

    ~MainWindow();

    // atributes
    std::map<double, std::vector<double>> lines;
    void field(int xp0, int yp0,int xp1,int yp1,int xp2,int yp2,int xp3,int yp3);
    void set_up();

private:
    Ui::MainWindow *ui;    
    QGraphicsScene * scene = new QGraphicsScene(this);
    QGraphicsView * view = new QGraphicsView(this);
};
#endif // MAINWINDOW_H
