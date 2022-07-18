#include <iostream>
#include <string>
#include <time.h>

#include "Monster.h"
#include "Slime.h"
#include "Skeleton.h"

// Function randomly generates the monster the player encounters

Monster* monsterGen(Monster *m1) {
    int monsterGenerator = std::rand() % 2 + 1; // Generate number (either 1 or 2)

    if (monsterGenerator == 1) {
        m1 = new Slime();
    }
    else if (monsterGenerator == 2) {
        m1 = new Skeleton();
    }

    else { // Error checking to ensure a monster is properly generated
        std::cout << "!!! MonsterGen.cpp random value error !!!" << std::endl;
    }

    std::cout << "A " << m1->getType() << " appears in front of you!" << std::endl;
    return m1;
}