#include <iostream>

int factorial(int x) {
    if(x == 0) { // base case
        return 1;
    } else { // recursive step
        return x * factorial(x-1);
    }
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
