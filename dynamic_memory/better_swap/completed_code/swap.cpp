#include <iostream>

class List {
    unsigned int size;
    int* elements;

  public:
    List() : size{0}, elements{nullptr} {}

    List(unsigned int s, int* e) : size{s} {
        if(size > 0) {
            elements = new int[size];
            for(unsigned int i=0; i<size; ++i)
                elements[i] = e[i];
        }
    }

    List(const List& source) : size{source.size}, elements{nullptr} {
        if(size > 0) {
            elements = new int[size];
            for(unsigned int i=0; i<size; ++i)
                elements[i] = source.elements[i];
        }
    }

    ~List() { 
        if(elements != nullptr)
            delete[] elements;
    }

    bool empty() const { return size == 0; }
    unsigned int getSize() const { return size; }
    int getElement(int index) const { return elements[index]; }

    List& operator=(const List& other) {
        if(elements != nullptr) {
            delete[] elements;
            elements = nullptr;
        }

        size = other.size;

        if(size > 0) {
            elements = new int[size];
            for(unsigned int i=0; i<size; ++i)
                elements[i] = other.elements[i];
        }

        return *this;
    }


    void swap(List& other) {
        // instead of doing a deep copy of elements using the copy assignment operator,
        // manually handle each data member so only need to swap the element pointers

        unsigned int tmpSize = other.size;
        other.size = size;
        size = tmpSize;

        int* tmpElements = other.elements;
        other.elements = elements;
        elements = tmpElements;
    }
};

std::ostream& operator<<(std::ostream& os, const List& list) {
    if(list.empty()) {
        os << "empty";
    } else {
        for(unsigned int i=0; i<list.getSize(); ++i)
            os << list.getElement(i) << " ";
    }
    return os;
}

int main() {
    int* items = new int[3]{1, 2, 3};
    List list1(3, items);
    delete[] items;

    List list2;

    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";

    std::cout << "swapping lists\n";
    list1.swap(list2);
    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";

    return 0;
}
