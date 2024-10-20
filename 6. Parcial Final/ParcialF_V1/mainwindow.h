#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>

#include "planet.h"
#include "falling.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H

