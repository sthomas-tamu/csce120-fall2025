#include "Dice.h"

int main() {
    Dice d1(6), d2(6);
    std::cout << "Created 2 dice:\n";
    std::cout << "\tDice 1: " << d1 << std::endl;
    std::cout << "\tDice 2: " << d2 << std::endl;
    std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
    std::cout << "d1 != d2: " << (d1 != d2) << std::endl;
   
    while(d1 == d2) { 
        d1.roll();
        d2.roll();
        std::cout << "\nRolled 2 dice:\n";
        std::cout << "\tDice 1: " << d1 << std::endl;
        std::cout << "\tDice 2: " << d2 << std::endl;
        std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
        std::cout << "d1 != d2: " << (d1 != d2) << std::endl;
    }
 
    return 0;
}
