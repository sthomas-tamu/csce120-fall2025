#include <iostream>

int main() {
    int val = 0;
    std::cout << "Enter a single integer: ";
    std::cin >> val;

    while(!std::cin.fail()) { // data was successfully read 
        std::cout << "You entered: " << val << std::endl;

        // prepare to read again
	if(!std::cin.eof()) { // haven't reached the end (this doesn't happen with keyboard input, but could happen with a file)
            std::cout << "\tIgnoring anything else you may have entered, starting over." << std::endl;
            std::cin.clear(); // set all stream state bits to zero, buffer NOT cleared
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer of everything/make clean slate to read again

            std::cout << "Enter a single integer: ";
            std::cin >> val;
        }
    }
    std::cout << "Invalid input, exiting." << std::endl;

    return 0;
}
