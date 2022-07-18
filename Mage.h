#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player
{
public:
    Mage();
    void battleCry();
    ~Mage();
};

#endif