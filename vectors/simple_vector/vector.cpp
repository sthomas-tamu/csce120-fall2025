#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;


void PrintVector(std::string label, const vector<int> v) {
    cout << "The " << label << " vector elements:" << endl;
    for (unsigned int i=0; i<v.size(); ++i) {
        cout << label << "[" << i << "] = " << v[i] << endl;
    }
    cout << endl;
}


int SumVector(const vector<int> v) {
    int sum = 0;
    for (unsigned int i=0; i<v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}


int main() {
    // declare/define a vector
    vector<int> evens(5, 0); // a vector of int of size 5, initialize all elements to 0
    
    // initialize the array with iteration    
    for (unsigned int i=0; i<evens.size(); ++i) {
        evens[i] = i*2;
    }

    // access a single element from the vector
    cout << "The second element of the evens vector is " << evens[1] << endl; //vectors are indexed starting at 0, not 1!
    
    // print values from vector (includes traversal)
    PrintVector("evens", evens);

    // sum the values
    cout << "The sum of the evens vector is " << SumVector(evens) << endl;

    /*
    // initialize the array with braces
    vector<int> odds = {1, 3, 5, 7, 9};
    PrintVector("odds", odds);

    //initialize the array to default
    vector<int> defaultVector(5);
    PrintVector("defaultInit", defaultVector);
    */
}
