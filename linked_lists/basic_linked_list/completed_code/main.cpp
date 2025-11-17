#include "LinkedList.h"

int main() {
    LinkedList ll;
    std::cout << "ll: constructor\n" << ll << std::endl;

    ll.insertBack(8);
    std::cout << "ll: insertBack(8)\n" << ll << std::endl;

    ll.insertFront(3);
    std::cout << "ll: insertFront(3)\n" << ll << std::endl;

    LinkedList ll2(ll);
    std::cout << "ll2: copy ll\n" << ll2 << std::endl;

    ll.insertBack(7);
    std::cout << "ll: insertBack(7)\n" << ll << std::endl;
    std::cout << "ll2:\n" << ll2 << std::endl;

    ll2 = ll;
    std::cout << "ll2 = ll1\n" << ll2 << std::endl;

    ll.clear();
    std::cout << "ll: clear\n" << ll << std::endl;
    std::cout << "ll2\n" << ll2 << std::endl;    
    
    std::cout << "ll2 contains 8: " << std::boolalpha << ll2.contains(8) << std::endl;
    std::cout << "ll2 contains 0: " << std::boolalpha << ll2.contains(0) << std::endl;

    std::cout << "ll2:\n" << ll2 << std::endl;

    ll2.insertAfter(-1, 0);
    std::cout << "ll2 attempt insert -1 after 0:\n" << ll2 << std::endl;

    ll2.insertAfter(-1, 8);
    std::cout << "ll2 attempt insert -1 after 8:\n" << ll2 << std::endl;

    ll2.remove(0);
    std::cout << "remove 0 from ll2:\n" << ll2 << std::endl;

    ll2.remove(8);
    std::cout << "remove 8 from ll2:\n" << ll2 << std::endl;

    ll2.remove(3);
    std::cout << "remove 3 from ll2:\n" << ll2 << std::endl;

    ll2.remove(7);
    std::cout << "remove 7 from ll2:\n" << ll2 << std::endl;
 
    return 0;
}
