#include <iostream>

// a class with dynamic memory example
class MyClass {
    int* ptr = nullptr;

  public:

    // default constructor, creates a new int on the heap initialized to 0
    MyClass() : ptr{new int{0}} {
        std::cout << "\tin MyClass default constructor" << std::endl;
    }

    // copy constructor, required to make a deep copy of ptr instead of a shallow copy,
    //   a new int on the heap is initialized to the same value as what source.ptr is pointing to
    MyClass(const MyClass& source) {
        std::cout << "\tin MyClass copy constructor" << std::endl;

        // if source is pointing to something, allocate new memory and copy the value
        if(source.ptr != nullptr) {
            ptr = new int{*(source.ptr)};
        }
    }
    
    // destructor, releases memory on the heap created by the object
    ~MyClass() {
        std::cout << "\tin MyClass destructor" << std::endl;

        // if source is pointing to something, release the memory
        if(ptr != nullptr) {
            std::cout << "\t\tMyClass.ptr not null, releasing it's memory" << std::endl;
            delete ptr;
        }
    }

    // assignment operator, required to make a deep copy of ptr instead of a shallow copy
    MyClass& operator=(const MyClass& source) {
        std:: cout << "\tin MyClass assignment operator" << std::endl;

        // if I'm already pointing to something, release my memory
        //   this check is not needed in the copy constructor since it I can't already be pointing to something 
        if(ptr != nullptr) {
            delete ptr;
            ptr = nullptr; // set dangling pointer to nullptr
        } 

        // if source is pointing to something, allocate new memory and copy the value
        if(source.ptr != nullptr) {
            ptr = new int{*(source.ptr)};
        }

        return *this; //return a reference to myself (this is a pointer to myself so need to dereference it before returning)
    }

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
