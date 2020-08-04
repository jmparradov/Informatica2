#include "mainmenu.h"
#include "ui_login_form.h"
#define n 4

login_form::login_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_form)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

login_form::~login_form()
{
    delete ui;
}

void login_form::on_LoginButton_2_clicked()
{
    this->close();
    mainmenu *ww = new mainmenu();
    ww->show();
}

void login_form::on_LoginButton_clicked()
{

    QString user = ui->username_input->text();
    QString password = ui->password_input->text();

    std::string user_s = user.toUtf8().constData();
    std::string pass_s = password.toUtf8().constData();

    if (validate(user_s,pass_s)){
        this->close();
        game_options *ww = new game_options();
        ww->show();
    }
    else{
        qDebug() << "failed";
    }
}

bool login_form::validate(std::string s_username, std::string s_password){
    bool validation = false;

    std::vector<std::string> users_auth = get_userinfo();
    std::vector<std::string>::iterator it = users_auth.begin();

    while(it != users_auth.end()){
        std::vector <std::string> user_content = split_text(*it);
        if (user_content[0] == s_username && user_content[1] == s_password){
            validation = true;
        }
        it++;
    }


    return validation;
}

std::vector <std::string> login_form:: get_userinfo(){
std::string data = "";
std::string ndata = "";
std::vector<std::string> seglist;

   std::ifstream infile;
   infile.open("../Gravity_Bike/sources/users/users.txt");

   while (std::getline(infile, data))
   {
       if(data.size() > 0){
           ndata = p_desencriptado(data);
           seglist.push_back(ndata);
       }
   }
   infile.close();

   return seglist;
  }

std::vector <std::string> login_form::split_text(std::string value){
    std::stringstream test(value);
    std::string segment;
    std::vector<std::string> seglist;
    while(getline(test, segment, ','))
    {
       seglist.push_back(segment);
    }
    return seglist;
}


std::string login_form::BinaryTostr(std::string s){
    int nl = s.length();
    std::string original = "";
    int sum = 0;
    int j = 7;
    int i = 0;

    while (i < nl){
        while (j >= 0){
            if (s.at(i) == '1'){
                sum += pow(2,j);
            }
            j -= 1;
            i += 1;
        }

        std::string ss(1, char(sum));
        original += ss;
        j = 7;
        sum = 0;
    }
    return original;
}



std::string login_form::p_desencriptado(std::string binary){
    int l_binary = 0;
    int i = 0;
    int j = 0;
    int cnt_group = 0;
    int one_count = 0;
    int zero_count = 0;

    int n_one_count = 0;
    int n_zero_count = 0;
    std::string crypted = "";
    std::string decrypted = "";

    l_binary = binary.length();

    while (i<l_binary){
        while (j<n){
            if (cnt_group == 0){
                if (binary[i] =='0'){
                    crypted.push_back('1');
                    n_one_count += 1;
                }
                else{
                    n_zero_count += 1;
                    crypted.push_back('0');
                }
            }
            else {
                if(zero_count == one_count){
                    if (binary[i] =='0'){
                        crypted.push_back('1');
                        n_one_count += 1;
                    }
                    else{
                        n_zero_count += 1;
                        crypted.push_back('0');
                    }
                }
                else if(zero_count > one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%2==0){
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                        else{
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }

                    }
                    else{
                        if ((j+1)%2==0){
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }
                        else{
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                    }

                }
                else if(zero_count < one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%3==0){
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                        else {
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }

                    }
                    else{
                        if ((j+1)%3==0){
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }
                        else {
                            crypted.push_back('1');
                            n_one_count += 1;
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

    decrypted = BinaryTostr(crypted);
    return decrypted;
}


