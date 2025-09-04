#include <iostream>
#include "vectorFunctions.h" // don't include the cpp file! 

using std::cin, std::cout, std::endl;
using std::vector;

void printMenu(); // function implementation will be given later in the file


int main() {
    // seed the random number generator with the current time to get different numbers every time
    // when debugging, can be helpful to comment this out so you have the same numbers every time
    srand(time(NULL));
    
    // initialize the vec to all 0's and set size to 0
    vector<int> vec(0, 0);    
    
    char menuChoice = ' ';
  
    // print the choices until the user wants to quit
    while ('Q' != toupper(menuChoice)) { // clean up input data by convering character to upper case 
    
        printMenu();
        
        cout << endl << "What would you like to do? ";
        cin >> menuChoice;
        cout << endl;
    
        // declaring variables that will be used inside the switch statement
        // c++ does not allow declaring them inside the switch because case statements are only labels
        int num = 0;
        unsigned int index = 0;
        unsigned int size = 0;
          
        switch (toupper(menuChoice)) { // clean up input data by converting character to upper case
            case 'L':
                cout << "Input number of random values to load: ";
                cin >> size;

                loadRandom(vec, size);
                break;
      
            case 'I':
                cout << "Input value to insert: ";
                cin >> num;
                
                cout << "Input index to insert: ";
                cin >> index;

		if (index > vec.size()) { //if index out of range, set to insert at the end of the vector
                    index = vec.size();
                }
      
                vec.insert(vec.begin()+index, num); 
                break;
        
            case 'X':
                cout << "Max: " << getMax(vec) << endl;
                break;
      
            case 'N':
                cout << "Min: " << getMin(vec) << endl;
                break;
      
            case 'C':
                cout << "Input value to count: ";
                cin >> num;
        
                cout << num << " appears " << countVal(num, vec) << " times" << endl;
                break;
      
            case 'P':
                print(vec);
                break;
      
            case 'S':
                cout << "Size: " << vec.size() << endl;
                break;
      
            case 'Q':
                cout << "Goodbye!" << endl;
                break;
      
            default:
                cout << "Invalid input, try again." << endl;
                break;
        }
    }
}

void printMenu() {
    cout << endl;
    cout << "'L' - Load random values" << endl;
    cout << "'I' - Insert number at index" << endl;
    cout << "'R' - Remove number at index" << endl;
    cout << "'F' - Remove first instance of value" << endl;
    cout << "'X' - Get maximum value" << endl;
    cout << "'N' - Get miniumum value" << endl;
    cout << "'C' - Count instances of number" << endl;
    cout << "'P' - Print values" << endl;
    cout << "'S' - Size" << endl;
    cout << "'Q' - Quit" << endl;
}
