#include <iostream>
#include <string>

int main() {
    std::string term;

    do {
        std::cout << "Enter std::string to convert to an integer or '.' to exit: ";
        std::cin >> term;

        if(term != ".") {
            size_t size = 0;
            try {
                int value = std::stoi(term, &size);
                std::cout << term << " times 2 is " << (value * 2) << std::endl;
            }
            catch (std::invalid_argument& e) {
                std::cout << "invalid argument - " << e.what() << std::endl;
            }
            catch (std::out_of_range& e) {
                std::cout << "out of range - " << e.what() << std::endl;
            } 
    	    catch (std::exception& e) {
                std::cout << "other exception - " << e.what() << std::endl;
            }
    	    catch ( ... ) {
                std::cout << "unknown exception" << std::endl;
    	    }
        }
    } while (term != ".");

    return 0;
}
