#include <iostream>
#include <cmath> //provides common math functions like sqrt and abs
#include <vector>

// Function declarations
void outputEquation(double a, double b, double c);
bool checkRoot(double a, double b, double c, double root);

double solveLinear(double b, double c);
std::vector<double> solveQuadratic(double a, double b, double c);


// main
int main() {
    // Prompt user for coefficients a, b, c
    std::cout << "Input coefficients a, b, and c for your equation: ";
    double a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    //check that a, b, c are numbers (check that cin.good())

    // Output equation ax^2 + bx + c = 0
    outputEquation(a, b, c);

    // Solve for roots
    double root1 = 0;
    double root2 = 0;
    std::cout << "calculating roots TBD" << std::endl;

    //check value of a
    //if a is 0, then linear equation
    //otherwise, quadratic


    std::cout << "Root 1: " << root1 << std::endl;
    std::cout << "Root 2: " << root2 << std::endl;

    std::cout << "Checking root 1: " << std::boolalpha << checkRoot(a, b, c, root1) << std::endl;
    std::cout << "Checking root 2: " << std::boolalpha << checkRoot(a, b, c, root2) << std::endl;

    return 0;
}


void outputEquation(double a, double b, double c) {
    std::cout << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
}


bool checkRoot(double a, double b, double c, double root) {
    double EPSILON=0.000000001; //error threshold

    double value = a*root*root + b*root + c;
    return (abs(value) < EPSILON);
}

double solveLinear(double b, double c) {
    std::cout << "solveLinear TBD" << std::endl;
    return 0;
}

std::vector<double> solveQuadratic(double a, double b, double c) {
    std::cout << "solveQuadratic TBD" << std::endl;
    std::vector<double> roots;
    return roots;
}
