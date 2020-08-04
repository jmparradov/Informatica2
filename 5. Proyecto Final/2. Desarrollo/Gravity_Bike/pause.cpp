#include "pause.h"
#include "ui_pause.h"
#define n 4

pause::pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pause)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/pause.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

pause::~pause()
{
    delete ui;
}

void pause::on_continuebutton_clicked()
{
    this->close();

}

void pause::on_savebutton_clicked()
{

    std::string name = get_gamesinfo();
    QString qstr = QString::fromStdString(name);
    qDebug() << "to save" <<qstr;
    append_users_info(name);
}

void pause::on_loadbutton_clicked()
{

}

void pause::on_exitbutton_clicked()
{

}

std::string pause:: get_gamesinfo(){
std::string data = "";
std::string ndata = "";
std::vector<std::string> seglist;

   std::ifstream infile;
   infile.open("../Gravity_Bike/sources/users/temp.txt");
   int  i = 0;
   while (std::getline(infile, data))
   {
       if(data.size() > 0){
           ndata = p_desencriptado(data);
           //seglist.push_back(ndata);
           i += 1;
       }
   }
   infile.close();

   return ndata;
}


std::vector <std::string> pause::split_text(std::string value){
    std::stringstream test(value);
    std::string segment;
    std::vector<std::string> seglist;
    while(getline(test, segment, ','))
    {
       seglist.push_back(segment);
    }
    return seglist;
}


std::string pause::BinaryTostr(std::string s){
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



std::string pause::p_desencriptado(std::string binary){
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

void pause::append_users_info(std::string input){
    std::string crypted = "";
    crypted = p_encriptado(input);
    std::ofstream outfile;

    outfile.open("../Gravity_Bike/sources/users/saved.txt", std::ios_base::app);

    bool success = outfile.is_open();

    if (success){
        outfile << crypted + "\n";
        outfile.close();

        QMessageBox msgBox;
        msgBox.setText("The game was sucessfully saved.");
        msgBox.exec();

        /*
        this->close();
        game_options *ww = new game_options();
        ww->show(); */
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("The user was not added, please try again");
        msgBox.exec();
    }

}

std::string pause::strToBinary(std::string s){
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

std::string pause::p_encriptado(std::string text){

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

