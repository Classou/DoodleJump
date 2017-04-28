#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"



//======================================
void jumper :: bouge(){
    v+=dt*a;
    y+=v.y()*dt;
    x+=v.x()*dt;
}
