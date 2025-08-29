#define DEBUG 0

#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
    double sum = 0;
    int counter = 0;

    cout << "Enter a series of integers. Last number is -1" << endl;
    int value = 0;
    cin >> value;
    if(cin.fail()) {
        cout << "ERROR, not a number, aborting." << endl;
        return -1;
    }
    if (DEBUG) {
        cout << "read in " << value << endl;
    }

    while (value != -1) {
        sum += value;
        counter++;
        if (DEBUG) {
            cout << "sum is now " << sum << ", counter is now " << counter << endl;
        }

        cin >> value;
        if(cin.fail()) {
            cout << "ERROR, not a number, aborting." << endl;
            return -1;
        }
        if (DEBUG) {
            cout << "read in " << value << endl;
        }
    }

    //check if no numbers were entered
    if(counter == 0) {
        cout << "No numbers were entered, there is no average." << endl;
    } else {
        cout << "The average is " << sum/counter << endl;
    }

    return 0;
}
