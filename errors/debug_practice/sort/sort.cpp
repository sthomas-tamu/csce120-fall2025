#include <iostream>
#include <vector>

void swap(std::vector<int> numbers, unsigned int i, unsigned int j) {
    int swap_value = numbers.at(j);
    numbers.at(j) = numbers.at(j+1);
    numbers.at(j+1) = swap_value;
}


int main() {
    std::vector<int> numbers;
    for(int i=0; i<10; ++i) {
        numbers.push_back(rand() % 20); //generate random numbers between 0 and 20
    }

    std::cout << "numbers =\t";
    for(int i=0; i<numbers.size(); ++i) {
        std::cout << " " << numbers.at(i);
    }
    std::cout << std::endl;

    //sort numbers using bubble sort
    for(unsigned int i=0; i<numbers.size()-1; ++i) {
        for(unsigned int j=0; j<numbers.size()-i-1; ++j) {
            if (numbers.at(j) > numbers.at(j+1)) {
                swap(numbers, i, j);
            }
        }
    }

    std::cout << "sorted =\t";
    for(int i=0; i<numbers.size(); ++i) {
        std::cout << " " << numbers.at(i);
    }
    std::cout << std::endl;

    return 0;
}
