#ifndef JUMPER_H
#define JUMPER_H
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <vector>
#include <list>
#include <iostream>
#include <cassert>
#include"marche.h"
using namespace std;
const float G=17;
const int hauteurmax=200;


const int taille_jumper=10;
class jumper{
    int x; //position du sauteur
    int y; //altitude du sauteur par rapport au milieu de l écran
    float vy; //la vitesse verticale du sauteur
    float vx; // la vitesse horizontale du sauteur, elle n'aura que 3 valeurs possible
public :
    jumper(){
        x=width_window/2;
        y=height_window/2;
        vy=-40;
    }
    float donnevy();
    void accelere(); ///acceleration verticale
    void bougex();
    void bougey();
    bool pasperdu();
    bool test_rebond(std :: vector<marche> Marches);/// verifie si le sauteur va rencontrer une marche et change sa vitesse verticale
    void affiche();
    void efface();
    bool hautducadre();
    bool ascention();
    float vitesse();///donne la vitesse verticale
    void putposverti(int posy);
};
#endif //JUMPER_H
