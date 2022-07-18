#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Entity.h"
#include "Player.h"
#include "Potion.h"

// Function decides whether a potion is dropped after an enemy is killed
// and if it does then will randomly generate either a HP or MP potion

void PotionGen(Potion *Inventory) {
    int potDrop = std::rand() % 3 + 1;
    int potType = std::rand() % 2 + 1;

    // 1 in 3 chance of a potion drop
    if (potDrop == 3) {
        for (int i = 0; i < 3; i++) {
            // Check to see if an inventory slot is empty. If it is, put the potion into the slot
            if (Inventory[i].getPotType() == "Empty") {
               if (potType == 1) {
                    std::cout << "The monster dropped a health potion" << std::endl;
                    Inventory[i].healthPot();
                    break;
                }

                else if (potType == 2) {
                    std::cout << "The monster dropped a mana potion" << std::endl;
                    Inventory[i].manaPot();
                    break;
                }
            }
        }
    }
}