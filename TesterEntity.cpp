#include <iostream>
#include "Entity.h"
#include "Monster.h"
#include "Slime.h"

int main () {

    Entity *e1 = new Slime();

    if (e1->getType() != "Slime") {
        std::cout << "Error with getType()" << std::endl;
    }

    e1->setHP(1000);
    if (e1->getHP() != 1000) {
        std::cout << "Error with setHP()" << std::endl;
    }

    else if (e1->getHP() != 1000) {
        std::cout << "Error with getHP()" << std::endl;
    }

    return 0;
}