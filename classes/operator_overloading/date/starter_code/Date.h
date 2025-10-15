#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date {
    private:
        unsigned int month, day, year;

    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}
        ~Date() {}

        void print() const {
            std::cout << month << "/" << day << "/" << year;
        }

        //add comparison: myself == rhs and myself != rhs

        //add ranking: myself < rhs and myself<= rhs
};

#endif
