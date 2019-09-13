#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "token.h"
using namespace std;

class Lexer{
    public:
    Lexer();
    vector<Token> obtained_tokens;
    vector<Token> getNextToken();
    string token_names[18] = {"AND",
"BASE_TYPE","BREAK","DO", "ELSE","EQ","FALSE","FOR", "GE",
"ID", "IF", "LE","NE","NUM","OR", "REAL", "TRUE", "WHILE"
};
    void print();
};


//is this a function that we can use 
vector<Token> Lexer::getNextToken(){
    /*
    Was thinking first, scan the file in here
    Get all the tokens and print them out when file is done scanned
    */
   int size = 50;
   Token *tokens = new Token[size];
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
           tokens[i] = something;
           i++;
       }
       //what about finding keywords?
    
        //need to add stuff
       else if(in_stream.eof()){
           Token end("EOF", "EOF");
           tokens[i] = end;
           size = size+1;
           break;
       }
   }
   return *tokens;
}

void Lexer::print(){
    for(int i =0; i < size; i++){
        cout << obtained_tokens[i].lexerme << '\t' << obtained_tokens[i].token_value << endl;
    }
    delete[] obtained_tokens;
}