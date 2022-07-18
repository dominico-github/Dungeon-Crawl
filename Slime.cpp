#include "Slime.h"
#include <iostream>
#include <string>

Slime::Slime() {
    HP = 40;
    atk = 6;
    maxHP = 40;
    type = "Slime";
}

void Slime::battleCry() {
    std::cout << "The slime spits a globule of mucus at you!" << std::endl;
}

Slime::~Slime() {

}
