#ifndef JUMPER_H
#define JUMPER_H
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <vector>
#include <list>
#include <iostream>
#include <cassert>
using namespace std;
const float dt=0.1;
class jumper{
    int x;//position du sauteur
    int y; //altitude du sauteur par rapport au milieu de l écran
    float m; //masse du sauteur
    IntPoint2 v; //vitesse du sauteur
    IntPoint2 a; //accélération du sauteur
    public :
        void accelere();
        void bouge();
        void test_rebond(marche []);
};


#endif // JUMPER_H
