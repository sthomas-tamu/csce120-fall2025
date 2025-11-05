#include <iostream>

// a class with dynamic memory example
//   updated to store an array of integers
class MyClass {
    int* ary = nullptr;
    unsigned int size = 0;

  public:

    // default constructor, creates a new int array of size 5 on the heap initialized to 0
    MyClass(unsigned int s = 5) : ary{nullptr}, size{s} {
        std::cout << "\tin MyClass default constructor" << std::endl;
        if(size > 0) 
            ary = new int[size]{};
    }

    // copy constructor, required to make a deep copy of ary instead of a shallow copy,
    //   a new int on the heap is initialized to the same value as what source.ptr is pointing to
    MyClass(const MyClass& source) : size{source.size} {
        std::cout << "\tin MyClass copy constructor" << std::endl;
        if(source.ary != nullptr) {
            ary = new int[source.size];
            for(unsigned int i = 0; i<source.size; ++i)
                ary[i] = source.ary[i];
        }
    }
    
    // destructor, releases memory on the heap created by the object
    ~MyClass() {
        std::cout << "\tin MyClass destructor" << std::endl;
        if(ary != nullptr) {
            std::cout << "\t\tMyClass.ary not null, releasing it's memory" << std::endl;
            delete[] ary;
        }
    }

    // assignment operator, required to make a deep copy of ary instead of a shallow copy
    MyClass& operator=(const MyClass& source) {
        std:: cout << "\tin MyClass assignment operator" << std::endl;
      
        // if I'm already pointing to something, release my memory
        //   this check is not needed in the copy constructor since it I can't already be pointing to something 
        if(ary != nullptr) {
            delete[] ary;
            ary = nullptr; // set dangling pointer to nullptr
        } 

        // if source is pointing to something, allocate new memory and copy the values
        if(source.ary != nullptr) {
            ary = new int[source.size];
            for(unsigned int i=0; i<source.size; ++i)
                ary[i] = source.ary[i];
        }

        size = source.size;

        return *this; //return a reference to myself (this is a pointer to myself so need to dereference it before returning)
    }

    // increment the elements of the int array ary is pointing to
    void increment() { 
        if(ary != nullptr) { 
            for(unsigned int i = 0; i<size; ++i)
                ary[i] = ary[i] + 1; 
        }
    }

    // print the value of the int array ary is pointing to
    void print() const {
        if(ary != nullptr) { 
            for(unsigned int i = 0; i<size; ++i)
                std::cout << ary[i] << " ";
            std::cout << std::endl; 
        } else {
            std::cout << "empty" << std::endl;
        }
    }
};

int main() {
    std::cout << "MyClass a;" << std::endl;
    MyClass a; // this calls the default constructor
    std::cout << "a: ";
    a.print();

    std::cout << "increment a 5 times and print out" << std::endl;
    for(int i=0; i<5; ++i) {
        a.increment();
    }
    std::cout << "a: ";
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
