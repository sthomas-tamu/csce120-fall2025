#include "Employee.h"

#include <iostream>

int main () {
    HourlyEmployee emp1("James", "Williams", 18.50);
    std::cout << "HourlyEmployee: ";
    emp1.print(std::cout);
    std::cout << std::endl;

    SalariedEmployee emp2 {"Mary", "Smith", 134000};
    std::cout << "SalariedEmployee: ";
    emp2.print(std::cout);
    std::cout << std::endl;

    return 0;
}
