#include <iostream>

void printAry(std::ostream& os, int* ary, unsigned int size) {
    if(size == 0) {
        os << "empty";
    } else {
        for(unsigned int i=0; i<size; ++i) {
            os << ary[i] << " ";
        }
    }
}


int main() {
    // Start with a small array
    unsigned int capacity = 3;
    unsigned int size = 0;
    int* ary = new int[capacity];
    std::cout << "Initial array (capacity = " << capacity << " ): ";
    printAry(std::cout, ary, size);   
    std::cout << std::endl; 
 
    // Add elements, resizing when needed
    for (int i = 0; i < 10; i++) {
        // TODO 3: Move the body of this loop into a push() function
        if (size == capacity) {
            // TODO 1: Implement array resizing by doubling capacity
            std::cout << "Array full! Implement resizing\n";
            break;
        } 
        // Add the new element
        ary[size] = i*2;
        size++;        
        std::cout << "Added: " << ary[size-1] << std::endl;
    }
    
    // Display final array
    std::cout << "Final array (capacity = " << capacity << "): ";
    printAry(std::cout, ary, size);
    std::cout << std::endl;

    // TODO 2: Shrink array to fit and display again
    // TODO 3: Move the shrink array into a shrinkToFit() function

    // Release the memory 
    delete[] ary;

    return 0;
}
