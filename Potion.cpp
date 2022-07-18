#include "Potion.h"
#include "Player.h"

#include <iostream>
#include <string>

Potion::Potion() {
    potType = "Empty";
}

void Potion::healthPot() {
    potType = "Health Potion";
}

void Potion::manaPot() {
    potType = "Mana Potion";
}

void Potion::clearPot() {
    potType = "Empty";
}

std::string Potion::getPotType() {
    return potType;
}

void Potion::consume(Player* p1) {
    // If player wants to use a health potion
    if (potType == "Health Potion") {
        p1->setHP(p1->getHP() + 30); // Restores 30 HP

        // Ensures maximum HP is not exceeded
        if (p1->getHP() > p1->getMaxHP()) {
            p1->setHP(p1->getMaxHP());
            std::cout << "The potion has restored you to full HP." << std::endl;
        }
        else {
           std::cout << "Restored 30 HP" << std::endl;
        }
    }
    // If player wants to use a mana potion
    else if (potType == "Mana Potion") {
        p1->setMP(p1->getMP() + 10); // Restores 10 MP

        // Ensures maximum HP is not exceeded
        if (p1->getMP() > p1 ->getMaxMP()) {
            p1->setMP(p1->getMaxMP());
            std::cout << "The potion has restored you to full MP." << std::endl;
        }
        else {
            std::cout << "Restored 10 MP" << std::endl;
        }
    }
}

Potion::~Potion() {

}