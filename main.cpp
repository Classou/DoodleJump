#include <cmath>
#include <ctime>
using namespace std;
#include "marche.h"
#include "jumper.h"
#include <iostream>
#include<vector>
#include<stdlib.h>

byte* loadFond(int&w, int&h){
    byte *fond;
    loadAlphaColorImage(srcPath("immeubles.jpg"),fond,w,h); // Load PNG Image
    return fond;
}

void GraphismeFond(byte* fond, int w, int h){
    //Image de fond Star Wars
    putAlphaColorImage(-w/4,0,fond,w,h,false,0.7);
}


void Affichemarches(std::vector<marche> & Marches, byte* sabre){
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

void Defilementmarches(std::vector<marche> & Marches, float vy,float & score, byte* sabre){
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
    //----------------DEBUT DU JEU--------------------------------
    Window menu=openWindow(1280,720);
    int wdebut, hdebut;
    byte* fonddebut;
    loadColorImage(srcPath("debutetoile.jpg"),fonddebut,wdebut,hdebut);
    putColorImage(0,0,fonddebut,wdebut,hdebut);
    Imagine::drawString(400,200,"Star Wars Jumper",YELLOW,30,true,true,true);
    drawString(500,330,"************",YELLOW,20);
    drawString(450,450,"Make R2D2 climb up !",YELLOW,20,false,false,true);
    drawString(1100,600,"begin : ",YELLOW,20);
    click();
    closeWindow(menu);
    //-----------------JEU-----------------------------------------
    float score=0;
    //initialisation bonhomme
    jumper bonhomme;
    InitRandom();

    Window jeu=openWindow(width_window,height_window);
    int wFond,hFond;
    byte* fond=loadFond(wFond,hFond);
    GraphismeFond(fond,wFond,hFond);
    marche image_marche;

    byte* r2d2=bonhomme.load();
    byte* sabre=image_marche.load();

    std :: vector<marche> Marches=init_marches(image_marche.dim());
    Affichemarches(Marches,sabre);



    while(bonhomme.pasperdu()){


        noRefreshBegin();
        GraphismeFond(fond,wFond,hFond);

        bougemarches(Marches);
        Affichemarches(Marches,sabre);
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

    //--------------------------FIN DU JEU-----------------------------------------------
    openWindow(width_window,height_window);
    byte* fondfin;
    loadColorImage(srcPath("ciel_etoile.jpg"),fondfin,wFond,hFond);
    putColorImage(0,0,fondfin,wFond,hFond);
    Imagine::drawString(20,200,"R2D2 died",YELLOW,30,true,true,true);
    drawString(20,350,"You climbed up to : ",YELLOW,20);
    drawString(20,500,to_string(int(score))+" meters",YELLOW,20);
    click();
    return 0;
}
