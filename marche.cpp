#include "marche.h"

marche::marche(int width,int height,Color col){
    w=width;
    h=height;
    C=col;
    pos.x()=rand()%(width_window-width);
    pos.y()=0;
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
void marche::affiche(){
    fillRect(pos.x()+height_plat/2,pos.y(),w-height_plat,h+1,WHITE);
    fillCircle(pos.x()+height_plat/2,pos.y()+height_plat/2,height_plat/2,WHITE);
    fillCircle(pos.x()+width_plat-height_plat/2,pos.y()+height_plat/2,height_plat/2,WHITE);
}

//Descente de la marche de 1 pixel
marche marche::defile(){
    marche nv;
    IntPoint2 p(pos.x(),pos.y()+1);
    nv.pos=p;
    nv.C=C;
    nv.w=w;
    nv.h=h;
    return nv;
}


