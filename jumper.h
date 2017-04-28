#ifndef JUMPER_H
#define JUMPER_H
#include <vector>
class jumper{
    int x; //position du sauteur
    int z; //altitude du sauteur par rapport au milieu de l écran
    float m; //masse du sauteur
    vector v; //vitesse du sauteur
    float a; //accélération du sauteur
public:
    void accelere();
    void bouge();
    void test_rebond(marche [])
};


#endif //JUMPER_H
