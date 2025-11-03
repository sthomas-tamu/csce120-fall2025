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

void push(int*& ary, unsigned int& capacity, unsigned int& size, int value) {
    if (size == capacity) {
        std::cout << "Array full! Resizing from " << capacity;
            
        // Double the capacity
        capacity *= 2;
        std::cout << " to " << capacity << std::endl;
            
        // Create new larger array
        int* newAry = new int[capacity];
            
        // Copy old elements
        for (unsigned int j = 0; j < size; j++) {
            newAry[j] = ary[j];
        }
            
        // Delete old array and update pointer
        delete[] ary;
        ary = newAry;
    }
        
    // Add the new element
    ary[size] = value;
    size++;        
    std::cout << "Added: " << ary[size-1] << std::endl;
}

void shrinkToFit(int*& ary, unsigned int& capacity, unsigned int& size) {
    if (size < capacity) {
        std::cout << "Shrinking array: " << capacity << " to " << size << std::endl;

        // Create new smaller array
        int* newAry = new int[size];

        // Copy old elements
        for (unsigned int i = 0; i < size; i++) {
            newAry[i] = ary[i];
        }

        // Delete old array and update pointer
        delete[] ary;
        ary = newAry;
        capacity = size;
    }
}


int main() {
    // Start with a small array
    unsigned int capacity = 3;
    unsigned int size = 0;
    int* ary = new int[capacity];
    std::cout << "Initial array (capacity = " << capacity << "): ";
    printAry(std::cout, ary, size);   
    std::cout << std::endl; 
 
    // Add elements, resizing when needed
    for (int i = 0; i < 10; i++) {
        push(ary, capacity, size, i*2);
    }
    
    // Display final array
    std::cout << "Final array (capacity = " << capacity << "): ";
    printAry(std::cout, ary, size);
    std::cout << std::endl;

    // Shrink array
    shrinkToFit(ary, capacity, size);

    // Display final array
    std::cout << "Final shrink to fit array (capacity = " << capacity << "): ";
    printAry(std::cout, ary, size);
    std::cout << std::endl;

    // Release the memory 
    delete[] ary;

    return 0;
}
