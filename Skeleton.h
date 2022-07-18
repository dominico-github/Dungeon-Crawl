#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"

class Skeleton : public Monster
{
public:
    Skeleton();
    void battleCry();
    ~Skeleton();
};

#endif