#include <iostream>
#include "LinkedList.h"


void printTest(const std::string& label, const LinkedList& l) {
    std::cout << label << ":\t\"" << l << "\"\n";
}

int main() {
    std::cout << "== Testing Constructors ==\n";

    LinkedList s1;
    printTest("s1: default constructor", s1);
    
    LinkedList s2("hello");
    printTest("s2: construct from a c-string", s2);
    
    std::string temps = "World";
    LinkedList s3(temps);
    printTest("s3: construct from std::string", s3);


    std::cout << "\n== Testing Print Reverse ==\n";
    std::cout << "s1 reversed: \"";
    s1.printReverse();
    std::cout << "\"\n";
    std::cout << "s2 reversed: \"";
    s2.printReverse();
    std::cout << "\"\n";
    std::cout << "s3 reversed: \"";
    s3.printReverse();
    std::cout << "\"\n";


    std::cout << "\n== Testing Insert Front and Back ==\n";
    s1.insertFront('a');
    s1.insertBack('c');
    printTest("s1: add 'a' to front and 'c' to back", s1);
    s1.insertFront('b');
    printTest("s1: add 'b' to front", s1);
 

    std::cout << "\n== Testing Find ==\n";
    std::cout << "s3: \"" << s3 << "\"\n";
    std::cout << "\ts3 has r: " << std::boolalpha << s3.contains('r') << std::endl;
    std::cout << "\ts3 has z: " << std::boolalpha << s3.contains('z') << std::endl;


    std::cout << "\n == Testing Remove ==\n";    
    s3.remove('W');
    printTest("s3: remove W", s3);
    s3.remove('z');
    printTest("s3: remove z", s3);
    s3.remove('d');
    printTest("s3: remove d", s3);
    s3.remove('l');
    printTest("s3: remove l", s3);
    s3.remove('r');
    printTest("s3: remove r", s3);
    s3.remove('o');
    printTest("s3: remove o", s3);
    s3.remove('!');
    printTest("s3: remove !", s3);


    std::cout << "\n == Testing Insert After and Insert Before ==\n";    
    std::cout << "s2: \"" << s2 << "\"\n";
    s2.insertAfter('=','e');
    printTest("s2: insert = after e", s2);
    s2.insertAfter('!','o');
    printTest("s2: insert ! after o", s2);
    s2.insertAfter('k', 'z');
    printTest("s2: insert k after z", s2);
    s2.insertBefore('?','l');
    printTest("s2: insert ? before l", s2);
    s2.insertBefore('-', 'z');
    printTest("s2: insert - before z",s2);
    std::cout << std::endl;

    return 0;
}
