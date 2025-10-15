#include "Date.h"

int main() {
    Date d1(1, 1, 2001);
    Date d2(10, 15, 2015);

    std::cout << "Date 1: ";
    d1.print();
    std::cout << std::endl;
    std::cout << "Date 2: ";
    d2.print();
    std::cout << std::endl;

    return 0;
}
