#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
protected:
    double HP;
    int maxHP;
    int blockStatus;
    int atk;
    std::string type;
public:
    Entity();

    double getHP();
    void setHP(double newHP);
    int getBlockStatus();
    int getMaxHP();
    void setBlockStatus(int newBlockStatus);
    std::string getType();

    virtual void attack(Entity* enemy) = 0;
    virtual void battleCry() = 0;
    virtual bool specialAttack(Entity* enemy) = 0;

    ~Entity();
};



#endif