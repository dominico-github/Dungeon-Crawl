#include <iostream>
#include <string>

#include "Player.h"
#include "Mage.h"
#include "Warrior.h"

using namespace std;

// Function is used to allow the player to select their class

Player* classSelect(Player* p1) {

        string classInput = "";
        cout << "Do you wish to be a Warrior or a Mage?" << endl;
        cin >> classInput;

        // Rejecting invalid inputs
        while (classInput != "warrior" && classInput != "Warrior" && classInput != "mage" && classInput != "Mage"){
            cout << "Choose properly!" << endl;
            cin >> classInput;
        }

        // If player selects Warrior
        if (classInput == "Warrior" || classInput == "warrior") {
            p1 = new Warrior();
            cout << "You have selected to be a Warrior!" << endl;
        }

        // If player selects Mage
        else if (classInput == "Mage" || classInput == "mage") {
            p1 = new Mage();
            cout << "You have selected to be a Mage!" << endl;
        }

        // Error checking to ensure the player class is properly selected
        if (p1->getType() != "Warrior" && p1->getType() != "Mage") {
        cout << "!!! Unexpected player class in classSelect.cpp !!!" << endl;
        }

    return p1;
}

