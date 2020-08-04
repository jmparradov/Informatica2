#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tgmath.h>
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>
#include <QInputDialog>
#include <QLineEdit>
#include <QDir>


namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QMainWindow *mainW_s);
    ~pause();

    std::string p_desencriptado(std::string binary);
    std::string BinaryTostr(std::string s);
    std::vector <std::string> split_text(std::string value);
    std::string  get_gamesinfo();
    void append_users_info(std::string input);
    std::string strToBinary(std::string s);
    std::string p_encriptado(std::string text);
    QMainWindow *mainW;

private slots:
    void on_continuebutton_clicked();

    void on_savebutton_clicked();

    void on_loadbutton_clicked();

    void on_exitbutton_clicked();

private:
    Ui::pause *ui;
};

#endif // PAUSE_H
