#ifndef POTION_H
#define POTION_H

#include "Player.h"
#include <string>

class Potion {
public:
    Potion();

    std::string potType;
    void healthPot();
    void manaPot();
    void clearPot();
    std::string getPotType();
    void consume(Player *p1);
    ~Potion();
};

#endif