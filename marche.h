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

const int width_plat=50;
const int height_plat=6;
const int width_window=250;
const int height_window=500;
const Color col=RED;

struct point {
    int x,y;
};

class marche{
    point pos;
    Color C;
    int w;
    int h;
public:
    marche(int width,int height,Color col);
    marche();
    void affiche();
    point posCoin();
    point dim();
};
