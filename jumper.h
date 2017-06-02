#pragma once
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
const float G=10;
const int hauteurmax=200;
const int VX=30;
const int VY=70;


const int jumper_width=0;
const int jumper_heigth=0;
class jumper{
    vector<int>ListeTouchesEnfoncees;
    int x; //position du sauteur
    int y; //altitude du sauteur par rapport au milieu de l écran
    float vy; //la vitesse verticale du sauteur
    float vx; // la vitesse horizontale du sauteur, elle n'aura que 3 valeurs possible
    int w;
    int h;
    int score;
public :
    jumper(){
        x=width_window/2;
        y=height_window/2;
        vy=-40;
        score=0;
    }
    float donnevy();
    void accelere(); ///acceleration verticale
    void bougex();
    void bougey();
    bool pasperdu();
    byte* load();
    void affiche(byte* r2d2);

    bool rebond(const std :: vector<marche> &Marches); //verifie si le sauteur va rencontrer une marche et change sa vitesse verticale
    void affiche();
    bool hautducadre();
    bool ascention();
    float vitesse();///donne la vitesse verticale
    void putposverti(int posy);
    int getScore();
    void setScore();
};
#endif //JUMPER_H
