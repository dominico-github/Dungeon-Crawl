#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "Mage.h"
#include "Warrior.h"
#include "Slime.h"
#include "Skeleton.h"

using namespace std;

    // External functions
    extern Player* classSelect(Player*);
    extern Monster* monsterGen(Monster*);
    extern void moveGen(Monster*, Player*);
    extern void playerActions(string, Monster*, Player*, Potion*, int);
    extern int PotionGen(Potion*);
    extern bool PlayerInputChecker(string);
    extern bool SpecialInputChecker(string);

int main() {
    
    cout << "Welcome to the dungeon! Here you will venture deep inside the dungeon and face dangerous foes." << endl;

    Player* p1;
    Monster* m1;
    srand(time(NULL)); // Seeding the rand() function used in various functions in the program

    p1 = classSelect(p1); // Calls class select function
    m1 = monsterGen(m1); // Generates monster
    cout << "If you are unsure what to enter, enter help." << endl;

    Potion* Inventory = new Potion[3];
    string pInput = "";
    int battlecounter = 0;
    int defeatcounter = 0;

    // Game loop
    while (p1->getHP() > 0) {
        battlecounter++;

        // Takes in user input for their next action
        cout << "What will you do?" << endl;
        cin >> pInput;

        // Reject invalid inputs.
        while (PlayerInputChecker(pInput) == 0) {
            cout << "Unexpected input! Please enter a valid command! Type help for more" << endl;
            cin >> pInput;
        }

        // Special handling for help and stats commands, so that they don't consume a player's turn.
        while (SpecialInputChecker(pInput) == 0) {
            playerActions(pInput, m1, p1, Inventory, defeatcounter);
            cout << "What will you do?" << endl;
            cin >> pInput;

            // Recheck for invalid inputs
            while (PlayerInputChecker(pInput) == 0) {
                cout << "Unexpected input! Please enter a valid command! Type help for more" << endl;
                cin >> pInput;
            }
        }

        // Compute player action choice
        playerActions(pInput, m1, p1, Inventory, defeatcounter);

        // Check to see if enemy has died
        if (m1->getHP() <= 0){
            cout << "Enemy defeated!" << endl;
            defeatcounter++;

            // Generate loot (potion) upon monster death
            PotionGen(Inventory);

            // Check to see if player wishes to continue
            cout << "Do you wish to continue? Yes or no?" << endl;
            cin >> pInput;

            // Reject invalid inputs
            while (pInput != "Yes" && pInput != "Y" && pInput != "yes" && pInput != "y"){

                if (pInput == "No" || pInput == "N" || pInput == "no" || pInput == "n"){
                    cout << "You trace your path back to the entrance and leave." << endl;
                    return 0;
                }
                cout << "You're not making much sense..." << endl;
                cout << "Do you wish to continue? Yes or no?" << endl;
                cin >> pInput;
            }

            cout << endl;
            cout << "You venture deeper into the dungeon..." << endl;

            // Generates another monster
            m1 = monsterGen(m1);
        }


        cout << "Monster HP: " << m1->getHP() << "/" << m1->getMaxHP() << endl;

        // Randomly generates monster attack move
        moveGen(m1, p1);

        // If the player dies
        if (p1->getHP() <= 0) {
            cout << "You Died. You survived for " << battlecounter << " rounds." << endl;
            cout << "You defeated " << defeatcounter << " monsters in the dungeon." << endl;
            return 0;
        }
        cout << "Player HP: " << p1->getHP() << "/" << p1->getMaxHP() << endl;

    }

    free(m1);
    free(p1);
    free(Inventory);

    return 0;
}