#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include <iostream>
#include<vector>


const int dt=0.1;//temps infinitésimal
//======================================
int main(){
    openWindow(width_window,height_window);

    std :: vector<marche> Marches;
    bool pas_perdu=true;
    marche b(width_plat,height_plat,col);
    Marches.push_back(b);

    while(pas_perdu){

        if(((Marches[0]).posCoin()).y()>4* height_plat){
            marche a(width_plat,height_plat,col);
            Marches.insert(Marches.begin(),a);
        }

        for (int i=0;i<Marches.size()-1;i++){
            Marches[i].defile();
            Marches[i].affiche();
        }
        if(Marches.back().posCoin().y()+height_plat>=height_window){
            Marches.pop_back();
        }
        else{
            Marches.back().defile();
            Marches.back().affiche();
        }
        milliSleep(100);
    }


    return 0;
}
