#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QWidget>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tgmath.h>
#include <QDebug>

namespace Ui {
class login_form;
}

class login_form : public QWidget
{
    Q_OBJECT

public:
    explicit login_form(QWidget *parent = nullptr);
    bool validate(std::string s_username, std::string s_password);
    std::vector <std::string> get_userinfo();
    std::vector <std::string> split_text(std::string value);
    std::string p_desencriptado(std::string binary);
    std::string p_encriptado(std::string text);
    std::string BinaryTostr(std::string s);
    std::string strToBinary(std::string s);

    ~login_form();

private slots:
    void on_LoginButton_clicked();

private:
    Ui::login_form *ui;
};

#endif // LOGIN_FORM_H
