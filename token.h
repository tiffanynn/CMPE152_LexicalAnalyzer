#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Token {
    public:
    Token();
    private:
    string input;
    int token_value;
    string tmp; 
};

Token::Token(){
}