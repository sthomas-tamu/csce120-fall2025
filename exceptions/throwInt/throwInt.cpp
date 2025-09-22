#include <iostream>


void throwingFunctionA() {
    std::cout << "-- start of throwingFunctionA --" << std::endl;

    // throw an int (just for fun make it even)
    throw 4;

    std::cout << "-- end of throwingFunctionA --" << std::endl;
} 


void throwingFunctionB() {
    std::cout << "-- start of throwingFunctionB --" << std::endl;

    // throw an int (just for fun make it odd)
    throw 5;

    std::cout << "-- end of throwingFunctionB --" << std::endl;
}


int main() {
    std::cout << "-- start of main --" << std::endl;

    std::cout << "Select which throwing function you would like (1 or 2): ";
    int version = 0;
    std::cin >> version;

    if(version == 1) {
        throwingFunctionA();
    } else if (version == 2) {
        throwingFunctionB();
    } else {
        std::cout << "Error, invalid choice." << std::endl;
    }

    std::cout << "-- end of main --" << std::endl;
}
