#ifndef LOAD_H
#define LOAD_H

#include <QWidget>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tgmath.h>
#include <QDebug>

namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT

public:
    explicit load(QWidget *parent = nullptr);
    ~load();

    std::vector <std::string> get_userinfo();
    std::string p_desencriptado(std::string binary);
    std::string BinaryTostr(std::string s);
    std::vector <std::string> split_text(std::string value);
    std::vector <std::string> saved_games;

private slots:
    void on_pushButton_clicked();

    void on_backbutton_clicked();

private:
    Ui::load *ui;
};

#endif // LOAD_H
