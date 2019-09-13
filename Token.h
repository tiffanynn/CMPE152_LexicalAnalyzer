#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Token
{
public:
	Token() {
		lexeme = "default";
		tokentype = "default";
	}
	Token(string lex, string type) {
		lexeme = lex;
		tokentype = type;
	}
	string lexeme;
	string tokentype;
	void print_token()
	{
		cout << "---------------------" << endl;
		cout << "Lexeme is: " << lexeme << endl;
		cout << "Token type: " << tokentype << endl;
		cout << "---------------------" << endl;
	}
};
