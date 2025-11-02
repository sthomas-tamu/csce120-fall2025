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
    std::cout << "Initial array: ";
    printAry(std::cout, ary, size);   
    std::cout << std::endl; 
 
    // Add elements, resizing when needed
    for (int i = 0; i < 10; i++) {
        if (size == capacity) {
            std::cout << "Array full! Implement resizing\n";
        } else {
            // Add the new element
            ary[size] = i*2;
            size++;        
            std::cout << "Added: " << ary[size-1] << std::endl;
        }
    }
    
    // Display final array
    std::cout << "Final array: ";
    printAry(std::cout, ary, size);
    std::cout << std::endl;

    // Release the memory 
    delete[] ary;

    return 0;
}
