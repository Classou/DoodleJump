#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>


void GraphismeFond(){
    //Couleur de fond
    fillRect(0,0,width_window,height_window,BLACK);

    //Image de fond Star Wars
    int w,h;
    byte* rgb;
    loadColorImage(srcPath("Star_Wars.png"),rgb,w,h);
    NativeBitmap texte(w,h);
    texte.setColorImage(0,0,rgb,w,h);
    putNativeBitmap(0,height_window/5,texte);
}


void Affichemarches(std::vector<marche> & Marches, NativeBitmap sabre){
    for (int i=0;i<Marches.size();i++){
        Marches[i].affiche(sabre);
    }
}
std :: vector<marche> init_marches(IntPoint2 dimens){
     std :: vector<marche> Marches;
     for (int i=0;i<10;i++){
         marche newM=marche(dimens.x(),dimens.y(),RED,int(height_window*i/10),true);
         Marches.push_back(newM);
     }
     return Marches;
}
void bougemarches(vector<marche> &marches){
    for(int i=0;i<marches.size();i++){
        marches[i].changedirection();
        marches[i].deplaceX();
    }
}

void Defilementmarches(std::vector<marche> & Marches, float vy, NativeBitmap sabre){

    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()*5>(rand()%300+5)* height_plat ){
        marche a(width_plat,height_plat,col,0);
        Marches.insert(Marches.begin(),a);
    }

    for (int i=0;i<Marches.size()-1;i++){
        Marches[i].efface();
        Marches[i].defile(vy);
        Marches[i].affiche(sabre);

    }
    if(Marches.back().posCoin().y()+height_plat>=height_window){
        Marches.back().efface();
        Marches.pop_back();
    }
    else{
        Marches.back().efface();
        Marches.back().defile(vy);
        Marches.back().affiche(sabre);
    }
}



//======================================
int main(){
    //initialisation bonhomme
    jumper bonhomme;

    openWindow(width_window,height_window);
    GraphismeFond();

    int score;

    marche image_marche;
    std :: vector<marche> Marches=init_marches(image_marche.dim());
    bool pas_perdu=true;

    NativeBitmap r2d2=bonhomme.load();
    NativeBitmap sabre=image_marche.load();


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

        noRefreshBegin();
        GraphismeFond();
        bougemarches(Marches);
        Affichemarches(Marches,sabre);
        bonhomme.efface();
        bonhomme.accelere();
        bonhomme.bougex();
        if(bonhomme.ascention()){
            if(bonhomme.hautducadre()){
                bonhomme.putposverti(hauteurmax);
                Defilementmarches(Marches,-bonhomme.vitesse(),sabre);
            }
            else{
                bonhomme.bougey();
            }
        }
        else{
            if(bonhomme.rebond(Marches))
                bonhomme.bougey();
        }
        bonhomme.affiche(r2d2);
        score=bonhomme.getScore();
        drawString(0,40,"Score : "+to_string(score),YELLOW,40);
        noRefreshEnd();
        milliSleep(10);
    }
    return 0;
}
