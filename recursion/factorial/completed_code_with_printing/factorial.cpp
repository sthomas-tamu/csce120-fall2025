#include <iostream>

int factorial(int x, std::string padding = "") {
    std::cout << padding << "start factorial(" << x << ")\n";

    if(x == 0) { // base case
        std::cout << padding << "end factorial(" << x << "), returning " << 1 << "\n";
        return 1;

    } else { // recursive step
        std::cout << padding << "computing a = factorial(" << x-1 << ")\n";
        int a = x * factorial(x-1, padding + "  ");

        std::cout << padding << "end factorial(" << x << "), returning " << (a) << "\n";
        return a;
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
