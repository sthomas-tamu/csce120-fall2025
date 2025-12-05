#include <iostream>

int fibonacci(int x, std::string padding = "") {
    std::cout << padding << "start fibonacci(" << x << ")\n";

    if(x == 0 || x == 1) { // base case
        std::cout << padding << "end fibonacci(" << x << "), returning " << x << "\n";
        return x;

    } else { // recursive step
        std::cout << padding << "computing a = fibonacci(" << x-2 << ")\n";
        int a = fibonacci(x-2, padding + "  ");

        std::cout << padding << "computing b = fibonacci(" << x-1 << ")\n";
        int b = fibonacci(x-1, padding + "  ");

        std::cout << padding << "end fibonacci(" << x << "), returning " << (a + b) << "\n";
        return a + b;
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
