#include <iostream>
#include "Entity.h"
#include "Monster.h"
#include "Slime.h"
#include "Skeleton.h"

int main () {

    Monster *e1 = new Slime();
    Monster *e2 = new Skeleton();

    int startingHP = e2->getHP();
    e1->attack(e2);
    if (e2->getHP() == startingHP) {
        std::cout << "Error with attack(). No damage dealt" << std::endl;
    }


    if (e1->specialAttack(e2) != true) {
        std::cout << "Error with specialAttack()" << std::endl;
    }

    return 0;
}