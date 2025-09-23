#include <iostream>

void A(bool cause_exception, std::string padding); // passing along padding std::string so easier to see nested function calls
void B(bool cause_exception, std::string padding); // passing along padding std::string so easier to see nested function calls
void C(bool cause_exception, std::string padding); // passing along padding std::string so easier to see nested function calls
void D(bool cause_exception, std::string padding); // passing along padding std::string so easier to see nested function calls


int main() {
    std::cout << "-- start of main --" << std::endl;

    std::cout << "There are a series of nested function calls. A->B->C->D" << std::endl;
    std::cout << "Would you like the function D to throw an exception? y or n" << std::endl;
    char input;
    std::cin >> input;

    if(std::toupper(input) == 'Y') {
        A(true, "  ");
    } else if(std::toupper(input) == 'N') {
        A(false, "  ");
    } else {
        std::cout << "invalid option, exiting." << std::endl;
    }

    std::cout << "-- end of main --" << std::endl;
    return 0;
}


void A(bool cause_exception, std::string padding) {
    std::cout << padding << "-- start of A --" << std::endl;

    B(cause_exception, padding + "  ");

    std::cout << padding << "-- end of A --" << std::endl;
}


void B(bool cause_exception, std::string padding) {
    std::cout << padding << "-- start of B --" << std::endl;

    try {
        C(cause_exception, padding + "  ");
    } catch (...) {
        std::cout << padding << "B: caught an exception from C" << std::endl;
    }

    std::cout << padding << "-- end of B --" << std::endl;
}


void C(bool cause_exception, std::string padding) {
    std::cout << padding << "-- start of C --" << std::endl;

    D(cause_exception, padding + "  ");

    std::cout << padding << "-- end of C --" << std::endl;
}


void D(bool cause_exception, std::string padding) {
    std::cout << padding << "-- start of D --" << std::endl;

    if (cause_exception) {
        std::cout << padding << "D is calling a function that throws an exception" << std::endl;
        std::string s = "hi";
        s.at(3);
    } else {
        std::cout << padding << "D is doing nothing" << std::endl;
    }

    std::cout << padding << "-- end of D --" << std::endl;
}
