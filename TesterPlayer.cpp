#include <iostream>

#include "Entity.h"
#include "Player.h"
#include "Warrior.h"
#include "Monster.h"
#include "Skeleton.h"

int main () {
    Player* t1 = new Warrior();
    Monster* t3 = new Skeleton();

    double h1 = t1->getHP();
    t3->attack(t1);
    double h2 = t1->getHP();

    if (h1 == h2){
        std::cout << "ERROR, player not recieving damage!" << std::endl;
    }

    t1->block();
    t3->attack(t1);
    double h3 = t1->getHP();

    if (h3 != h2-(h1-h2)/2){
        std::cout << "ERROR, block not halving damage!" << std::endl;
    }

    h1 = t3->getHP(); //start hp
    t1->attack(t3);
    h2 = t3->getHP(); //hp after attack
    t1->specialAttack(t3);
    h3 = t3->getHP(); //hp after special
    double h4 = h2 - h1; // difference in hp after normal attack

    double h5 = h3 - h2; // different in hp after special attack

    if (h5 != 2*h4){
        std::cout << "ERROR, special not dealing correct damage!" << std::endl;
    }

    return 0;
}