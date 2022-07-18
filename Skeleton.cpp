#include "Skeleton.h"
#include <iostream>
#include <string>

Skeleton::Skeleton() {
    HP = 25;
    maxHP = 25;
    atk = 8;
    type = "Skeleton";
}

void Skeleton::battleCry() {
    std::cout << "The skeleton lunges forward, striking you with a bone club." << std::endl;
}

Skeleton::~Skeleton() {

}
