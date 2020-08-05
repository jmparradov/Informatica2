#include "mainwindow.h"
#include "mainmenu.h"
#include "createuser.h"
#include <QApplication>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainmenu w;
    w.show();
    return a.exec();
}
