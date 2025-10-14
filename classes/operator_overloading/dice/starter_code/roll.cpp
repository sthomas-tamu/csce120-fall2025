#include <iostream>

#include "Dice.h"

void printDice(const Dice d, const std::string& label) {
    std::cout << label << ": " << d.getSides() << " sides, value = " << d.getValue() << std::endl;
}

int main() {
    Dice d1(6), d2(6);
    std::cout << "Created 2 dice:\n";
    printDice(d1, "\tDice 1");
    printDice(d2, "\tDice 2");
    std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
   
    while(d1 == d2) { 
        d1.roll();
        d2.roll();
        std::cout << "\nRolled 2 dice:\n";
        printDice(d1, "\tDice 1");
        printDice(d2, "\tDice 2");
        std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
    }
 
    return 0;
}
