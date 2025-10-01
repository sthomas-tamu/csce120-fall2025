#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;

string tolower(string wd) {
    for (size_t i=0; i<wd.size(); ++i) {
        wd.at(i) = tolower(wd.at(i));
    }
    return wd;
}

string getReplace(string wd) {
    return "***";
}

int main() {
    // set filenames - hardcoded but could update to read from cin
    string censorWordsFilename = "censorwords.txt";
    string originalTextFilename = "input.txt";
    string censoredTextFilename = "censored.txt";

    // create filestreams
    ifstream censorIn(censorWordsFilename);
    ifstream origIn(originalTextFilename);
    ofstream censorOut(censoredTextFilename);
    // TODO #2: add code to check opened properly

    // get list of words to censor from file
    string censorWords;
    string censorWord;
    while (censorIn >> censorWord) { // the >> operator will use whitespace to determine the end of the string
                                     // failure checking is built in: 
                                     //   the >> operator returns a reference to the stream, 
                                     //   evaluating the stream as a boolean returns the same value as the stream's fail() function
        censorWords += (" " + tolower(censorWord)); // append the new word to a string with all the censor words
    }

    // TODO #1: print out list of censored words for debugging

    // read original text, censor text, write out updated text to output file
    // process text line by line, until the end of the file:
        // get next line
        // see if each censor word is in line
        // if it is there, replace with symbols
        // output modified line
    while (!origIn.eof()) {
        string line;
        getline(origIn, line);
        // TODO #2: add code to check if getline executed properly

        // TODO #1: print out line you are about to process for debugging

        string lineOut = line;
        istringstream censorWds(censorWords); // treat the list of censor words as an input stream
        string censorWd;
        while (censorWds >> censorWd) { // while there are censor words to process (failure checking built in, see earlier while loop comments)
            string lowerLine = tolower(lineOut); // make a temporary copy with the string convered to lower case to match against censor words
            size_t position = lowerLine.find(censorWd);
            while (position != string::npos) {
                // TODO #1: print out the censor word you found and the position its position for debugging
                lowerLine.replace(position, censorWd.size(), getReplace(censorWd));
                lineOut.replace(position, censorWd.size(), getReplace(censorWd));
                position = lowerLine.find(censorWd);
            }
        }
        // TODO #1: print out the updated line for debugging
        censorOut << lineOut << endl;
    }

    return 0; //do not need to close ifstreams/ofstream because this is done by their destructors
}
