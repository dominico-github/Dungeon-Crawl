#include "Entity.h"

#include <iostream>
#include <string>

Entity::Entity() {

}

double Entity::getHP() {
    return HP;
}

void Entity::setHP(double pHP) {
    HP = pHP;
}

std::string Entity::getType() {
    return type;
}

int Entity::getBlockStatus() {
    return blockStatus;
}

int Entity::getMaxHP() {
    return maxHP;
}

void Entity::setBlockStatus(int newBlockStatus) {
    blockStatus = newBlockStatus;
}


Entity::~Entity() {

}