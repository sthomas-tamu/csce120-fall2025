#include <iostream>
#include <sstream>


int main() {
    // read in a line of input, place in a istringstream
    std::cout << "Enter something, followed by the return key." << std::endl 
              << "The code will attempt to extract an integer from it and store it in the variable x." << std::endl;
    std::string line;
    getline(std::cin, line);
    std::istringstream iss(line);

    int x = -99;
    iss >> x;
    std::cout << std::endl;
    std::cout << "x: " << x << std::endl;

    std::cout << "iss.eof(): " << std::boolalpha << iss.eof() << std::endl;
    std::cout << "iss.fail(): " << std::boolalpha << iss.fail() << std::endl;
    std::cout << "iss.bad(): " << std::boolalpha << iss.bad() << std::endl;
    std::cout << "iss.good(): " << std::boolalpha << iss.good() << std::endl;
    std::cout << std::endl; 

    return 0; 
}
