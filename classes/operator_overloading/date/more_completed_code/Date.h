#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date {
    private:
        unsigned int month, day, year;

    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}
        ~Date() {}

        unsigned int getMonth() const { return month; }        
        unsigned int getDay() const { return day; }        
        unsigned int getYear() const { return year; }        

        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;

        bool operator<(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;

        Date& operator++(); 
        unsigned int daysInMonth() const; //helper function to compute number of days in the month
        bool isLeapYear() const; //helper function to determine if a leap year or not
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
