#include <string>

// Functions are used to reject invalid inputs from the user.
// Only allows specific inputs to the program.

bool PlayerInputChecker(std::string PlayerInput) {

    if (PlayerInput != "block" && PlayerInput != "attack" && PlayerInput != "special" && PlayerInput != "potion"
    && PlayerInput != "stats" && PlayerInput != "help" && PlayerInput != "Block" && PlayerInput != "Attack"
    && PlayerInput != "Special" && PlayerInput != "Potion" && PlayerInput != "Stats" && PlayerInput != "Help") {
        return false;
    }

    return true;
}

bool SpecialInputChecker(std::string PlayerInput) {

    if (PlayerInput == "help"  || PlayerInput == "stats" || PlayerInput == "Stats" || PlayerInput == "Help") {
        return false;
    }

    return true;
}