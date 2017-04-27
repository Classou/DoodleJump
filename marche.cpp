#include "marche.h"

marche::marche(int width,int height,Color col){
    w=width;
    h=height;
    C=col;
    pos.x=rand()%(width_window-width);
    pos.y=height_window;
}


marche::marche(){
}

point marche::posCoin(){
    return pos;
}

point marche::dim(){
    point dimens={w,h};
    return dimens;
}

void marche::affiche(){
    fillRect(pos.x+height_plat/2,pos.y,w-height_plat,h,C);
    fillCircle(pos.x+height_plat/2,pos.y+height_plat/2,height_plat/2,C);
    fillCircle(pos.x+width_plat-height_plat/2,pos.y+height_plat/2,height_plat/2,C);
}


