#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "token.h"
using namespace std;

class Lexer{
    public:
    Lexer();
    Token *getNextToken();
    Token *obtained_tokens;
    int size;
    string token_names[18] = {"AND",
"BASE_TYPE","BREAK","DO", "ELSE","EQ","FALSE","FOR", "GE",
"ID", "IF", "LE","NE","NUM","OR", "REAL", "TRUE", "WHILE"
};
    int size;
    void print();
};

Lexer::Lexer(){
    //have a set number first for the size
    size = 50;
    Token *obtained_tokens = new Token[size];
}
Token Lexer::*getNextToken(){
    /*
    Was thinking first, scan the file in here
    Get all the tokens and print them out when file is done scanned
    */
    int size = 50;
    Token *obtained_tokens = new Token[size];
   ifstream in_stream;
   in_stream.open("test.txt");
   if(!in_stream){
       cout << "Cannot open file." << endl;
       exit(1);
   }
   char c;
   int i = 0;

   while(in_stream.get(c)){

       if(isspace(c)){
           //something with creating a new token
       }
       else if(c == '.'){
           //something here to deal with the float
       }
       else if(c == '{' || c == '}' || c ==';' || c== '<' || c == '>'){
           Token something(c, c);
           obtained_tokens[i] = something;
           i++;
       }
       //what about finding keywords?
    
        //need to add stuff
       else if(in_stream.eof()){
           //Token eof();
           //not sure how to account for EOF token
       }
   }
   return *obtained_tokens;
}

void Lexer::print(){
    for(int i =0; i < size; i++){

    }
}