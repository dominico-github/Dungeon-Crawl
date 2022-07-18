#ifndef SLIME_H
#define SLIME_H

#include "Monster.h"

class Slime : public Monster
{
public:
    Slime();
    void battleCry();
    ~Slime();
};

#endif