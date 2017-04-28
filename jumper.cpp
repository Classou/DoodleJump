#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"
#include "marche.h"




//======================================
void jumper :: bouge(){
    v+=dt*a;
    y+=(v.y()*dt)/width_window;
    x+=v.x()*dt/width_window;
}
void jumper :: accelere(){

}

bool jumper::perdu(){
    if(y < 0)
        return true;
}
