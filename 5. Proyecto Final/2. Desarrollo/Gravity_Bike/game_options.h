#ifndef GAME_OPTIONS_H
#define GAME_OPTIONS_H

#include <QWidget>

namespace Ui {
class game_options;
}

class game_options : public QWidget
{
    Q_OBJECT

public:
    explicit game_options(QWidget *parent = nullptr);
    ~game_options();

private:
    Ui::game_options *ui;
};

#endif // GAME_OPTIONS_H
