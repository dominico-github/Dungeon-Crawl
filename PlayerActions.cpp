#include <iostream>
#include <string>

#include "Player.h"
#include "Potion.h"
#include "Monster.h"

using namespace std;

void playerActions(string pInput, Monster* m1, Player* p1, Potion* Inventory, int defeatcounter) {
    cout << endl;
    // Player action: help
    if (pInput == "help" || pInput == "Help") {
        cout << "-------------------------------------" << endl;
        cout << "The available commands and their functionality are: " << endl;
        cout << endl;
        cout << "Attack: perform a basic attack" << endl;
        cout << "Special: perform a special attack, consuming MP to deal double damage" << endl;
        cout << "Block: perform a block, halves incoming damage for a turn" << endl;
        cout << "Stats: displays your current stats and inventory" << endl;
        cout << "Potion: consume a potion to restore your HP or MP" << endl;
        cout << "Help: returns a list of available commands" << endl;
        cout << "-------------------------------------" << endl;
    }

    // Player action: stats
    else if (pInput == "stats" || pInput == "Stats") {
        cout << "-------------------------------------" << endl;
        cout << "Your current HP is "<< p1->getHP() << "/" << p1->getMaxHP() << endl;
        cout << "Your current MP is "<< p1->getMP() << "/" << p1->getMaxMP() << endl;
        cout << "You have defeated " << defeatcounter << " monsters" << endl;
        cout << "Your inventory: " << endl;

        for (int i = 0; i < 3; i++) {
            cout << Inventory[i].getPotType() << endl;
        }
        cout << "-------------------------------------" << endl;
    }

    // Player action: Block
    else if (pInput == "block" || pInput == "Block") {
        p1->block();
    }

    // Player action: Attack
    else if (pInput == "attack" || pInput == "Attack") { //attack only on player input
        p1->battleCry();
        p1->attack(m1);
    }

    // Player action: Special Attack
    else if (pInput == "special" || pInput == "Special") {
        p1->specialAttack(m1);
    }

    // Player action: Consume a potion
    else if (pInput == "potion" || pInput == "Potion") {
        cout << "What potion do you want to consume?" << endl;
        cin >> pInput;
        int empty = 0;

        // Reject invalid inputs
        while (pInput != "Health" && pInput != "health" && pInput != "Mana" && pInput != "mana"){
            std::cout << "Invalid input. Select either a health or mana potion." << std::endl;
            cin >> pInput;
        }

        // Player choice of what type they wish to consume
        if (pInput == "Health" || pInput == "health") {
            for (int i = 0; i < 3; i++){
                if (Inventory[i].getPotType() == "Health Potion") {
                    Inventory[i].consume(p1);
                    Inventory[i].clearPot();
                    break;
                }

                else {
                    empty++;
                }

                // If all inventory slots are empty, warn player
                if (empty == 3) {
                    cout << "You have no health potions!" << endl;
                }
            }
        }

        else if (pInput == "Mana" || pInput == "mana") {
            for (int i = 0; i < 3; i++){
                if (Inventory[i].getPotType() == "Mana Potion") {
                    Inventory[i].consume(p1);
                    Inventory[i].clearPot();
                    break;
                }

                else {
                    empty++;
                }

                // If all inventory slots are empty, warn player
                if (empty == 3) {
                    cout << "You have no mana potions!" << endl;
                }
            }
        }
    }
}


