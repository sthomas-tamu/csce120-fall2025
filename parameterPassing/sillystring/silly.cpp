#include <iostream>
#include <string>
#include <ctime>

//return the middle of the string
std::string getMiddleThird(std::string& str) {
    std::string retStr;

    size_t third = str.size()/3; // will accept there may be some rounding errors
    for (size_t i=third; i<(third*2); ++i) {
        retStr += str.at(i);
    }

    // side effect to fix
    str.at(str.size()/2) = '?';

    return retStr;
}


// randomly swap characters from the first half of the string with the second half
void shuffle(std::string& str) {
    for (size_t i=0; i<str.size()/2; ++i) {
        size_t index = random() % (str.size() / 2);

        char temp = str.at(index);
        str.at(index) = str.at(str.size()-1-index);
        str.at(str.size()-1-index) = temp;
    }
}


int main() {
    srand(time(NULL));

    std::cout << "Enter a string: ";
    std::string str;
    std::getline(std::cin, str);

    shuffle(str);
    std::cout << "String: " << str << std::endl;

    std::cout << "Middle third: " << getMiddleThird(str) << std::endl;
    std::cout << "String: " << str << std::endl;

    return 0;
}
