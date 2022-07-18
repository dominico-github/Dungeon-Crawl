#include "Mage.h"
#include <iostream>

Mage::Mage() {
    MP = 50;
    maxMP = 50;
    HP = 75;
    maxHP = 75;
    atk = 10;
    MPcost = 10;
    type = "Mage";
}

void Mage::battleCry() {
    std::cout << "You cast a spell, it strikes the creature." << std::endl;
}

Mage::~Mage() {

}