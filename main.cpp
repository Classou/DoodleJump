#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>

void Affichemarches(std::vector<marche> & Marches){
    for (int i=0;i<Marches.size();i++){
        Marches[i].affiche();
    }
}
std :: vector<marche> init_marches(){
     std :: vector<marche> Marches;
     for (int i=0;i<10;i++){
         marche newM=marche(width_plat,height_plat,RED,int(height_window*i/10));
         Marches.push_back(newM);
     }
     return Marches;
}

void Defilementmarches(std::vector<marche> & Marches, float vy){
    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()*5>(rand()%300+5)* height_plat ){
        marche a(width_plat,height_plat,col,0);
        Marches.insert(Marches.begin(),a);
    }

    for (int i=0;i<Marches.size()-1;i++){
        Marches[i].efface();
        Marches[i].defile(vy);
        Marches[i].affiche();

    }
    if(Marches.back().posCoin().y()+height_plat>=height_window){
        Marches.back().efface();
        Marches.pop_back();
    }
    else{
        Marches.back().efface();
        Marches.back().defile(vy);
        Marches.back().affiche();
    }
}


//======================================
int main(){
    //initialisation bonhomme
    jumper bonhomme;

    openWindow(width_window,height_window);

    std :: vector<marche> Marches=init_marches();
    bool pas_perdu=true;


    while(pas_perdu){



        // Gestion du Jumper
//        bonhomme.accelere();

//        bonhomme.efface();
//        bonhomme.bougey();
//        bonhomme.bougex();
//        bonhomme.affiche();

//        bonhomme.test_rebond(Marches);
//        milliSleep(10);


////////////////////////////        version semi finale (wtf "semi finale"???) du main

        Affichemarches(Marches);
        bonhomme.efface();
        bonhomme.accelere();
        bonhomme.bougex();
        if(bonhomme.ascention()){
            if(bonhomme.hautducadre()){
                bonhomme.putposverti(hauteurmax);
                Defilementmarches(Marches,-bonhomme.vitesse());
            }
            else{
                bonhomme.bougey();
            }
        }
        else{
            if(bonhomme.rebond(Marches))
                bonhomme.bougey();
        }
        bonhomme.affiche();
        milliSleep(10);
    }
    return 0;
}
