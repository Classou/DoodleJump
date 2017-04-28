#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"


const int dt=0.1;//temps infinitésimal
//======================================
int main(){
    openWindow(width_window,height_window);


    //Création d'une liste de marches
    vector<marche> marches_toutes;
    for(int i=0;i<5;i++){
        marche M(width_plat,height_plat,col);
        marches_toutes.push_back(M);
    }
    for(int i=0;i<marches_toutes.size();i++){
        marches_toutes[i].affiche();
        click();
    }
    IntPoint2 test;

    return 0;
}
