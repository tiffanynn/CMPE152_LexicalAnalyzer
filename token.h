#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Token {
    public:
    Token(int t);
    string toString();
    int token_value; 
    string keywords[18] = {"AND",
"BASE_TYPE","BREAK","DO", "ELSE","EQ","FALSE","FOR", "GE",
"ID", "IF", "LE","NE","NUM","OR", "REAL", "TRUE", "WHILE"
};

};

Token::Token(int t){
 token_value  = t;
};

string Token::toString(){
    return ("" + (char)token_value);
};
