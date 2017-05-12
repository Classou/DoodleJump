#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>

void GraphismeFond(){
    //Couleur de fond
    Color rosepale;
    rosepale.r()=255;
    rosepale.g()=155;
    rosepale.b()=170;
    fillRect(0,0,width_window,height_window,rosepale);

    //Image de fond de coeur bonbons
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("Coeur2.bmp"),rgb,w,h);
    NativeBitmap coeur(w,h);
    coeur.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(0,height_window/5,coeur);
}

void GestionDesMarches(std::vector<marche> & Marches, float vy){
    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()*5>(rand()%300+5)* height_plat ){
        marche a(width_plat,height_plat,col);
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
    GraphismeFond();

    std :: vector<marche> Marches;
    bool pas_perdu=true;
    marche b(width_plat,height_plat,col);
    Marches.push_back(b);

    while(pas_perdu){

        noRefreshBegin();
        GraphismeFond();

        GestionDesMarches(Marches,10);

        // Gestion du Jumper
        bonhomme.accelere();
        bonhomme.efface();
        bonhomme.bougey();
        bonhomme.bougex();
        bonhomme.affiche();
        noRefreshEnd();
        milliSleep(10);


// //////////////////////////        version semi finale du main
//        bonhomme.efface();
//        bonhomme.accelere();
//        bonhomme.bougex();
//        if(bonhomme.ascention()){
//            if(bonhomme.hautducadre()){
//                bonhomme.putposverti(hauteurmax);
//                GestionDesMarches(Marches,bonhomme.vitesse());
//            }
//            else{
//                bonhomme.bougey();
//            }
//        }
//        else{
//            if(bonhomme.test_rebond(Marches))
//            bonhomme.bougey();
//        }
//        bonhomme.affiche();
//        milliSleep(10);


    }


    return 0;
}
