#include "marche.h"

marche::marche(int width, int height, Color col, int y, bool mobi){
    w=width;
    h=height;
    C=col;
    pos.x()=rand()%(width_window-width);
    pos.y()=y;
    mobile=mobi;
    if(mobi==true){
        Vx=rand()%VXmarche-(VXmarche/2);
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
NativeBitmap marche::load(){
    byte* rgb;
    loadColorImage(srcPath("Sabre_Laser.png"),rgb,w,h);
    NativeBitmap sabre(w,h);
    sabre.setColorImage(0,0,rgb,w,h);
    return sabre;
}

void marche::affiche(NativeBitmap sabre){
//    fillRect(pos.x()+height_plat/2,pos.y(),w-height_plat,h+1,C);
//    fillCircle(pos.x()+height_plat/2,pos.y()+height_plat/2,height_plat/2,C);
//    fillCircle(pos.x()+width_plat-height_plat/2,pos.y()+height_plat/2,height_plat/2,C);
    putNativeBitmap(pos.x(),pos.y(),sabre);
}

//Effacement de la marche
void marche::efface(){
    fillRect(pos.x()+height_plat/2,pos.y(),w-height_plat,h,BLACK);
}

//Descente de la marche de 1 pixel
void marche::defile(float vy, float &score){
    pos.y()+=int (vy*dt);
    score+=0.1;
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


