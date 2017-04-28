#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include <iostream>
#include<list>



//======================================
int main(){
    openWindow(width_window,height_window);

    std :: list<marche> Marches;
    bool pas_perdu=true;


    while(pas_perdu){

        if(Marches[Marches.begin()]>4*height_plat){
            marche a(width_plat,height_plat,col);
            Marches.push_front(a);
        }

        for (int i=0;i<Marches.size()-1;i++){
            Marches[i].defile();
            Marches[i].affiche();
        }
        if(Marches[Marches.size()].posCoin().y+height_plat>=height_window){
            Marches.pop_back();
        }
        else{
            Marches[Marches.size()].defile();
            Marches[Marches.size()].affiche();
        }

    }


    return 0;
}
