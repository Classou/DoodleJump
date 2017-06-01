#pragma once
#include <iostream>
#include <cmath>
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <vector>
#include <list>
#include <iostream>
#include <cassert>
using namespace std;


//Paramètres initiaux pour les marches, et taille de la fenêtre
const int width_plat=110;
const int height_plat=15;
const int width_window=400;
const int height_window=800;
const float dt=0.1;
const Color col=RED;
const int VXmarche=10;


class marche{
    IntPoint2 pos; //Position
    Color C;   //Couleur
    int w;     //Largeur
    int h;     //Hauteur
    bool mobile;
    int Vx;
public:
    marche(int width, int height, Color col, int y, bool mobi=false); //Génère une marche en bas de l'image, avec position horizontale aléatoire
    marche(); //Constructeur vide pour pouvoir générer un tableau
    byte* load();
    void affiche(byte* sabre);
    void efface(); //Efface la marche
    IntPoint2 posCoin(); //Renvoie la position du coin en haut à gauche
    IntPoint2 dim(); //Renvoie (width,height)
    void defile(float vy,float & score); //Déplace la marche de un cran vers le bas
    marche initMarches(IntPoint2 dimens);
    void deplaceX();
    void changedirection();

};
