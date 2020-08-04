#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class game_over;
}

class game_over : public QWidget
{
    Q_OBJECT

public:
    explicit game_over(QString difficult, QString world, int  players,QMainWindow *mainW_s);
    ~game_over();

    QString difficult;
    QString world;
    int  players;

private slots:
    void on_restartbutton_clicked();

    void on_loadbutton_clicked();

    void on_menubutton_clicked();

private:
    Ui::game_over *ui;
};

#endif // GAME_OVER_H
