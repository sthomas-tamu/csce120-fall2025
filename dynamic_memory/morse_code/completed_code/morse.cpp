#include <iostream>

class MorseCode {
  private:
    char* code;
    unsigned int length;

  public:
    // default constructor
    MorseCode() : code {nullptr}, length{0} {}

    // constructor with initial symbols
    MorseCode(const char* c, unsigned int l) : code{nullptr}, length{l} {
        if(length > 0) { 
            code = new char[length];
            for(unsigned int i=0; i<length; ++i)
                code[i] = c[i];
        }
    }

    // copy constructor
    MorseCode(const MorseCode& source) : code{nullptr}, length{source.length} {
        if(length > 0) { 
            code = new char[length];
            for(unsigned int i=0; i<length; ++i)
                code[i] = source.code[i];
        }
    }

    // destructor
    ~MorseCode() { 
        if(code != nullptr)
            delete[] code;
    }

    // copy assignment operator
    MorseCode& operator=(const MorseCode& source) {
        if(code != nullptr)
            delete[] code;

        length = source.length;    
        if(length > 0) { 
            code = new char[length];
            for(unsigned int i=0; i<length; ++i)
                code[i] = source.code[i];
        }
    
        return *this;
    }

    // getter methods
    unsigned int getLength() const { return length; }
    char getSymbol(unsigned int i) const { return code[i]; }

    // concat operator
    //   add a space only if both codes are not empty
    MorseCode operator+(const MorseCode& other) const {
        unsigned int space = 0;
        if((length > 0) && (other.length > 0))
            space = 1;

        unsigned int newLength = length + space + other.length;
        char* newCode = new char[newLength];

        for(unsigned int i=0; i<length; ++i) 
            newCode[i] = code[i];
 
        if(space == 1)
            newCode[length] = ' ';

        for(unsigned int i=0; i<other.length; ++i) 
            newCode[length + space + i] = other.code[i];

        MorseCode result(newCode, newLength);
        delete[] newCode; // clean up temporary memory
        return result;
    }
};

std::ostream& operator<<(std::ostream& os, const MorseCode& mc) {
    for(unsigned int i=0; i<mc.getLength(); ++i) 
        os << mc.getSymbol(i);
    return os;
}

int main() {
    // create morse code symbols S and O
    MorseCode S("...", 3);
    std::cout << "S: \"" << S << "\"\n";
    MorseCode O("---", 3);
    std::cout << "O: \"" << O << "\"\n";
   
    // create distress signal
    MorseCode help = S + O + S;
    std::cout << "help: \"" << help << "\"\n";

    // check that + words when one or both sides is empty
    MorseCode empty;
    std::cout << "S + empty: \"" << (S + empty) << "\"\n";
    std::cout << "empty + S: \"" << (empty + S) << "\"\n";
    std::cout << "S + empty + O: \"" << (S + empty + O) << "\"\n";  
    std::cout << "empty + empty: \"" << (empty + empty) << "\"\n";
 
    return 0;
}
