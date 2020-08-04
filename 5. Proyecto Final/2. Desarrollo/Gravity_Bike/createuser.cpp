#include "mainmenu.h"
#include "ui_createuser.h"
#define n 4

createuser::createuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createuser)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

createuser::~createuser()
{
    delete ui;
}

void createuser::on_addUserButton_clicked()
{
    qDebug() << "add user";

    QString user = ui->username_input->text();
    qDebug() << "user: "<<user;

    QString password = ui->password_input->text();
    qDebug() << "user: "<<password;

    std::string user_s = user.toUtf8().constData();
    std::string pass_s = password.toUtf8().constData();

    append_users_info(user_s + "," + pass_s);

}

void createuser::on_cancelbutton_clicked()
{
    this->close();
    mainmenu *ww = new mainmenu();
    ww->show();
}


void createuser::append_users_info(std::string input){
    std::string crypted = "";
    crypted = p_encriptado(input);
    std::ofstream outfile;

    outfile.open("../Gravity_Bike/sources/users/users.txt", std::ios_base::app);
    qDebug() << outfile.is_open();

    bool success = outfile.is_open();

    if (success){
        outfile << crypted + "\n";
        outfile.close();

        QMessageBox msgBox;
        msgBox.setText("The user was sucessfully added.");
        msgBox.exec();

        this->close();
        game_options *ww = new game_options();
        ww->show();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("The user was not added, please try again");
        msgBox.exec();
    }

}

std::string createuser::strToBinary(std::string s){
    int nl = s.length();
    std::string binary = "";
    for (int i = 0; i < nl; i++)
    {

        int val = int(s[i]);
        std::string bin = "";
        int j = 0;
        while (j < 8)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
            j += 1;
        }
        reverse(bin.begin(), bin.end());
    binary += bin;
    }
    return binary;
}

std::string createuser::p_encriptado(std::string text){

    int l_binary = 0;
    std::string binary = "";
    int i = 0;
    int j = 0;
    int cnt_group = 0;
    int one_count = 0;
    int zero_count = 0;

    int n_one_count = 0;
    int n_zero_count = 0;
    std::string crypted = "";

    binary = strToBinary(text);
    l_binary = binary.length();

    while (i<l_binary){
        while (j<n){
            if (cnt_group == 0){
                if (binary[i] =='0'){
                    crypted.push_back('1');
                    n_zero_count += 1;
                }
                else{
                    n_one_count += 1;
                    crypted.push_back('0');
                }
            }
            else {
                if(zero_count == one_count){
                    if (binary[i] =='0'){
                        crypted.push_back('1');
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        crypted.push_back('0');
                    }
                }
                else if(zero_count > one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%2==0){
                            crypted.push_back('1');
                        }
                        else{
                            crypted.push_back('0');
                        }
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        if ((j+1)%2==0){
                            crypted.push_back('0');
                        }
                        else{
                            crypted.push_back('1');
                        }
                    }

                }
                else if(zero_count < one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%3==0){
                            crypted.push_back('1');
                        }
                        else {
                            crypted.push_back('0');
                        }
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        if ((j+1)%3==0){
                            crypted.push_back('0');
                        }
                        else {
                            crypted.push_back('1');
                        }
                    }
                }
            }
            j += 1;
            i += 1;
        }
        cnt_group += 1;
        j =0;
        zero_count = n_zero_count;
        n_zero_count = 0;
        one_count = n_one_count;
        n_one_count = 0;
    }
    return crypted;
}

