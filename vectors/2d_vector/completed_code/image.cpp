#include <iostream>
#include "imageFunctions.h"

/*  Function printMenu
 *  Return value: none
 */
// You should not modify this function unless you add another processing option. //
void printMenu()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << " 'G': Make grayscale image" << std::endl;
    std::cout << " 'S': Make sepia image" << std::endl;
    std::cout << " 'N': Make invert image" << std::endl;
    std::cout << " 'I': Make grayscale- invert image" << std::endl;
    std::cout << " 'Q': Quit" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl << "Please enter your choice: ";
}


int main() {
    // declare/define image 2d vector of Pixels
    std::vector<std::vector<Pixel> > image;
    
    char menuChoice = ' '; // selected menu option
    do {
        printMenu();
        std::cin >> menuChoice;
        switch (toupper(menuChoice)) { // use toupper so user can input upper or lower case choices
            case 'G':
            case 'S':
            case 'N':
            case 'I':
                processImage(menuChoice, image);
                break;
            case 'Q': // does nothing but needed or default will execute
                break;
            default:
                std::cout << std::endl << "'" << menuChoice << "' is not a valid option'" << std::endl << std::endl;
        }
    } while (toupper(menuChoice) != 'Q'); // use toupper so user can input upper or lower case choices
}

