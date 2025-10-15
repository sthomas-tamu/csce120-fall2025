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
