#include "Monster.h"
#include "Slime.h"

#include <iostream>
#include <string>

Monster::Monster() {
    specialAttackStatus = 0;
}

void Monster::attack(Entity *enemy) {
    // Special attack - Deals double the monster's ATK value
    if (specialAttackStatus == 1) {
        atk = atk * 2;
    }

    // Check to see if the player is blocking
    if (enemy->getBlockStatus() == 1) {
        enemy->setHP(enemy->getHP() - atk/2); // Attack damage is halved if player is blocking
        std::cout << "You succesfully blocked the enemy attack." << std::endl;
        std::cout << "You took a reduced " << atk/2 << " damage." << std::endl;
    }

    // Otherwise damage is normal
    else {
        enemy->setHP(enemy->getHP() - atk);
        std::cout << "You took " << atk << " damage." << std::endl;
    }

    enemy->setBlockStatus(0); // Always reset player block status to prevent the effect from lingering over turns

    // Reset stats to normal after special attack
    if (specialAttackStatus == 1) {
        atk = atk / 2;
        specialAttackStatus = 0;
    }
}

// Special attack - Monster charges up to deal 2x damage with its next attack
bool Monster::specialAttack(Entity* enemy) {
    // Check to see if the monster's previous move was a special attack.
    // If so, perform the attack (instead of charging up twice)
    if (specialAttackStatus == 1) {
        attack(enemy);
        return true;
    }

    enemy->setBlockStatus(0); // Always reset player block status to prevent the effect from lingering over turns

    std::cout << "The enemy appears to be charging up its next attack" << std::endl;
    specialAttackStatus = 1; // Sets up next attack to be
    return true;
}

Monster::~Monster() {

}
