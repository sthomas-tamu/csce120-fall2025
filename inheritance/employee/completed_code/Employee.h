#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include <iostream>

class Employee {
  private:
    std::string firstName, lastName;

  public:
    Employee(std::string f, std::string l) : firstName(f), lastName (l) {}

    void print(std::ostream& os) const {
        os << firstName << " " << lastName;
    }
};


class HourlyEmployee : public Employee {
  private:
    double hourlyWage;

  public:
    HourlyEmployee(std::string f, std::string l, double w) : Employee(f, l), hourlyWage(w) {}

    void print(std::ostream& os) const {
        Employee::print(os);
        os << ", " << hourlyWage;
    }
};


class SalariedEmployee : public Employee {
  private:
    double annualSalary;

  public:
    SalariedEmployee(std::string f, std::string l, double w) : Employee(f, l), annualSalary(w) {}

    void print(std::ostream& os) const {
        Employee::print(os);
        os << ", " << annualSalary;
    }
};

#endif
