#include <iostream>
#include <sstream>

int main() {
    // read in expression
    std::cout << "Enter the expression to calculate in one line: " << std::endl;
    std::string line;
    std::getline(std::cin, line);

    // extract operands and operator using an istd::stringstream
    double firstNum = 0, secondNum = 0;
    char op = ' ';

    std::istringstream iss(line);
    std::cout << "TODO: extract firstNum op secondNum from iss" << std::endl;

    // compute the result of the question based on op
    double result = 0;
    std::cout << "TODO: compute result based on op symbol, allowed symbols are +, -, *, %" << std::endl;

    // output result 
    std::cout << "result: " << result << std::endl;

    return 0;
}
