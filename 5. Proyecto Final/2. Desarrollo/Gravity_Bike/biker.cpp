#include "biker.h"
#include "road.h"

#define PI 3.14159265
#define M 80         // Peso Bicicleta kg
#define G 9.89       // gravity m/s^2
#define E 150        // px/m
#define n 4
#define T 1
#define C 0.03

#define worldx 15024
#define worldy 6736

biker::biker(std::map<double, std::vector<double>> line, QString difficult_s, QString world_s, int  players_s, QMainWindow *mainW_s, int n_player_s,
             double x0, double y0, double v0_s)
{

    width = 90;
    height = 59;
    Break = false;
    flying = false;
    jump = false;
    speed = false;
    vo = v0_s;
    lines = line;
    paused = false;
    difficult = difficult_s;
    world = world_s;
    players = players_s;
    mainW = mainW_s;
    n_player = n_player_s;

    //qDebug() << "lines" <<lines;

    //draw it and locate
    QPixmap pim(":/sources/character/c1.png");
    setPixmap(pim);
    setTransformOriginPoint(width/2,height/2);
    setPos(x0,y0);

    //make item  focusable
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //connect

    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(T);
}

void biker::keyPressEvent(QKeyEvent *event){
    if (n_player ==1){
        if (event->key() == Qt::Key_W){
            // Up action - jump
            if(!flying){
                jump = true;
            }
        }

        else if (event->key() == Qt::Key_D){
            // Right action - speed up
            if(!flying){
                speed = true;
            }
            else {
                teta_aux += 5;
                setRotation(teta_aux);
            }
        }

        else if (event->key() == Qt::Key_A){
            // Left Action - Break
            if(!flying){
                Break = true;
            }
            else {
                teta_aux -= 5;
                setRotation(teta_aux);
            }
        }
    }

    else if (n_player == 2){
        if (event->key() == Qt::Key_I){
            // Up action - jump
            if(!flying){
                jump = true;
            }
        }

        else if (event->key() == Qt::Key_L){
            // Right action - speed up
            if(!flying){
                speed = true;
            }
            else {
                teta_aux += 5;
                setRotation(teta_aux);
            }
        }

        else if (event->key() == Qt::Key_J){
            // Left Action - Break
            if(!flying){
                Break = true;
            }
            else {
                teta_aux -= 5;
                setRotation(teta_aux);
            }
        }

    }

    if(event->key() == Qt::Key_Space){

        if (!paused){
            timer->stop();

            QGraphicsTextItem *text;
            pause *ww = new pause(mainW);
            ww->show();
            text = scene()->addText("Press space to continue");
            text->setPos(x()-150, y()-100);
            text->setDefaultTextColor(Qt::black);
            QFont serifFont("Times", 40, QFont::Bold);
            text->setFont(serifFont);

            QString x_qs = QString::number(x());
            QString y_qs = QString::number(y());
            QString v_qs = QString::number(vo);


            std::string world_qs = world.toUtf8().constData();
            std::string difficulty_qs = difficult.toUtf8().constData();

            std::string x_s = x_qs.toUtf8().constData();
            std::string y_s = y_qs.toUtf8().constData();
            std::string v_s = v_qs.toUtf8().constData();

            append_users_info(world_qs + "," + difficulty_qs + "," + v_s + "," + x_s + "," + y_s);
            paused = true;
        }
        else {
            for (QGraphicsItem *list:scene()->items()){
                if (list->type() == 8){
                    scene()->removeItem(list);
                    delete list;
                }
            }

            timer->start(T);
            paused = false;
        }
    }
}

void biker::move(){
    bool collision = checkColliding();
    if (collision && T != 0 && players == 1){
        timer->stop();
        game_over *ww = new game_over(difficult, world,players, mainW);
        ww->show();

    }

    // acceleration components
    double a = G*sin(teta*PI/180)-C*pow(vo,2);

    double tp = (1e-3)*T;
    double yp = (vo*tp)+(0.5*a*tp*tp);

    double dx = yp*cos(teta*PI/180)*E;
    double dy = yp*sin(teta*PI/180)*E;

    int tries = 0;

    vo += a*(tp);


    setPos(x()+dx,y()+dy);

    // check if player reached the end
    if(x()>= worldx){
        timer->stop();
        win *ww = new win(mainW, n_player, difficult, world,players);
        ww->show();
    }

    if(y()>= worldy){
        timer->stop();
        game_over *ww = new game_over(difficult, world,players, mainW);
        ww->show();
    }

    if (n_player ==1){
        QList<QGraphicsView *> views = scene()->views();
        views.at(0)->centerOn(this);
    }

    bool coll = checkrolling(dx);
    //qDebug() << "coll :" <<coll;
    if (coll){
        tries += 1;
    }

    if (tries >0){

        // velocity
        vo -= a*(tp);

        // set character rotation
        setRotation(teta);
        teta_aux = teta;
    }
    else{

        if (teta<90){
            teta += 300*tp;
        }
    }

}

bool biker::checkColliding(){
    bool collided = false;
    for(QGraphicsItem* item: collidingItems()) {
        if (item->type() == 7){
            //qDebug() <<item->type();
            collided = true;
        }
    }
    return collided;
}

bool biker::checkrolling(double dx){

    bool collided = false;
    double tolerance = 3;

    double Bx_min = 0.00;
    double By_min = 0.00;
    double r_min = 1e6;

    double px_min = 0.00;
    double py_min = 0.00;

    //qDebug() << "lines" <<lines;
    for (std::map<double, std::vector<double>>::iterator it = lines.begin(); it != lines.end(); it++ ){
        double Bx = it->first;
        double By = it->second[0];
        double px = x() + (width/2);
        double py = y() + (height/2);

        double r = sqrt(pow((Bx-px),2) + pow((By-py),2));
        //qDebug() << "r i" <<r;
        if (r < r_min){
            r_min = r;

            Bx_min = Bx;
            By_min = By;

            px_min = px;
            py_min = py;
        }
    }

    //qDebug() << "r min :" <<r_min;

    if (abs(r_min - height/2) < tolerance){

        teta = lines[Bx_min][1];

        if (!jump){
            if (Break){
                vo -= 1;
                qDebug() <<"break";
                Break = false;
            }

            if (speed){
                vo += 0.2;
                qDebug() <<"speed up";
                speed = false;
            }

            setPos(x()+dx,By_min-(height+tolerance));
            flying = false;
        }
        else {
            flying = true;
            setRotation(teta);
            teta_aux = teta;

            teta = -30;
            jump = false;
            qDebug() <<"jumping ";

            return false;
        }

        if (n_player ==1){
            QList<QGraphicsView *> views = scene()->views();
            views.at(0)->centerOn(this);
        }
        return true;

    }

    return collided;
}

void biker::append_users_info(std::string input){
    std::string crypted = "";
    crypted = p_encriptado(input);
    std::ofstream outfile;

    outfile.open("../Gravity_Bike/sources/users/temp.txt");

    bool success = outfile.is_open();

    if (success){
        outfile << crypted + "\n";
        outfile.close();
    }
}

std::string biker::strToBinary(std::string s){
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

std::string biker::p_encriptado(std::string text){

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
