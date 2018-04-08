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
#include <stdlib.h>
#include <ctype.h>

/*
 *  Open the file reading class in the main method
 *  and pass it as a parameter to the methods that
 *  will open and read the file.
 */

Stack::Stack() = default;

void Stack::calcDepth()
{
    int max = 0;
    if(numFor > max)
        max = numFor;
    if(numBegin > max)
        max = numBegin;
    if(numEnd > max)
        max = numEnd;
    int min = max;
    if((numFor < max))
        Stack::pushSyntaxError("FOR");
    if(numFor < min)
        min = numFor;
    if((numBegin < max) && !(beginTypo))
        Stack::pushSyntaxError("BEGIN");
    if(numBegin < min)
        min = numBegin;
    if((numEnd < max) && !(endTypo))
        Stack::pushSyntaxError("END");
    if(numEnd < min)
        min = numEnd;

    if(depth < min)
        depth = min;
}

int Stack::getDepth()
{
    return depth;
}

/*
 *  push will check to see which
 *  vector the string belongs in.
 */
void Stack::push(std::string a)
{
    /*
     *  This section checks the strings that have
     *  a length greater than one. This may include
     *  strings that contain other strings, like
     *  operators, constants or delimiters.
     */
    if(a.size() > 1)
    {
        // Check to see if the string is a constant
        bool isNotNum = false;
        int j = a.size();
        for(int i = 0; i < j; i++)
        {
            if(!(isdigit(a[i])))
            {
                isNotNum = true;
                break;
            }
        }
        if(!isNotNum)
        {
            Stack::pushConstant(a);
            if(lastIsFor)
            {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
            return;
        }
            // Check to see if the string is a keyword
        else if((a.compare("FOR") == 0) || (a.compare("For") == 0) || (a.compare("for") == 0))
        {
            Stack::pushKeyword(a);
            lastIsFor = true;
            numFor++;
            return;
        }
        else if((a.compare("BEGIN") == 0) || (a.compare("Begin") == 0) || (a.compare("begin") == 0))
        {
            // Check to see if there is a )
            if(!hasCloseParen) {
                Stack::pushSyntaxError(")");
                //depth--;
            }
            hasCloseParen = false;
            Stack::pushKeyword(a);
            lastIsFor = false;
            numBegin++;
            return;
        }
        else if((a.compare("END") == 0) || (a.compare("End") == 0) || (a.compare("end") == 0))
        {
            Stack::pushKeyword(a);
            lastIsFor = false;
            ++numEnd;
            return;
        }

        // Check to see if the string is an operator
        else if((a.compare("++") == 0) || (a.compare("--") == 0)
                || (a.compare("==") == 0) || (a.compare("!=") == 0))
        {
            Stack::pushOperator(a);
            if(lastIsFor)
            {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
            return;
        }

        // Check to see if the string contains a another string (delimiter, constant, etc.)
        int x = a.find(";");
        int y = a.find(")");
        int z = a.find("(");
        int xx = a.find(",");
        int yy = a.find("=");
        if((x != -1) || (y != -1))
        {
            Stack::push(a.substr(0, a.size()-1));
            Stack::push(a.substr(a.size()-1, 1));
        }
        else if(z != -1)
        {
            Stack::push(a.substr(0, 1));
            Stack::push(a.substr(1, a.size()-1));
        }
        else if(xx != -1)
        {
            Stack::push(a.substr(0, a.size()-1));
            Stack::push(a.substr(a.size()-1, 1));
        }
        else if(yy != -1)
        {
            int find = a.find("=");
            int last = a.size() - 1;
            if(find == 0)
            {
                Stack::push(a.substr(0, 1));
                Stack::push(a.substr(1, a.size()-1));
            }
            else if(find == last)
            {
                Stack::push(a.substr(0, a.size()-1));
                Stack::push(a.substr(a.size()-1, 1));
            }
            else
            {
                Stack::push(a.substr(0, (-1)*(find-a.size())));
                Stack::push(a.substr(find, 1));
                Stack::push(a.substr(find+1, a.size()-find));
            }
        }

        // Check to see is the string is a typo
        else if((a.size() == 3))
        {
            bool typo = true;
            for(int i = 0; i < j; i++)
            {
                if(!(isupper(a[i])))
                {
                    typo = false;
                    break;
                }
            }
            if(typo)
            {
                Stack::pushSyntaxError(a);
                endTypo = true;
            }
            else
                Stack::pushIdentifier(a);
        }
        else if((a.size() == 5))
        {
            bool typo = true;
            for(int i = 0; i < j; i++)
            {
                if(!(isupper(a[i])))
                {
                    typo = false;
                    break;
                }
            }
            if(typo)
            {
                Stack::pushSyntaxError(a);
                beginTypo = true;
            }
            else
                Stack::pushIdentifier(a);
        }

        // Check to see if the string is an identifier
        else
        {
            Stack::pushIdentifier(a);
            if(lastIsFor)
            {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
        }
    }

    /*
     *  This section checks the strings that have a length
     *  of 1. These will not include any strings that
     *  could contain an operator, constant or delimiter.
     */
    else {
        // Check to see if the string is a constant
        if (isdigit(a[0])) {
            Stack::pushConstant(a);
            if (lastIsFor) {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
        }

        // Check to see if the string is a paren
        else if(a.compare("(") == 0)
        {
            lastIsFor = false;
            hasOpenParen = true;
        }
        else if(a.compare(")") == 0)
        {
            if(!hasOpenParen){
                Stack::pushSyntaxError(a);
                //depth--;
            }
            if(hasCloseParen){
                Stack::pushSyntaxError(a);
                //depth--;
            }
            hasCloseParen = true;
        }

        // Check to see if the string is a delimiter
        else if((a.compare(";") == 0) || (a.compare(",") == 0))
        {
            Stack::pushDelimiter(a);
        }

        // Check to see if the string is an operator
        else if((a.compare("+") == 0) || (a.compare("-") == 0) || (a.compare("*") == 0)
                || (a.compare("/") == 0) || (a.compare("%") == 0) || (a.compare("=") == 0))
        {
            Stack::pushOperator(a);
            if(lastIsFor)
            {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
        }

        // Check to see if the string is an identifier
        else
        {
            Stack::pushIdentifier(a);
            if(lastIsFor)
            {
                lastIsFor = false;
                Stack::pushSyntaxError("(");
                //depth--;
            }
        }
    }
}

void Stack::pushKeyword(std::string a)
{
    if(keywords.size() > 0) {
        int j = keywords.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(keywords[i]) == 0) {
                return;
            }
        }
    }
    keywords.push_back(a);
}

void Stack::pushIdentifier(std::string a)
{
    if(identifiers.size() > 0) {
        int j = identifiers.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(identifiers[i]) == 0) {
                return;
            }
        }
    }
    identifiers.push_back(a);
}

void Stack::pushConstant(std::string a)
{
    if(constants.size() > 0) {
        int j = constants.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(constants[i]) == 0) {
                return;
            }
        }
    }
    constants.push_back(a);
}

