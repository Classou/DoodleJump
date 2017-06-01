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
    if(x<=0){
        x=width_window+x;

    }
    x=x%width_window;
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
    if(y+vy*dt <= height_window)
        return true;
    if(y>height_window)
        return false;
    cout<<y<<endl;
}

float jumper:: vitesse(){
    return vy;
}

void jumper::putposverti(int posy){
    y=posy;
}

NativeBitmap jumper::load(){
    byte* rgb;
    loadColorImage(srcPath("r2d2.png"),rgb,w,h);
    NativeBitmap r2d2(w,h);
    cout<<"w : "<<w<<endl;
    cout<<"h : "<<h<<endl;
    r2d2.setColorImage(0,0,rgb,w,h);
    return r2d2;
}

void jumper::affiche(NativeBitmap r2d2){
    putNativeBitmap(x-w/2,y-h,r2d2);
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
    int x_A2;
    int x_M2;
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
        x_A2=x+jumper_width;
        y_A=y+jumper_heigth;
        x_B=x+vx*dt;
        y_B=y-vy*dt;

        float t=(y_C-y_A)/(y_B-y_A);
        int x_M=(x_B-x_A)*t+x_A;
        int x_M2=(x_B-x_A2)*t+x_A2;

        if((y_B<y_C && y_A>y_C && x_C<x_M && x_M<x_D)||(y_B<y_C && y_A>y_C && x_C<x_M2 && x_M2<x_D)){
                //proche=true;
                //cout<<"plat"<<x_plateforme<<endl;
                //cout<<"jumper"<<x<<endl;
                x=x_M;
                y=y_C-jumper_heigth;
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
