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
//    do {
//        getEvent(0,e);
//        if (e.type==EVT_KEY_ON)
//            return e.key;
//    } while (e.type!=EVT_NONE);
//    return 0;

    getEvent(0,e);
    if(e.type==EVT_KEY_ON)
        return e.key;
//    if(e.type==EVT_NONE)
//        return 0;
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

void jumper::affiche(){
    fillRect(x,y,taille_jumper,taille_jumper,BLUE);
}
void jumper::efface(){
    fillRect(x,y,taille_jumper,taille_jumper,WHITE);
}
bool jumper::test_rebond(std :: vector<marche> Marches){
    int x_plateforme;
    int y_plateforme;
    bool proche=false;
    int n=Marches.size();
    marche newmarch;
    for (int i=0; i<n;i++){
        newmarch=Marches[i];
        x_plateforme=newmarch.posCoin().x();
        y_plateforme=newmarch.posCoin().y();

        if (abs(y_plateforme-y)<3){

            if (x_plateforme<x && x<x_plateforme+width_plat){
                proche=true;
                cout<<"plat"<<x_plateforme<<endl;
                cout<<"jumper"<<x<<endl;
                vy=-VY;
                cout<<"true"<<endl;
            }
        }
//        Marches.push_back(newmarch);
    }

}
