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

   ifstream in_stream;
   in_stream.open("test.txt");
   if(!in_stream){
       cout << "Cannot open file." << endl;
       exit(1);
   }

   char c;
   char file_contents[100];
   int size = 0;
   /*
   1. Scan characters from the file into an array or something lol
   2. Have a for-loop comparing the characters and tokens
   3. Push into the vector
   */ 
  while(in_stream.get(c)){
      file_contents[size] = c;
      size++;
  }


for(int i = 0; i < size; i++){}
       if(isspace(c)){
           //something with creating a new token
       }
       else if(c == '.'){
           //something here to deal with the float
       }
       else if(c == '{' || c == '}' || c ==';' || c== '<' || c == '>'){
           string symbol(1, c);
           Token something(symbol, symbol);
           obtained_tokens.push_back(something);
        
       }
       //what about finding keywords?
    
        //need to add stuff
  
           Token end("EOF", "EOF");
           obtained_tokens.push_back(end);
           break;
      
   return obtained_tokens;
}

void Lexer::print(){
    for(int i =0; i < obtained_tokens.size; i++){
        cout << obtained_tokens[i].lexerme << '\t' << obtained_tokens[i].token_value << endl;
    }
}