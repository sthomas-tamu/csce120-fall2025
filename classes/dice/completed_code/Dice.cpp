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
