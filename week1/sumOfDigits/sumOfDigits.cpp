//this next line prints out debugging statements, can turn them off by commenting it out and uncommenting the next line
#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;
//#define DEBUG(X) 0

#include <iostream>
#include "function.h"

using std::cout, std::cin, std::endl;

int main() {
    cout << "Enter an integer" << endl;
    int x = 0;
    cin >> x;
    if(cin.fail()) {
        cout << "Error, failed to read in an integer, aborting." << endl;
        return -1;
    }
    DEBUG("read in " << x);

    cout << "the sum of digits is " << sumOfDigits(x) << endl;

    return 0;
}