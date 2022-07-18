#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Monster.h"
#include "Slime.h"
#include "Skeleton.h"

// Function generates the monster's next attack.

void moveGen(Monster* m1, Player* p1) {
    int monsterMove = std::rand() % 10 + 1; // Generates a number between 1 and 10 (inclusive)

    // Condition ensures a 1 in 10 chance of being a critical hit
    if (monsterMove == 10) {
        m1->specialAttack(p1);
    }

    // Otherwise perform a normal attack
    else {
        m1->battleCry();
        m1->attack(p1);
    }
}