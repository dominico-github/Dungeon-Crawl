#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    Warrior();
    void battleCry();
    ~Warrior();
};

#endif