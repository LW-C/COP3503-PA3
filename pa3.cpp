#include <iostream>
#include "pa3.h"
#include <fstream>


/*
 *  Open the file reading class in the main method
 *  and pass it as a parameter to the methods that
 *  will open and read the file.
 */


std::ifstream getFile()
{
    /*
     *  This method will get the file name from the user.
     *  The main method will check to see if it is a
     *  valid file.
     */
}

void readFile(std::ifstream)
{
    /*
     *  This method will read the file that was opened
     *  in the openFile method. It will call push
     *  methods from the Stack class to add the input to
     *  the Stack.
     */
    // Check shunting-yard algorithm on Wikipedia
}

void printOutput(int depth, Stack* theStack)
{
    // Depth
    std::cout << "OUTPUT> The depth of nested loop(s) is ";
    std::cout << depth << "\n";

    // Keywords
    std::cout << "Keywords: ";
    if(theStack->getKeywordSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getKeywordSize(); i++)
        {
            std::cout << theStack->popKeyword() << " ";
        }
    }
    std::cout << "\n";

    // Identifiers
    std::cout << "Identifiers: ";
    if(theStack->getIdentifierSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getIdentifierSize(); i++)
        {
            std::cout << theStack->popIdentifier() << " ";
        }
    }
    std::cout << "\n";

    // Constants
    std::cout << "Constants: ";
    if(theStack->getConstantSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getConstantSize(); i++)
        {
            std::cout << theStack->popConstant() << " ";
        }
    }
    std::cout << "\n";

    // Operators
    std::cout << "Operators: ";
    if(theStack->getOperatorSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getOperatorSize(); i++)
        {
            std::cout << theStack->popOperator() << " ";
        }
    }
    std::cout << "\n";

    //Delimiters
    std::cout << "Delimiters: ";
    if(theStack->getDelimiterSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getDelimiterSize(); i++)
        {
            std::cout << theStack->popDelimiter() << " ";
        }
    }
    std::cout << "\n";

    // Syntax Errors
    std::cout << "Syntax Error(s): ";
    if(theStack->getSyntaxErrorSize() == 0)
        std::cout << "NA";
    else{
        for(int i = 0; i<theStack->getSyntaxErrorSize(); i++)
        {
            std::cout << theStack->popSyntaxError() << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    // Call getFile
    /*
     *  Check to see if the file is valid. If it is,
     *  continue. Otherwise, give an error and terminate
     *  the program.
     */
    // Call readFile
    return 0;
}