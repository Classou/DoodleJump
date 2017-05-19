#include "marche.h"

marche::marche(int width, int height, Color col, int y, bool mobi){
    w=width;
    h=height;
    C=col;
    pos.x()=rand()%(width_window-width);
    pos.y()=y;
    mobile=mobi;
    if(mobi==true){
        Vx=rand()%VX-(VX/2);
    }
    else Vx=0;
}

//Cobstructeur vide pour les tableaux
marche::marche(){
}

//Accès à la position du coin en haut à gauche
IntPoint2 marche::posCoin(){
    return pos;
}

//Acces aux dimensions de la marche (width, height)
IntPoint2 marche::dim(){
    IntPoint2 dimens(w,h);
    return dimens;
}

//Affichage de la marche
void marche::affiche(){
    fillRect(pos.x()+height_plat/2,pos.y(),w-height_plat,h+1,C);
    fillCircle(pos.x()+height_plat/2,pos.y()+height_plat/2,height_plat/2,C);
    fillCircle(pos.x()+width_plat-height_plat/2,pos.y()+height_plat/2,height_plat/2,C);
}

//Effacement de la marche
void marche::efface(){
    fillRect(pos.x()+height_plat/2,pos.y(),w-height_plat,h+1,WHITE);
    fillCircle(pos.x()+height_plat/2,pos.y()+height_plat/2,height_plat/2,WHITE);
    fillCircle(pos.x()+width_plat-height_plat/2,pos.y()+height_plat/2,height_plat/2,WHITE);
}

//Descente de la marche de 1 pixel
void marche::defile(float vy){
    pos.y()+=int (vy*dt);
}

void marche::deplaceX(){
    pos.x()+=int(Vx*dt);
}

void marche::changedirection(){
    if(Vx>0 && pos.x()+int(Vx*dt)+width_plat>width_window){
        Vx=-Vx;
    }
    if(Vx<0 && pos.x()+int(Vx*dt)<0){
        Vx=-Vx;
    }
}

