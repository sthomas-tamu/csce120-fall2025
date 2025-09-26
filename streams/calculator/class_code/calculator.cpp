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
    if(!(iss >> firstNum)) {
        std::cout << "Error, bad input for the first number, exiting." << std::endl;
        return -1;
    }

    if(!(iss >> op)) {
        std::cout << "Error, bad input for the operator, exiting." << std::endl;
        return -1;
    }

    if(!(iss >> secondNum)) {
        std::cout << "Error, bad input for the second number, exiting." << std::endl;
        return -1;
    }

    std::cout << "Computing " << firstNum << " " << op << " "<< secondNum << std::endl;



    // compute the result of the question based on op
    double result = 0;
    switch(op) {
        case '+': 
            result = firstNum + secondNum;
            break;
        case '-': 
            result = firstNum - secondNum;
            break;
        case '*': 
            result = firstNum * secondNum;
            break;
        case '/': 
            result = firstNum / secondNum;
            break;
        default:
            std::cout << "Error, invalid math symbol, exiting" << std::endl;
            return -1;
    }

    // output result 
    std::cout << "result: " << result << std::endl;

    return 0;
}
