#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Token {
    public:
    Token(int t);
    string toString();
    int token_value; //final keyword?
};

Token::Token(int t){
 token_value  = t;
};

string Token::toString(){
    return ("" + (char)token_value);
};
