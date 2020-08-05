#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class win;
}

class win : public QWidget
{
    Q_OBJECT

public:
    explicit win(QMainWindow *mainW, int n_player, QString difficult, QString world, int  players);
    ~win();

    QMainWindow *mainW;
    int player;
    QString difficult;
    QString world;
    int  players;

private slots:
    void on_restartbutton_clicked();

    void on_menubutton_clicked();

    void on_loadgamebutton_clicked();

private:
    Ui::win *ui;
};

#endif // WIN_H
