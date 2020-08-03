#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <fstream>
#include <QFile>

namespace Ui {
class createuser;
}

class createuser : public QWidget
{
    Q_OBJECT

public:
    explicit createuser(QWidget *parent = nullptr);
    ~createuser();
    void append_users_info(std::string input);
    std::string p_encriptado(std::string text);
    std::string strToBinary(std::string s);

private slots:
    void on_addUserButton_clicked();

private:
    Ui::createuser *ui;
};

#endif // CREATEUSER_H
