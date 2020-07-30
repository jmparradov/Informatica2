#include "falling.h"
#define E 150        // px/m
#define T 1          // unidad de tiempo en ms
#define PI 3.14159265

falling::falling()
{
    auto Go = bind(std::uniform_int_distribution<>(5,20),std::default_random_engine());
    G = Go;
    vo = 0;
}

//falling.cpp:9:9: error: assigning to 'int' from incompatible type 'std::_Bind<std::uniform_int_distribution<int> (std::linear_congruential_engine<unsigned int, 16807, 0, 2147483647>)>'

void falling::move(){

    // acceleration components
    double a = G*sin(teta*PI/180);

    double tp = (1e-3)*T;
    double yp = (vo*tp)+(0.5*a*tp*tp);

    double dx = yp*cos(teta*PI/180)*E;
    double dy = yp*sin(teta*PI/180)*E;

    vo += a*(tp);
    setPos(x()+dx,y()+dy);
}
