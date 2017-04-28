#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"
#include "marche.h"




//======================================
void jumper :: bouge(){
    v+=dt*a;
    y+=v.y()*dt;
    x+=v.x()*dt;
}

bool jumper::perdu(){
    if(y < 0)
        return true;
}
