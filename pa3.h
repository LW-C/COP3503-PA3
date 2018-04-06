#include <vector>

class Stack
{
private:
    const std::string KEYWORDSlist[3] = {"BEGIN", "END", "FOR"};
    const std::string OPERATORSlist[7] = {"+", "-", "*", "/", "++", "=", "=="};
    const std::string DELIMITERSlist[2] = {",", ";"};
    std::vector<std::string> keywords;
    std::vector<std::string> identifiers;
    std::vector<std::string> constants;
    std::vector<std::string> operators;
    std::vector<std::string> delimiteres;
    std::vector<std::string> syntaxErrors;
public:
    Stack();
    void push(std::string);             //Calls the other methods to push a string to the end of the appropriate vector
    void pushKeyword(std::string);
    void pushIdentifier(std::string);
    void pushConstant(std::string);
    void pushOperator(std::string);
    void pushDelimiter(std::string);
    void pushSyntaxError(std::string);
    std::string pop();                  //Calls the other methods to pop a string from the end of the appropriate vector
                                        //Is this method necessary?
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