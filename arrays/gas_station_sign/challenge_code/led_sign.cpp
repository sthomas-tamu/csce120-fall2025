#include <iostream>
#include "digits.h"

// led sign is 7 bulbs tall and 24 bulbs wide
// prices are displayed as follows (d = dollars, t = tenths, h = hundreds, x = fractional 9/10 cent, coords shown)
//  012345678901234567890123
// 0 dddd   tttt  hhhh  xxx 0
// 1 dddd   tttt  hhhh  x x 1
// 2 dddd   tttt  hhhh  xxx 2
// 3 dddd   tttt  hhhh    x 3
// 4 dddd   tttt  hhhh    x 4
// 5 dddd   tttt  hhhh      5
// 6 dddd . tttt  hhhh      6
//  012345678901234567890123

static const int SIGN_HEIGHT = 7;
static const int SIGN_WIDTH = 24;

void printChoices(std::ostream& os); //menu choices for controling led bulbs

void display_sign(std::ostream& os, char led[][SIGN_WIDTH], unsigned int height, unsigned int width);

void clear_sign(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width); //turn all bulbs off
void check_bulbs(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width); //turn all bulbs on and display

void set_price(double price, char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width); //clear display and set bulbs to show price
void place_digit(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width, unsigned int start_row, unsigned int start_col, unsigned int digit); //turns on bulbs for a single digit
void place_remainder(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width, unsigned int start_row, unsigned int start_col); //turns on bulbs for the fractional 9/10 cent


int main() {
    //create 2d array for led gas signs
    char led_regular[SIGN_HEIGHT][SIGN_WIDTH];
    char led_diesel[SIGN_HEIGHT][SIGN_WIDTH];

    //initialze each sign (turn off all bulbs)
    clear_sign(led_regular, SIGN_HEIGHT, SIGN_WIDTH);
    clear_sign(led_diesel, SIGN_HEIGHT, SIGN_WIDTH);

    char choice = ' ';
    double price = 0;

    while(toupper(choice) != 'Q') {
        printChoices(std::cout);
        std::cin >> choice;

        switch (toupper(choice) ) {
            case 'C':
                clear_sign(led_regular, SIGN_HEIGHT, SIGN_WIDTH);
                clear_sign(led_diesel, SIGN_HEIGHT, SIGN_WIDTH);
                std::cout << "sign cleared\n";
                break;

            case 'B':
                check_bulbs(led_regular, SIGN_HEIGHT, SIGN_WIDTH);
                check_bulbs(led_diesel, SIGN_HEIGHT, SIGN_WIDTH);
                std::cout << "all bulbs should be on:\n";
                // no break because want it to display the sign after turning all bulbs on

            case 'D':
                std::cout << "Regular:\n";
                display_sign(std::cout, led_regular, SIGN_HEIGHT, SIGN_WIDTH);
                std::cout << "\n";

                std::cout << "Disel:\n";
                display_sign(std::cout, led_diesel, SIGN_HEIGHT, SIGN_WIDTH);
                std::cout << "\n";
                break;
           
            case 'P':
                //read in and set regular price
                std::cout << "What is the price for regular?\n";
                
                std::cin >> price;
                if(std::cin.fail() || price < 0 || price > 10) {
                    std::cout << "Invalid price, must be less than 10.00. Price not updated.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                set_price(price, led_regular, SIGN_HEIGHT, SIGN_WIDTH);

                //read in and set diesel price
                std::cout << "What is the price for diesel?\n";
                std::cin >> price;
                if(std::cin.fail() || price < 0 || price > 10) {
                    std::cout << "Invalid price, must be less than 10.00. Price not updated.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                set_price(price, led_diesel, SIGN_HEIGHT, SIGN_WIDTH);
                
                break;
            
            case 'Q':
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }
    }

    return 0;
}


void printChoices(std::ostream& os) {
    os << "What would you like to do?\n";
    os << "\tD - display sign\n";
    os << "\tC - clear sign\n";
    os << "\tP - set prices\n";
    os << "\tB - bulb check\n";
    os << "\tQ - quit\n";
}

void clear_sign(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width) {
    //turn all bulbs OFF
    for(unsigned int row = 0; row < height; ++row) {
        for(unsigned int col = 0; col < width; ++col) {
            led_sign[row][col] = OFF;
        }
    }
}

void display_sign(std::ostream& os, char led[][SIGN_WIDTH], unsigned int height, unsigned int width) {
    //print top border
    os << " ";
    for(unsigned int col = 0; col < width; ++col) {
        os << "_";
    }
    os << "\n";

    //print each row with border
    for(unsigned int row = 0; row < height; ++row) {
        os << "|";
        for(unsigned int col = 0; col < width; ++col) { 
            os << led[row][col];
        }
        os << "|\n";
    }

    //print bottom border
    os << " ";
    for(unsigned int col = 0; col < width; ++col) {
        os << "-";
    }
    os << "\n";
}

void check_bulbs(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width) {
    //turn all bulbs ON
    for(unsigned int row = 0; row < height; ++row) {
        for(unsigned int col = 0; col < width; ++col) {
            led_sign[row][col] = ON;
        }
    }
}

void place_digit(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width, unsigned int start_row, unsigned int start_col, unsigned int digit) {
    //turn on bulbs to display digit, top left corner of digit is start_row, start_col
    for(unsigned int row=0; row < DIGIT_HEIGHT; row++) {
        for(unsigned int col=0; col < DIGIT_WIDTH; col++) {
            led_sign[start_row + row][start_col + col] = digits[digit][row][col];
        }
    }
}

void place_remainder(char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width, unsigned int start_row, unsigned int start_col) {
    //turn on bulbs to display fractional 9/10 cent, top left corner is start_row, start_col
    for(unsigned int row=0; row < DIGIT_HEIGHT; row++) {
        for(unsigned int col=0; col < 3; col++) {
            led_sign[start_row + row][start_col + col] = remainder_cents[row][col];
        }
    }
}

void set_price(double price, char led_sign[][SIGN_WIDTH], unsigned int height, unsigned int width) {
    //extract digits from price
    long long amount = std::round(price * 100.0);
    long long hundredths = amount % 10;
    amount /= 10;
    long long tenths = amount % 10;
    amount /= 10;
    long long dollars = amount % 10;

    //clear sign
    clear_sign(led_sign, height, width);

    //place price
    place_digit(led_sign, height, width, 0, 1, dollars); //print dollars
    led_sign[SIGN_HEIGHT - 1][6] = ON; // print decimal
    place_digit(led_sign, height, width, 0, 8, tenths); //print tenth place for cents
    place_digit(led_sign, height, width, 0, 14, hundredths); //print hundredths place for cents
    place_remainder(led_sign, height, width, 0, 20); //print fractional 9/10 cent
}

