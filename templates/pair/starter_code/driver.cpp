#include "Pair.h"

int main() {
    // Pair with int
    Pair p1(1, 2);
    Pair p2(2, 1);
    Pair p3(1, 1);

    //Print pairs and compare:
    std::cout << "p1: ";
    p1.print(std::cout);
    std::cout << "\n";


    std::cout << "p2: ";
    p2.print(std::cout);
    std::cout << "\n";

    std::cout << "p3: ";
    p3.print(std::cout);
    std::cout << "\n";

    std::cout << "p1 < p2: " << (p1 < p2) << "\n";
    std::cout << "p1 < p3: " << (p1 < p3) << "\n";

    return 0;
}
