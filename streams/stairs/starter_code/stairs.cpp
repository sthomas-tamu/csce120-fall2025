#include <iostream>
#include <limits>

int main()
{
    unsigned int no_lines = 0;

    // read in number of "stairs"
    std::cout << "Please provide a number of lines to print the stair-case pattern: ";
    std::cin >> no_lines;
    
    // print "stairs"
    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    return 0;
}
