#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"


const int dt=0.1;//temps infinitésimal
//======================================
int main(){
    openWindow(width_window,height_window);


    //Création d'une liste de marches
    int nb_marches=0;
    marche* marches_toutes=new marche[100];
    for(int i=0;i<5;i++){
        marche M(width_plat,height_plat,col);
        nb_marches+=1;
        marches_toutes[i]=M;
    }
    for(int i=0;i<nb_marches;i++){
        marches_toutes[i].affiche();
        click();
    }


    return 0;
}
