#include "Employee.h"

#include <iostream>
#include <vector>

int main () {
    HourlyEmployee emp1("James", "Williams", 18.50);
    std::cout << "HourlyEmployee: ";
    emp1.print(std::cout);
    std::cout << std::endl;

    SalariedEmployee emp2 {"Mary", "Smith", 134000};
    std::cout << "SalariedEmployee: ";
    emp2.print(std::cout);
    std::cout << std::endl;

    std::vector<Employee*> staff;
    staff.push_back(&emp1);
    staff.push_back(&emp2);

    std::cout << "Staff:\n";
    for(unsigned int i=0; i<staff.size(); ++i) {
        staff.at(i)->print(std::cout);
        std::cout << "\n";
    }

    return 0;
}
