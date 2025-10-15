#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date {
    private:
        unsigned int month, day, year;

    Date() {}
    ~Date() {}

    void print() const {
        std::cout << month << "/" << day << "/" << year;
    }

    //add comparison
};

#endif
