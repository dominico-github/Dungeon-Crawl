#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
protected:
    int MP;
    int MPcost;
    int maxMP;

public:
    Player();

    void attack(Entity *enemy);
    void block();
    void setMP(int newMP);
    int getMaxMP();
    int getMP();
    bool specialAttack(Entity* enemy);

    ~Player();
};

#endif