#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>


void GestionDesMarches(std::vector<marche> & Marches){
    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()>8* height_plat){
        marche a(width_plat,height_plat,col);
        Marches.insert(Marches.begin(),a);
    }

    for (int i=0;i<Marches.size()-1;i++){
        Marches[i].efface();
        Marches[i].defile();
        Marches[i].affiche();

    }
    if(Marches.back().posCoin().y()+height_plat>=height_window){
        Marches.back().efface();
        Marches.pop_back();
    }
    else{
        Marches.back().efface();
        Marches.back().defile();
        Marches.back().affiche();
    }
}


//======================================
int main(){
    //initialisation bonhomme
    jumper bonhomme;

    openWindow(width_window,height_window);

    std :: vector<marche> Marches;
    bool pas_perdu=true;
    marche b(width_plat,height_plat,col);
    Marches.push_back(b);

    while(pas_perdu){


        GestionDesMarches(Marches);

        // Gestion du Jumper
        bonhomme.accelere();

        bonhomme.efface();
        bonhomme.bouge();
        bonhomme.affiche();
        milliSleep(100);

    }


    return 0;
}
