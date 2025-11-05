#include <iostream>

// a class with dynamic memory example
class MyClass {
    int* ptr = nullptr;

  public:

    // default constructor, creates a new int on the heap initialized to 0
    MyClass() : ptr{new int{0}} {
        std::cout << "\tin MyClass default constructor" << std::endl;
    }

    // TODO Rule of 3: need to implement the destructor, copy constructor, and copy assignment operator
    //   to make sure memory is not leaked and copies are deep instead of shallow

    // increment the int ptr is pointing to
    void increment() { 
        if(ptr != nullptr) { 
            *ptr = *ptr + 1; 
        }
    }

    // print the value of the int ptr is pointing to
    void print() const {
        if(ptr != nullptr) { 
            std::cout << *ptr << std::endl; 
        }
    }
};

int main() {
    std::cout << "MyClass a;" << std::endl;
    MyClass a; // this calls the default constructor

    std::cout << "increment a 5 times and print out" << std::endl;
    for(int i=0; i<5; ++i) {
        a.increment();
    }
    a.print();

    std::cout << "MyClass b(a);" << std::endl;
    MyClass b(a); // this calls the copy constructor

    std::cout << "MyClass c = a;" << std::endl;
    MyClass c = a; // this also calls the copy constructor

    std::cout << "a = b;" << std::endl;
    a = b; // this calls the assignment operator

    std::cout << "exiting main()" << std::endl;
    return 0;
}
