#include <iostream>

#include "Range.h"

int main() {
    Range<int> rangeInt;
    std::cout << "adding 5, 2, -10, 4 to rangeInt\n";
    rangeInt.add(5);
    rangeInt.add(2);
    rangeInt.add(-10);
    rangeInt.add(4);
    std::cout << "rangeInt range is " << rangeInt.getRange() << "\n";
    std::cout << "\tmin is " << rangeInt.getMin() << "\n";
    std::cout << "\tmax is " << rangeInt.getMax() << "\n";

    Range<double> rangeDouble;
    std::cout << "adding 5.5, 2.2, -10.0, 4.4 to rangeDouble\n";
    rangeDouble.add(5.5);
    rangeDouble.add(2.2);
    rangeDouble.add(-10.0);
    rangeDouble.add(4.4);
    std::cout << "rangeDouble range is " << rangeDouble.getRange() << "\n";
    std::cout << "\tmin is " << rangeDouble.getMin() << "\n";
    std::cout << "\tmax is " << rangeDouble.getMax() << "\n";

    return 0;
}
