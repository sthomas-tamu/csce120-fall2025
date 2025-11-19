#include "LinkedList.h"

int main() {
    std::cout << "== Testing count ==\n";

    LinkedList ll;
    ll.insertBack(8);
    ll.insertFront(3);
    ll.insertBack(7);
    ll.insertBack(8);
    std::cout << "ll:\n" << ll << std::endl;

    std::cout << "ll.count(8) = " << ll.count(8) << std::endl;
    std::cout << "ll.count(3) = " << ll.count(3) << std::endl;
    std::cout << "ll.count(0) = " << ll.count(0) << std::endl;

    LinkedList ll_empty;
    std::cout << "ll_empty:\n" << ll_empty << std::endl;
    std::cout << "ll_empty.count(1) = " << ll_empty.count(1) << std::endl;

    LinkedList ll_single;
    ll_single.insertBack(1);
    std::cout << "ll_single:\n" << ll_single << std::endl;
    std::cout << "ll_single.count(0) = " << ll_single.count(0) << std::endl;
    std::cout << "ll_single.count(1) = " << ll_single.count(1) << std::endl;


    std::cout << "== Testing multiply ==\n";

    ll.multiply(3);
    std::cout << "ll:\n" << ll << std::endl;

    ll_empty.multiply(3);
    std::cout << "ll_empty:\n" << ll_empty << std::endl;

    ll_single.multiply(3);
    std::cout << "ll_single:\n" << ll_single << std::endl;


    std::cout << "== Testing getEvens ==\n";

    LinkedList ll_evens, ll_evens_empty;
    ll.getEvens(ll_evens);
    ll_empty.getEvens(ll_evens_empty);
    std::cout << "ll_evens:\n" << ll_evens << std::endl;
    std::cout << "ll_evens_empty:\n" << ll_evens_empty << std::endl;


    std::cout << "== Testing popFront ==\n";

    std::cout << "ll:\n" << ll << std::endl;
    while(!ll.empty()) {
        std::cout << ll.popFront() << std::endl;
        std::cout << "ll:\n" << ll << std::endl;
    }
    std::cout << ll.popFront() << std::endl;
    std::cout << "ll:\n" << ll << std::endl;


    std::cout << "== Testing popBack ==\n";

    for(int i=1; i<4; ++i) {
        ll.insertBack(i);
    }
    std::cout << "ll:\n" << ll << std::endl;
    while(!ll.empty()) {
        std::cout << ll.popBack() << std::endl;
        std::cout << "ll:\n" << ll << std::endl;
    }
    std::cout << ll.popBack() << std::endl;
    std::cout << "ll:\n" << ll << std::endl;


    std::cout << "== Testing removeDuplicates ==\n";

    ll.insertBack(8);
    ll.insertFront(3);
    ll.insertBack(7);
    ll.insertBack(8);
    std::cout << "ll:\n" << ll << std::endl;
    ll.removeDuplicates();
    std::cout << "ll:\n" << ll << std::endl;
    ll.removeDuplicates();
    std::cout << "ll:\n" << ll << std::endl;

    return 0;
}
