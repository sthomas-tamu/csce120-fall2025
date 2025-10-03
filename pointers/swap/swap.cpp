#include <iostream>

void print(const int& x, const int& y, const int* p_x, const int* p_y) {
    std::cout << "x: " << x << " with address " << &x << std::endl;
    std::cout << "y: " << y << " with address " << &y << std::endl;

    std::cout << "p_x: " << p_x << " points to " << *p_x << std::endl;
    std::cout << "p_y: " << p_y << " points to " << *p_y << std::endl;

    std::cout << std::endl;
}


int main() {
    // create 2 integers
    int x = 9;
    int y = 5;

    // create 2 pointers to them
    int* p_x = &x;
    int* p_y = &y;
    
    std::cout << "before swap:" << std::endl;
    print(x, y, p_x, p_y);

    std::cout << "swapping pointers:" << std::endl;
    int* temp = p_x;
    p_x = p_y;
    p_y = temp;
    print(x, y, p_x, p_y);

    return 0;
}
