#include <iostream>

int factorial(int x) {
    //TODO: compute, return 0 for now
    return 0;
}

int main() {
    int y = 0;
    std::cout << "Enter an integer: ";
    if(std::cin >> y && y >= 0) {
        std::cout << "Computing factorial(" << y << "):\n";
        int result = factorial(y);
        std::cout << "Result = " << result << "\n";
    }

    return 0;
}
