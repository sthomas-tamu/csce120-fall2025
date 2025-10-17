#include "Date.h"

bool Date::operator==(const Date& rhs) const {
    return ((year == rhs.year) && (month == rhs.month) && (day == rhs.day));
}


bool Date::operator!=(const Date& rhs) const {
    //implement using == operator already defined
    //using the this pointer to refer to myself (the lhs)
    return !(*this == rhs);

    //or can implement explicitly
    //return ((year != rhs.year) || (month != rhs.month) || (day != rhs.day));
}


bool Date::operator<(const Date& rhs) const {
    //first compare the years
    if (year < rhs.year) {
        return true;
    }
    if (year > rhs.year) {
        return false;
    }

    //years are the same, next compare the months
    if (month < rhs.month) {
        return true;
    }
    if(month > rhs.month) {
        return false;
    }

    //years and months are the same, now compare the days
    //can simply use the < operator on days since there is nothing else to compare after it
    return (day < rhs.day);
}


bool Date::operator<=(const Date& rhs) const {
    //implement using existing operators
    //using the this pointer to refer to myself (the lhs)
    return (*this < rhs) || (*this == rhs);
}


Date& Date::operator++() {
    day++;
    if (day > daysInMonth()) { //move to next month
        day = 1;
        month++;
     
        if(month > 12) { //move to next year
            month = 1;
            year++;
        }
    }

    return *this;
}


unsigned int Date::daysInMonth() const {
    //months have 31 days except for February which has 28 or 29 depending on the year and April/June/September/November which as 30
    switch (month) {
        case 2:
            if (isLeapYear()) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}


bool Date::isLeapYear() const {
    //leap years must be divisible by 4 and cannot be divisible by 100 unless also divisible by 400

    //checking divisible by 400 first since always a leap year
    if(year % 400 == 0) {
        return true;
    }

    //not divisible by 400, so checking 100
    if(year % 100 == 0) {
        return false;
    }

    //not divisible by 100, so only leap year if divisible by 4
    return year % 4 == 0;
}


std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
    return os;
}

