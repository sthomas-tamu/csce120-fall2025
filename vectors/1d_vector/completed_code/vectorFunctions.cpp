#include <iostream>
#include "vectorFunctions.h"

//can now have using statements as these are contained to only this implementation file
using std::cin, std::cout, std::endl;
using std::vector;


void print(const vector<int>& v) {
    if (v.empty()) { //or could check if size is 0
        cout << "Empty Vector" << endl;

    } else {
        for (unsigned int i=0; i<v.size(); ++i) {
            cout << v.at(i) << " ";

            // start a new line every 10 elements
            if ((i+1) % 10 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
}


void loadRandom(vector<int>& v, unsigned int size) {
    v.clear(); //erase all existing elements

    for (unsigned int i=0; i<size; ++i) {
        v.push_back(rand() % 100);
    }
}


int getMax(const vector<int>& v) {
    if(v.empty()) {
        cout << "Error, vector is empty. Returning 0.";
        return 0;
    }

    // will look for the max using the champion approach (keep the current winner)
    int maxVal = v.at(0);

    for (unsigned int i=1; i<v.size(); ++i) {
        if (v.at(i) > maxVal) { // checking for new winner, could simply use maxVal = std::max(maxVal, array[i]) instead
            maxVal = v.at(i);
        }
    }

    return maxVal;
}


int getMin(const vector<int>& v) {
    cout << "Not implemented yet." << endl;
    return 0;
}


unsigned int countVal(int val, const vector<int>& v) {
    unsigned int cnt = 0;
    for (unsigned int i=0; i<v.size(); i++) {
        if (v.at(i) == val) {
            cnt++;
        }
    }

    return cnt;
}

