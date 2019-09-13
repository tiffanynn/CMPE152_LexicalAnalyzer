#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Token {
    public:
    Token();
    Token(string input, string attributes);
    string lexerme;
    string token_value; 

};

Token::Token(){
    lexerme = "";
    token_value = "";
}
Token::Token(string input, string attributes){
    lexerme = input;
    token_value = attributes;
};
