#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


std::string tolower(std::string wd) {
    for (size_t i=0; i<wd.size(); ++i) {
        wd.at(i) = tolower(wd.at(i));
    }
    return wd;
}


std::string getReplace() {
    return "***";
}


int main() {
    // set filenames - hardcoded but could update to read from cin
    std::string censorWordsFilename = "censorwords.txt";
    std::string originalTextFilename = "input.txt";
    std::string censoredTextFilename = "censored.txt";

    // create filestreams
    std::ifstream censorIn(censorWordsFilename);
    std::ifstream origIn(originalTextFilename);
    std::ofstream censorOut(censoredTextFilename);
    // TODO: add code to check all opened properly

    // get list of words to censor from file
    std::string censorWords;
    std::string censorWord;
    while (censorIn >> censorWord) { // the >> operator will use whitespace to determine the end of the std::string
                                     // failure checking is built in: 
                                     //   the >> operator returns a reference to the stream, 
                                     //   evaluating the stream as a boolean returns the same value as the stream's fail() function
        censorWords += (" " + tolower(censorWord)); // append the new word to a std::string with all the censor words
    }

    std::cout << "DEBUG::censorWords: " << censorWords << std::endl;

    // read original text, censor text, write out updated text to output file
    // process text line by line, until the end of the file:
        // get next line
        // see if each censor word is in line
        // if it is there, replace with symbols
        // output modified line
    while (!origIn.eof()) {
        std::string line;
        getline(origIn, line);
        // TODO: add code to check if getline executed properly

        std::cout << "DEBUG::processing line: " << line << std::endl;

        std::string lineOut = line;
        std::istringstream censorWds(censorWords); // treat the list of censor words as an input stream
        std::string censorWd;
        while (censorWds >> censorWd) { // while there are censor words to process (failure checking built in, see earlier while loop comments)
            std::string lowerLine = tolower(line); // make a temporary copy with the std::string convered to lower case to match against censor words
            size_t position = lowerLine.find(censorWd);
            while (position != std::string::npos) {
                std::cout << "DEBUG::   found censor word " << censorWd << " at position " << position << ", replacing" << std::endl;
                lowerLine.replace(position, censorWd.size(), getReplace());
                lineOut.replace(position, censorWd.size(), getReplace());
                position = lowerLine.find(censorWd);
            }
        }
        std::cout << "DEBUG::line becomes: " << lineOut << std::endl;
        censorOut << lineOut << std::endl;
    }

    return 0; //do not need to close std::ifstreams/std::ofstream because this is done by their destructors
}
