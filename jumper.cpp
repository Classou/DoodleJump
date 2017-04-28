#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"



//======================================
void jumper :: bouge(){
    v+=dt*a;
    y+=(v.y()*dt)/width_window;
    x+=v.x()*dt/width_window;
}
void jumper :: accelere(){

}
