#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"



//======================================
void jumper :: bouge(){
    v+=dt*a;
    if(x<width_window)
    y+=v.y()*dt;
    x+=v.x()*dt;

}
