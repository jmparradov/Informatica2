#include "mainwindow.h"
#include "game_options.h"
#include "ui_load.h"
#define n 4

load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/sources/menus/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QRect geo = this->geometry();
    this->setFixedSize(geo.width(),geo.height());

    saved_games = get_userinfo();
    std::vector<std::string>::iterator it = saved_games.begin();

    while(it != saved_games.end()){
        std::vector <std::string> user_content = split_text(*it);
        std::string game_name =  user_content[0];
        QString game_name_q = QString::fromStdString(game_name);
        qDebug() << "load " <<game_name_q;
        ui->SavedList->addItem(game_name_q);

        it++;
    }
}

load::~load()
{
    delete ui;
}

std::vector <std::string> load::split_text(std::string value){
    std::stringstream test(value);
    std::string segment;
    std::vector<std::string> seglist;
    while(getline(test, segment, ','))
    {
       seglist.push_back(segment);
    }
    return seglist;
}

void load::on_pushButton_clicked()
{
    QListWidgetItem *list = ui->SavedList->currentItem();
    int row = ui->SavedList->currentRow();
    qDebug() << list->text();

    std::string item = saved_games[row];

    QString item_q = QString::fromStdString(item);
    qDebug()<<item_q;

    std::vector <std::string> loaded  = split_text(item);
    // name + world_s + "," + difficulty_s + "," + v_s + "," + x_s + "," + y_s +


    std::string difficult_s = loaded[2];
    QString difficult = QString::fromStdString(difficult_s);

    std::string world_s = loaded[1];
    QString world = QString::fromStdString(world_s);

    QString xs = QString::fromStdString(loaded[4]);
    double x1 = xs.toDouble();
    qDebug() << "x :" <<x1;
    QString ys = QString::fromStdString(loaded[5]);
    double y1 = ys.toDouble();
    qDebug() << "y :" <<y1;
    QString v1s = QString::fromStdString(loaded[3]);
    double v1 = v1s.toDouble();
    qDebug() << "v :" <<v1;

    //loading game information
    MainWindow *ww = new MainWindow(difficult, world,1,x1,y1,0,0,v1);
    ww->show();
    this->close();


}

std::vector <std::string> load:: get_userinfo(){
std::string data = "";
std::string ndata = "";
std::vector<std::string> seglist;

   std::ifstream infile;
   infile.open("../Gravity_Bike/sources/users/saved.txt");

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

std::string load::p_desencriptado(std::string binary){
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

std::string load::BinaryTostr(std::string s){
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

void load::on_backbutton_clicked()
{
    game_options *ww = new game_options();
    ww->show();
    this->close();
}
