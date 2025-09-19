#include <iostream>
#include <cmath> //provides common math functions like sqrt and fabs
#include <vector>

// Struct for returning error codes
struct Root {
    double value = 0;
    bool valid = false;
};


// Function declarations
void outputEquation(double a, double b, double c);
bool checkRoot(double a, double b, double c, double root);

Root solveLinear(double b, double c);
std::vector<Root> solveQuadratic(double a, double b, double c);


// main
int main() {
    // Prompt user for coefficients a, b, c
    std::cout << "Input coefficients a, b, and c for your equation: ";
    double a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    // Output equation ax^2 + bx + c = 0
    outputEquation(a, b, c);

    //Solve for roots
    if (a == 0) {
        //solve linear version
        Root root = solveLinear(b, c);
        if(root.valid) {
            std::cout << "Root 1: " << root.value << std::endl;
            std::cout << "Checking root 1: " << std::boolalpha << checkRoot(a, b, c, root.value) << std::endl;
        } else {
            std::cout << "Error! Not a valid equation" << std::endl;
        }
    } else {
        //solve quadratic version
        std::vector<Root> roots = solveQuadratic(a, b, c);

        for(unsigned int i=0; i<roots.size(); ++i) {
            if(roots.at(i).valid) {
                std::cout << "Root " << i << ": " << roots.at(i).value << std::endl;
                std::cout << "Checking root " << i << ": " << std::boolalpha << checkRoot(a, b, c, roots.at(i).value) << std::endl;
            } else {
                std::cout << "Error, roots complex " << std::endl;
                break;
                //instead of reporting an error, could create a solveComplex function
            }
        }
    }

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


Root solveLinear(double b, double c) {
    Root root;
    if (b == 0) {
        root.valid = false;
    } else {
        root.value = -c / b;
        root.valid = true;
    }

    return root;
}


std::vector<Root> solveQuadratic(double a, double b, double c) {
    /*
    compute descriminant
    if (discriminant is >= 0)
      compute roots using formula
    else
      report complex root
    */

   std::vector<Root> roots;
   
   double descriminant = b*b - 4*a*c;
   std::cout << "Descriminant is " << descriminant << std::endl;

   if(descriminant < 0) { // complex root
        return roots;
   } else { // real root
        Root root1;
        root1.value = (-b + sqrt(descriminant))/(2*a);
        root1.valid = true;
        roots.push_back(root1);

        //only have root2 if descriminant is not 0
        if(descriminant != 0) {
            Root root2;
            root2.value = (-b - sqrt(descriminant))/(2*a);
            root2.valid = true;
            roots.push_back(root2);
        }
   }

   return roots;
}

