/*
 *  Program written by Lauren Wonicker-Cook
 *  for COP3503 Programming Assignment #3.
 */

#include <iostream>
#include "pa3.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>

/*
 *  Open the file reading class in the main method
 *  and pass it as a parameter to the methods that
 *  will open and read the file.
 */

Stack::Stack() = default;

void Stack::addDepth()
{
    depth++;
}

int Stack::getDepth()
{
    return depth;
}

void Stack::push(std::string a)
{
    /*
     *  This method will check to see which
     *  vector the string belongs in.
     */
    std::cout << a << "\n";
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

/*static void PA3::printOutput(Stack * theStack)
{
    // Depth
    std::cout << "OUTPUT> The depth of nested loop(s) is ";
    std::cout << depth << "\n";

    // Keywords
    std::cout << "Keywords: ";
    if (theStack->getKeywordSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getKeywordSize(); i++) {
            std::cout << theStack->popKeyword() << " ";
        }
    }
    std::cout << "\n";

    // Identifiers
    std::cout << "Identifiers: ";
    if (theStack->getIdentifierSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getIdentifierSize(); i++) {
            std::cout << theStack->popIdentifier() << " ";
        }
    }
    std::cout << "\n";

    // Constants
    std::cout << "Constants: ";
    if (theStack->getConstantSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getConstantSize(); i++) {
            std::cout << theStack->popConstant() << " ";
        }
    }
    std::cout << "\n";

    // Operators
    std::cout << "Operators: ";
    if (theStack->getOperatorSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getOperatorSize(); i++) {
            std::cout << theStack->popOperator() << " ";
        }
    }
    std::cout << "\n";

    //Delimiters
    std::cout << "Delimiters: ";
    if (theStack->getDelimiterSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getDelimiterSize(); i++) {
            std::cout << theStack->popDelimiter() << " ";
        }
    }
    std::cout << "\n";

    // Syntax Errors
    std::cout << "Syntax Error(s): ";
    if (theStack->getSyntaxErrorSize() == 0)
        std::cout << "NA";
    else {
        for (int i = 0; i < theStack->getSyntaxErrorSize(); i++) {
            std::cout << theStack->popSyntaxError() << " ";
        }
    }
    std::cout << "\n";
}
*/
/*
 *  Main will get the file name from the user.
 *  It will the check to see if it is a valid file.
 *  If it is, it will continue. Otherwise, it will
 *  give an error and terminate the program. It then
 *  reads the file that was opened and calls the push
 *  method from the Stack class to add the input to
 *  the Stack.
 */
int main()
{
    // Get the file from the user
    std::string fn;
    std::cout << "INPUT> Please enter the name of the input file:\n";
    std::cin >> fn;
    std::ifstream theFile(fn);

    // Check to see if the file is valid.
    if(!theFile)
    {
        std::cerr << "The file could not be opened\n";
        return 1;
    }

    // Read the file to the Stack
    Stack * theStack = new Stack();
    // The while loop checks to see if there is something
    // else to read from the file.
    std::string toPush = "";
    std::string theWord = " ";
    while(theFile >> theWord)
    {
        //std::cout << aLine << "\n";
        char c;
        int i=0;
        char str[] = {};
        std::string aWord = theWord;
        strcpy(str, aWord.c_str());     //This line causes an error because it deletes the reference and the next time around it gives a seg fault
        while(str[i])
        {
            c = str[i];
            toPush.push_back(c);
            i++;
        }
        theStack->push(toPush);
    }

    // Closing the file
    theFile.close();

    // Printing the output
    //PA3::printOutput(theStack);

    /*
     *  Testing:
     *  Stack *theStack = new Stack();
     *  theStack->pushKeyword("Test");
     *  std::cout << theStack->popKeyword();
     */

    return 0;
}
