#include "Player.h"
#include "Entity.h"

#include <iostream>

using namespace std;

Player::Player() {
    blockStatus = 0;
}

void Player::attack(Entity *enemy) {
    enemy->setHP(enemy->getHP() - atk);
    cout << "You dealt " << atk << " damage to the " << enemy->getType() << endl;
}

void Player::block(){
    blockStatus = 1;
}

bool Player::specialAttack(Entity *enemy) {
    // Check to see if the player has enough mana to perform the special attack
    if (MP < MPcost) {
        cout << "You don't have enough mana!" << endl;
        return false;
    }

    MP = MP - MPcost; // Special mana drain
    cout << "You consumed " << MPcost << " mana." << endl;
    cout << "Current mana: " << MP << "/" << maxMP << endl;
    enemy->setHP(enemy->getHP() - 2 * atk); // Special attack does double damage
    cout << "You dealt " << 2 * atk << " damage to the " << enemy->getType() << endl;
    return true;
}

void Player::setMP(int newMP) {
    MP = newMP;
}

int Player::getMP() {
    return MP;
}

int Player::getMaxMP() {
    return maxMP;
}

Player::~Player() {

}