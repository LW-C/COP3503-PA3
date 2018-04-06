/*
 *  Program written by Lauren Wonicker-Cook
 *  for COP3503 Programming Assignment #3.
 */

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

Stack::Stack()
{
}

void Stack::push(std::string a)
{
    /*
     *  This method will check to see which
     *  vector the string belongs in.
     */
}

void Stack::pushKeyword(std::string a)
{
    keywords.push_back(a);
}

void Stack::pushIdentifier(std::string a)
{
    identifiers.push_back(a);
}

void Stack::pushConstant(std::string a)
{
    constants.push_back(a);
}

void Stack::pushOperator(std::string a)
{
    operators.push_back(a);
}

void Stack::pushDelimiter(std::string a)
{
    delimiters.push_back(a);
}

void Stack::pushSyntaxError(std::string a)
{
    syntaxErrors.push_back(a);
}

std::string Stack::popKeyword()
{
    std::string a = keywords.back();
    keywords.pop_back();
    return a;
}

std::string Stack::popIdentifier()
{
    std::string a = identifiers.back();
    identifiers.pop_back();
    return a;
}

std::string Stack::popConstant()
{
    std::string a = constants.back();
    constants.pop_back();
    return a;
}

std::string Stack::popOperator()
{
    std::string a = operators.back();
    operators.pop_back();
    return a;
}

std::string Stack::popDelimiter()
{
    std::string a = delimiters.back();
    delimiters.pop_back();
    return a;
}

std::string Stack::popSyntaxError()
{
    std::string a = syntaxErrors.back();
    syntaxErrors.pop_back();
    return a;
}

int Stack::getKeywordSize()
{
    return static_cast<int>(keywords.size());
}

int Stack::getIdentifierSize()
{
    return static_cast<int>(identifiers.size());
}

int Stack::getConstantSize()
{
    return static_cast<int>(constants.size());
}

int Stack::getOperatorSize()
{
    return static_cast<int>(operators.size());
}

int Stack::getDelimiterSize()
{
    return static_cast<int>(delimiters.size());
}

int Stack::getSyntaxErrorSize()
{
    return static_cast<int>(syntaxErrors.size());
}

int main() {
    // Call getFile
    /*
     *  Check to see if the file is valid. If it is,
     *  continue. Otherwise, give an error and terminate
     *  the program.
     */
    // Call readFile
    Stack* theStack = new Stack();
    theStack->pushKeyword("Test");
    theStack->popKeyword();
    return 0;
}