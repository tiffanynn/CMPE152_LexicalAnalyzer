#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "token.h"
using namespace std;

class Lexer{
    public:
    Token getNextToken();
};


Token Lexer::getNextToken(){
    /*
    Was thinking first, scan the file in here
    Get all the tokens and print them out when file is done scanned
    */
   ifstream in_stream;
   in_stream.open("test.txt");
   if(!in_stream){
       cout << "Cannot open file." << endl;
       exit(1);
   }
   char c;
   while(in_stream.get(c)){
       if(isspace(c)){
           //something with creating a new token
       }
       else if(c == '.'){
           //something here to deal with the float
       }
       else if(c == '{' || c == '}' || c ==';' || c== '<' || c == '>'){
           return Token(c);
       }
       //what about finding keywords?
   }
}