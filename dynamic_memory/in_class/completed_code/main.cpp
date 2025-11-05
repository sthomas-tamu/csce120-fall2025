#include <iostream>

class MyClass {
    int* ptr = nullptr;
  public:

    //default constructor
    MyClass() : ptr{new int{0}} {}

    //copy constructor
    MyClass(const MyClass& copy) : ptr {new int{*(copy.ptr)}} {}

    // destructor
    ~MyClass() {
        std::cout << "in MyClass destructor" << std::endl;
        if(ptr != nullptr) {
            delete ptr;
        }
        std::cout << "memory cleaned up!" << std::endl;
    }

    // assignment operator
    MyClass& operator=(const MyClass& source) {
        if(source.ptr != nullptr) {
            ptr = new int{*(source.ptr)};
        }
        return *this;
    }


    void increment() { 
        if(ptr != nullptr) { 
            *ptr = *ptr + 1; 
        }
    }

    void print() const {
        if(ptr != nullptr) { 
            std::cout << *ptr << std::endl; 
        }
    }
};

int main() {
    MyClass c; //this calls the default constructor

    for(int i=0; i<5; ++i) {
        c.increment();
    }
    c.print();

    MyClass copyC(c); //this calls the copy constructor

    MyClass b; //call the default constructor
    b = c; //calls the assignment operator

    std::cout << "Exiting" << std::endl;
}
