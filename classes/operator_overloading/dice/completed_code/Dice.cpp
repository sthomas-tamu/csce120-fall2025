#include <cstdlib>
#include "Dice.h"

unsigned int Dice::getSides() const {
    return num_sides;
}

unsigned int Dice::getValue() const {
    return current_value;
}

void Dice::roll() {
    current_value = 1 +  (rand() % num_sides);
}

// myself == rhs
bool Dice::operator==(const Dice& rhs) const {
    //note that class member functions have access to data of rhs, even though private
    return current_value == rhs.current_value;

    //if want to be more explicit, can use the this pointer to refer to myself (the lhs)
    //return this->current_value == rhs.current_value;
}

// myself != rhs
bool Dice::operator!=(const Dice& rhs) const {
    //note that class member functions have access to data of rhs, even though private
    return current_value !== rhs.current_value;

    //could also implement using existing == operator and "this" (pointer to myself)
    //return !(*this == rhs);
}
