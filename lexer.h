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

//need to consider keywords and stuff
string temp = ""; //need this to store in letters 

for(int i = 0; i < size; i++){
    //checking if there's letters first
    if(isalpha(file_contents[i])){
        //probably going to hard code everything
        temp += file_contents[i];
        //don't know how to deal with any letters oop

        // if(file_contents[i] == 't'){
        //     if(file_contents[i] == 't'){}
        //     else{}
        // }

    }

    //considering the symbols
    else if(file_contents[i] == '{' || file_contents[i] == '}' || file_contents[i] ==';' || file_contents[i] = '+' ||
    file_contents[i] == '-' ||file_contents[i] == '*' || file_contents[i] == '(' || file_contents[i] == ')' || file_contents[i] == '/'){
           string symbol(1, file_contents[i]);
           Token something(symbol, symbol);
           obtained_tokens.push_back(something);
       }
    else if(file_contents[i]  == '>' || file_contents[i] == '<')
    {
        temp = file_contents[i];
        if(file_contents[i]  == '>'){
            if(file_contents[i+1] == '='){
                temp += file_contents[i+1];
                Token something(temp, "GE");
                obtained_tokens.push_back(something);
            }
            else{
          string symbol(1, file_contents[i]);
           Token something(symbol, symbol);
           obtained_tokens.push_back(something);
           }
        }
        else if(file_contents[i]  == '<'){
            if(file_contents[i+1] == '='){
                temp += file_contents[i+1];
                Token something(temp, "LE");
                obtained_tokens.push_back(something);
            }
else{
          string symbol(1, file_contents[i]);
           Token something(symbol, symbol);
           obtained_tokens.push_back(something);
           }
        }
    }
   else if( i == (size-1)){
           Token end("EOF", "EOF");
           obtained_tokens.push_back(end);
    }
}


           
      
   return obtained_tokens;
}

void Lexer::print(){
    for(int i =0; i < obtained_tokens.size; i++){
        cout << obtained_tokens[i].lexerme << '\t' << obtained_tokens[i].token_value << endl;
    }
}