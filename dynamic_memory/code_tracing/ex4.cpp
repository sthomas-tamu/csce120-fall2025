#include <iostream>

int createInteger() {
    int* z = new int(15);
    return *z;
}

int main() {
    int* k = new int(3);
    std::cout << *k << std::endl;
    k = new int(7);
    std::cout << *k << std::endl;

    int w = createInteger();
    std::cout << w << std::endl;
    return 0;
}
