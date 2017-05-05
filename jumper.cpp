#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"
#include "marche.h"





//**************************************
int Clavier() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}
//======================================
void jumper :: bouge(){
    v+=dt*a;
    y+=(v.y()*dt)/width_window;
    x+=v.x()*dt/width_window;
}

void jumper :: accelere(){
    int k=Clavier();
    if (k==16777234){
        v=2;
    }
    else if (k==16777236){
        v=-2;
    }
    a=(-m*9.81)/m;

}

bool jumper::perdu(){
    if(y < 0)
        return true;
}

void affiche(jumper);
