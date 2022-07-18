#include "Warrior.h"
#include <iostream>

Warrior::Warrior() {
    MP = 10;
    maxMP = 10;
    HP = 100;
    maxHP = 100;
    atk = 15;
    MPcost = 5;
    type = "Warrior";
}

void Warrior::battleCry() {
    std::cout << "You swing your weapon at the creature, striking it." << std::endl;
}

Warrior::~Warrior() {

}