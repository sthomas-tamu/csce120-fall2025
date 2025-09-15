#include <iostream>

int main() {

    std::cout << "How many numbers do you want to average?" << std::endl;
    unsigned int x = 0;
    std::cin >> x;
    if(std::cin.fail()) {
        std::cout << "Invalid input, exiting." << std::endl;
        return -1;
    }

    std::vector<int> numbers;
    //fill vector with random numbers between 0 and 10
    for(unsigned int i=0; i<x; ++i) {
        numbers.push_back(rand() % 10);
    }

    //print out vector
    std::cout << "numbers =\t";
    for(unsigned int i=0; i<numbers.size(); ++i) {
        std::cout << " " << numbers.at(i);
    }
    std::cout << std::endl;

    //compute average
    int sum = 0;
    for(unsigned int i=0; i<numbers.size(); ++i) {
        sum += numbers.at(i);
    }
    std::cout << "average is " << sum / numbers.size() << std::endl;

    return 0;
}
