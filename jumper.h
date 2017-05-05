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
#include "marche.h"
const float dt=0.1;
class jumper{
    int x; //position du sauteur
    int y; //altitude du sauteur par rapport au milieu de l écran
    float m; //masse du sauteur
    IntPoint2 v; //vitesse du sauteur
    IntPoint2 a; //accélération du sauteur
public :
    jumper(){
        x=width_window/2;
        y=height_window/2;
        m=1;
        v=0;
        a=0;
    }
    void accelere();
    void bouge();
    bool perdu();
    void test_rebond(std :: vector<marche> Marches);
    void affiche();
    void efface();
};
#endif //JUMPER_H
