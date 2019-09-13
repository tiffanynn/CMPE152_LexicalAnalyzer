#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Token {
    public:
    Token(char t);
    string toString();
    int token_value; 
    string token_names[18] = {"AND",
"BASE_TYPE","BREAK","DO", "ELSE","EQ","FALSE","FOR", "GE",
"ID", "IF", "LE","NE","NUM","OR", "REAL", "TRUE", "WHILE"
};

};

Token::Token(char t){
 token_value  = t;
};
