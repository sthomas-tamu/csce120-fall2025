#include <iostream>
#include <sstream>

std::string formatResult(double a, double b, char op, double result) {
    std::ostringstream oss;
    oss << a << " " << op << " " << b << " = " << result;
    return oss.str();
}

int main() {
    // read in expression
    std::cout << "Enter the expression to calculate in one line: " << std::endl;
    std::string line;
    std::getline(std::cin, line);

    // extract operands and operator using an istd::stringstream
    double firstNum = 0, secondNum = 0;
    char op = ' ';

    std::istringstream iss(line);
    if(!(iss >> firstNum)) { // a way to check if the read was successful, will learn next time a clearer way
        std::cout << "Error, first operand must be a number, exiting" << std::endl;
        return 0;
    }
    iss >> op; // since any char will be a valid read, will check below if it is a valid operator symbol
    if(!(iss >> secondNum)) { // a way to check if the read was successful, will learn next time a clearer way
        std::cout << "Error, second operand must be a number, exiting" << std::endl;
        return 0;
    }
    // iss >> firstnum >> op >> secondnum; // could instead put it all on 1 line, just like we do with std::cin/std::cout

    // compute the result of the question based on op
    double result = 0;
    switch (op) {
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
            std::cout << "Error, invalid operator '" << op << "', must be either +, -, *, or /" << std::endl;
            return -1;
    }

    // output result 
    std::cout << "result: " << result << std::endl;
    std::cout << formatResult(firstNum, secondNum, op, result) << std::endl;

    return 0;
}
