#include <cmath>
#include <ctime>
using namespace std;
#include "jumper.h"
#include "marche.h"
#include <iostream>
using namespace std;



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

float jumper::donnevy(){
    return vy;
}

void jumper::bougex(){// bouge horizontalement
    int k=Clavier();
    if (k==KEY_LEFT){
        vx=-VX;
    }
    if(k==KEY_RIGHT){
        vx=VX;
    }
    if(k==0){// demander a Monasse comment on fait pour gerer mieux les appuie long pour les touches
        vx=0;
    }
    x+=int(vx*dt);
}
void jumper::bougey(){
    y=y+vy*dt;
}


void jumper :: accelere(){// acceleration verticale
    vy=vy+G*dt;
}

bool jumper::ascention(){
    return (vy<0);
}

bool jumper::hautducadre(){
    return (y+vy*dt<hauteurmax);
}

bool jumper::pasperdu(){
    if(y+vy*dt < height_window)
        return true;
    else
        return false;
}

float jumper:: vitesse(){
    return vy;
}

void jumper::putposverti(int posy){
    y=posy;
}

void jumper::affiche() {
//    fillRect(x,y,10,10,BLUE);
    byte* rgb;
    loadColorImage(srcPath("Yoda.png"),rgb,w,h);
    NativeBitmap yoda(w,h);
    yoda.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(x-w/2,y-h,yoda);
}
void jumper::efface(){
    fillRect(x-w/2,y-h,w,h,BLACK);
}
bool jumper::rebond(const std :: vector<marche> &Marches){
    int x_C;
    int y_C;
    int x_D;
    int y_D;
    int x_A;
    int y_A;
    int x_B;
    int y_B;

    bool proche=false;
    int n=Marches.size();
    marche newmarch;
    for (int i=0; i<n;i++){
        newmarch=Marches[i];
        x_C=newmarch.posCoin().x();
        y_C=newmarch.posCoin().y();
        x_D=x_C+newmarch.dim().x();
        y_D=y_C+newmarch.dim().y();
        x_A=x;
        y_A=y+taille_jumper;
        x_B=x+vx*dt;
        y_B=y-vy*dt;

        float t=(y_C-y_A)/(y_B-y_A);
        int x_M=(x_B-x_A)*t+x_A;
        if(y_B<y_C && y_A>y_C && x_C<x_M && x_M<x_D){
                //proche=true;
                //cout<<"plat"<<x_plateforme<<endl;
                //cout<<"jumper"<<x<<endl;
                x=x_M;
                y=y_C-taille_jumper;
                vy=-VY;
                cout<<"true"<<endl;
        }
    }

}


//Score
int jumper::getScore(){
    return score;
}

void jumper::setScore(){
    if(ascention() && hautducadre())
        score-=vy;
}