void Stack::pushOperator(std::string a)
{
    if(operators.size() > 0) {
        int j = operators.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(operators[i]) == 0) {
                return;
            }
        }
    }
    operators.push_back(a);
}

void Stack::pushDelimiter(std::string a)
{
    if(delimiters.size() > 0) {
        int j = delimiters.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(delimiters[i]) == 0) {
                return;
            }
        }
    }
    delimiters.push_back(a);
}

void Stack::pushSyntaxError(std::string a)
{
    if(syntaxErrors.size() > 0) {
        int j = syntaxErrors.size();
        for (int i = 0; i < j; ++i) {
            if (a.compare(syntaxErrors[i]) == 0) {
                return;
            }
        }
    }
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
    std::string theWord = " ";
    while(theFile >> theWord)
    {
        theStack->push(theWord);
    }

    // Closing the file
    theFile.close();

    // Calculating the depth
    theStack->calcDepth();

    // Printing the output
    // Depth
    std::cout << "OUTPUT> The depth of nested loop(s) is ";
    std::cout << theStack->getDepth() << "\n\n";

    // Keywords
    std::cout << "Keywords: ";
    if (theStack->getKeywordSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getKeywordSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popKeyword() << " ";
        }
    }
    std::cout << "\n";

    // Identifiers
    std::cout << "Identifiers: ";
    if (theStack->getIdentifierSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getIdentifierSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popIdentifier() << " ";
        }
    }
    std::cout << "\n";

    // Constants
    std::cout << "Constants: ";
    if (theStack->getConstantSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getConstantSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popConstant() << " ";
        }
    }
    std::cout << "\n";

    // Operators
    std::cout << "Operators: ";
    if (theStack->getOperatorSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getOperatorSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popOperator() << " ";
        }
    }
    std::cout << "\n";

    //Delimiters
    std::cout << "Delimiters: ";
    if (theStack->getDelimiterSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getDelimiterSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popDelimiter() << " ";
        }
    }
    std::cout << "\n\n";

    // Syntax Errors
    std::cout << "Syntax Error(s): ";
    if (theStack->getSyntaxErrorSize() == 0)
        std::cout << "NA";
    else {
        int j = theStack->getSyntaxErrorSize();
        for (int i = 0; i < j; i++) {
            std::cout << theStack->popSyntaxError() << " ";
        }
    }
    std::cout << "\n";

    /*
     *  Testing:
     *  Stack *theStack = new Stack();
     *  theStack->pushKeyword("Test");
     *  std::cout << theStack->popKeyword();
     */

    return 0;
}
