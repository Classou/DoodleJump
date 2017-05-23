#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>
#include<stdlib.h>

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

void Defilementmarches(std::vector<marche> & Marches, float vy,float & score, NativeBitmap sabre){
    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()*5>(rand()%300+5)* height_plat ){
        marche a(width_plat,height_plat,col,0);
        Marches.insert(Marches.begin(),a);
    }

    for (int i=0;i<Marches.size()-1;i++){
        Marches[i].efface();
        Marches[i].defile(vy,score);
        Marches[i].affiche(sabre);


    }
    if(Marches.back().posCoin().y()+height_plat>=height_window){
        Marches.back().efface();
        Marches.pop_back();
    }
    else{
        Marches.back().efface();
        Marches.back().defile(vy,score);
        Marches.back().affiche(sabre);
    }
}



//======================================
int main(){
    float score=0;
    //initialisation bonhomme
    jumper bonhomme;

    Window jeu=openWindow(width_window,height_window);
    GraphismeFond();
    marche image_marche;
    std :: vector<marche> Marches=init_marches(image_marche.dim());
    bool pas_perdu=true;

    NativeBitmap r2d2=bonhomme.load();
    NativeBitmap sabre=image_marche.load();


    while(bonhomme.pasperdu()){



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
                Defilementmarches(Marches,-bonhomme.vitesse(),score,sabre);
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
        drawString(0,40,"Score : "+to_string(int(score)),YELLOW,40);
        noRefreshEnd();
        milliSleep(1);

    }
    closeWindow(jeu);
    openWindow(width_window,height_window);

    drawString(20,200,"GAME OVER, score :"+to_string(int(score)),YELLOW,30);
    click();
    return 0;
}
