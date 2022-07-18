#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "Entity.h"

class Monster : public Entity
{
protected:
    int specialAttackStatus;

public:
    Monster();

    void attack(Entity* enemy);
    bool specialAttack(Entity* enemy);

    ~Monster();
};

#endif