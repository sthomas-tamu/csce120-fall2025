#include <iostream>

int fibonacci(int x) {
    if(x == 0 || x == 1) { // base case
        return x;

    } else { // recursive step
        return fibonacci(x-2) + fibonacci(x-1);
    }
}

int main() {
    int y = 0;
    std::cout << "Enter an integer: ";
    if(std::cin >> y && y >= 0) {
        std::cout << "Computing fibonacci(" << y << "):\n";
        int result = fibonacci(y);
        std::cout << "Result = " << result;
    }

    return 0;
}
