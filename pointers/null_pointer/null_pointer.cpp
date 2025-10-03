#include <iostream>
#include <string>

void print(const int& x, std::string label) {
    std::cout << "  " << label << ":\t";
    std::cout << "address = " << &x << "\t" << std::flush;
    std::cout << "value = " << x << "\t" << std::flush;
    std::cout << std::endl;
}


void print(const int* x, std::string label) {
    std::cout << "  " << label << ":\t";
    std::cout << "address = " << &x << "\t" << std::flush;
    std::cout << "value = " << x << "\t" << std::flush;
    std::cout << "points to = " << *x << std::flush;
    std::cout << std::endl;
}


int main() {
    // declare an interger pointer but don't initialize
    std::cout << "using an int pointer without initializing it" << std::endl;
    int* k; 
    print(k, "k");

    // initialize it to a new int
    std::cout << std::endl << "creating a new int and setting the int pointer to point to it" << std::endl;
    int j = 10;
    k = &j;
    print(j, "j");
    print(k, "k");

    // set it to the nullptr
    std::cout << std::endl << "setting the int pointer to be the nullptr and attempting to use it" << std::endl;
    k = nullptr;
    print(k, "k");

    return 0;
}
