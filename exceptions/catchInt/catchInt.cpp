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


void errorMessage(int errorCode) {
    std::cout << "-- start of errorMessage --" << std::endl;

    if(errorCode % 2 == 0) {
        std::cout << "caught even error" << std::endl;
    } else {
        std::cout << "caught odd error" << std::endl;
    }

    std::cout << "-- end of errorMessage --" << std::endl;
}


int main() {
    std::cout << "-- start of main --" << std::endl;

    std::cout << "Select which throwing function you would like (1, 2, or 3): ";
    int version = 0;
    std::cin >> version;

    if(version == 1) {
        try {
            throwingFunctionA();
        } catch (int e) {
            errorMessage(e);
        }
    } else if (version == 2) {
        try {
            throwingFunctionB();
        } catch (int e) {
            errorMessage(e);
        }
    } else if (version == 3) {
        try {
            throwingFunctionA();
            throwingFunctionB();
        } catch (int e) {
            errorMessage(e);
        }
    } else {
        std::cout << "Error, invalid choice." << std::endl;
    }

    std::cout << "-- end of main --" << std::endl;
}
