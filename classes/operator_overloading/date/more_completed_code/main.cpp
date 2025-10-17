#include "Date.h"

int main() {
    Date d1(12, 31, 2000);
    ++d1;
    Date d2(10, 15, 2015);
    Date d3(10, 15, 2015);

    std::cout << "Date 1: " << d1 << std::endl;
    std::cout << "Date 2: " << d2 << std::endl;
    std::cout << "Date 3: " << d3 << std::endl;

    std::cout << "Comparing Date 1 and Date 2:\n";
    std::cout << "\t==: " << (d1 == d2) << std::endl;
    std::cout << "\t!=: " << (d1 != d2) << std::endl;
    std::cout << "\t<:  " << (d1 < d2) << std::endl;
    std::cout << "\t<=: " << (d1 <= d2) << std::endl;

    std::cout << "Comparing Date 2 and Date 3:\n";
    std::cout << "\t==: " << (d2 == d3) << std::endl;
    std::cout << "\t!=: " << (d2 != d3) << std::endl;
    std::cout << "\t<:  " << (d2 < d3) << std::endl;
    std::cout << "\t<=: " << (d2 <= d3) << std::endl;
    
    return 0;
}
