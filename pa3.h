#include <vector>

class Stack
{
private:
    int depth = 0;
    //const std::string KEYWORDSlist[3] = {"BEGIN", "END", "FOR"};
    //const std::string OPERATORSlist[7] = {"+", "-", "*", "/", "++", "=", "=="};
    //const std::string DELIMITERSlist[2] = {",", ";"};
    bool hasOpenParen = false;
    bool hasCloseParen = false;
    bool lastIsFor = false;
    int numBegin = 0;
    int numEnd = 0;
    int numFor = 0;
    std::vector<std::string> keywords;
    std::vector<std::string> identifiers;
    std::vector<std::string> constants;
    std::vector<std::string> operators;
    std::vector<std::string> delimiters;
    std::vector<std::string> syntaxErrors;
public:
    Stack();
    void calcDepth();
    int getDepth();
    void push(std::string a);             //Calls the other methods to push a string to the end of the appropriate vector
    void pushKeyword(std::string a);
    void pushIdentifier(std::string a);
    void pushConstant(std::string a);
    void pushOperator(std::string a);
    void pushDelimiter(std::string a);
    void pushSyntaxError(std::string a);
    std::string popKeyword();
    std::string popIdentifier();
    std::string popConstant();
    std::string popOperator();
    std::string popDelimiter();
    std::string popSyntaxError();
    int getKeywordSize();
    int getIdentifierSize();
    int getConstantSize();
    int getOperatorSize();
    int getDelimiterSize();
    int getSyntaxErrorSize();
};