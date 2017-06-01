#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>
#include<stdlib.h>


NativeBitmap loadFond(){
    int wFond, hFond;
    byte* rgb;
    loadColorImage(srcPath("immeubles.jpg"),rgb,wFond,hFond);
    NativeBitmap fond(wFond,hFond);
    fond.setColorImage(0,0,rgb,wFond,hFond);
    return fond;
}

void GraphismeFond(NativeBitmap fond){
    //Couleur de fond
    fillRect(0,0,width_window,height_window,BLACK);

    //Image de fond Star Wars

    putNativeBitmap(0,0,fond);
}


void Affichemarches(std::vector<marche> & Marches, NativeBitmap sabre){
    for (int i=0;i<Marches.size();i++){
        Marches[i].affiche(sabre);
    }
}
std :: vector<marche> init_marches(IntPoint2 dimens){
     std :: vector<marche> Marches;
     int k;
     for (int i=0;i<10;i++){
         k=rand()%2;
         marche newM;
         if(k==0){
             newM=marche(dimens.x(),dimens.y(),RED,int(height_window*i/10),true);
         }
         else{
             newM=marche(dimens.x(),dimens.y(),RED,int(height_window*i/10),false);
         }
         Marches.push_back(newM);
     }
     return Marches;
}
void bougemarches(vector<marche> & marches){
    for(int i=0;i<marches.size();i++){
        marches[i].changedirection();
        marches[i].deplaceX();
    }
}

void Defilementmarches(std::vector<marche> & Marches, float vy,float & score, NativeBitmap sabre){
    //Gère un vecteur de marches, qui en entrée n'est pas vide
    if(((Marches[0]).posCoin()).y()*5>(rand()%300+5)* height_plat ){
        int k=rand()%2;
        bool bouge=false;
        if(k==1){
            bouge=true;
        }
        marche a(width_plat,height_plat,RED,0,bouge);


        Marches.insert(Marches.begin(),a);
    }

    for (int i=0;i<Marches.size()-1;i++){
//        Marches[i].efface();
        Marches[i].defile(vy,score);
//        Marches[i].changedirection();
//        Marches[i].deplaceX();
//        Marches[i].affiche(sabre);


    }
    if(Marches.back().posCoin().y()+height_plat>=height_window){
//        Marches.back().efface();
        Marches.pop_back();
    }
    else{
//        Marches.back().efface();
        Marches.back().defile(vy,score);
//        Marches.back().changedirection();
//        Marches.back().deplaceX();
//        Marches.back().affiche(sabre);
    }
}

void InitRandom()
{
    srand((unsigned int)time(0));
}



//======================================
int main(){
    float score=0;
    //initialisation bonhomme
    jumper bonhomme;
    InitRandom();

    Window jeu=openWindow(width_window,height_window);

    NativeBitmap fond=loadFond();
    GraphismeFond(fond);
    marche image_marche;

    NativeBitmap r2d2=bonhomme.load();
    NativeBitmap sabre=image_marche.load();


    std :: vector<marche> Marches=init_marches(image_marche.dim());
    Affichemarches(Marches,sabre);



    while(bonhomme.pasperdu()){


        noRefreshBegin();
        GraphismeFond(fond);

        bougemarches(Marches);
        Affichemarches(Marches,sabre);
//        bonhomme.efface();
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

    drawString(20,200,"R2D2 died",YELLOW,30);
    drawString(20,500,"You climbed up to : "+to_string(int(score))+" meters",YELLOW,20);
    click();
    return 0;
}
