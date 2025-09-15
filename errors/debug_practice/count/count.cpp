#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    //fill vector with random numbers between 0 and 9
    for(int i=0; i<10; ++i) {
        numbers.push_back(rand() % 10);
    }

    //print out vector
    std::cout << "numbers =\t";
    for(int i=0; i<numbers.size(); ++i) {
        std::cout << " " << numbers.at(i);
    }
    std::cout << std::endl;

    //ask for a number to search for
    std::cout << "Which number would you like to count in the list?" << std::endl;
    int x = 0;
    std::cin >> x;
    if(std::cin.fail()) {
        std::cout << "Invalid input, exiting." << std::endl;
        return -1;
    }

    //count how many times x is in the vector
    int count = 0;
    for(int i=0; i<numbers.size(); ++i) {
        if((numbers.at(i) = x)) {
            count++;
        }
    }
    std::cout << "There are " << count << " instances of " << x << " in the list." << std::endl;

    return 0;
}
