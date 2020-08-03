#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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
