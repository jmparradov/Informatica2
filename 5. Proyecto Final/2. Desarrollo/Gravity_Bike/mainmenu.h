#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QDebug>
#include "createuser.h"
#include "login_form.h"
#include "howto.h"

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

public slots:
    void on_CreateUserButton_clicked();

    void on_LoginButton_clicked();

    void on_HowToButton_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
