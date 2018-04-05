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
public:
    void push(std::string);
    std::string pop(int);
    std::string pop(std::string);
};