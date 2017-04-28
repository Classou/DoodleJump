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
const int width_plat=60;
const int height_plat=6;
const int width_window=250;
const int height_window=500;
const Color col=RED;


class marche{
    IntPoint2 pos; //Position
    Color C;   //Couleur
    int w;     //Largeur
    int h;     //Hauteur
public:
    marche(int width,int height,Color col); //Génère une marche en bas de l'image, avec position horizontale aléatoire
    marche(); //Constructeur vide pour pouvoir générer un tableau
    void affiche(); //Affiche un marche
    void efface(); //Efface la marche
    IntPoint2 posCoin(); //Renvoie la position du coin en haut à gauche
    IntPoint2 dim(); //Renvoie (width,height)
    marche defile(); //Déplace la marche de un cran vers le bas
};
