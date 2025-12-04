#include <iostream>

int fibonacci(int x, std::string padding = "") {
    std::cout << padding << "start fibonacci(" << x << ")\n";

    //TODO: compute result, for now just return 0
    std::cout << padding << "end fibonacci(" << x << "), returning " << 0 << "\n";
    return 0;
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
