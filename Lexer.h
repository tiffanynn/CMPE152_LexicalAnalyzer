#pragma once
#include "Token.h"


class Lexer
{
public:
	int line;
	Token *tokarr;
	int arrsize;
	char peek;
	Lexer() 
	{
		arrsize = 100;
		tokarr = new Token[arrsize];
		peek = ' ';
		line = 0;
	}
	void readchar(ifstream &fin)
	{
		fin >> noskipws >> peek;
	}

	bool validtok(char c, ifstream & fin)
	{
		readchar(fin);
		if (peek != c)
			return false;
		else
		{
			peek = ' ';
			return true;
		}
	}

	Token scan(ifstream &fin) 
	{
		Token tok;
		for(;;readchar(fin))
		{
			cout << peek << endl;
			if (peek == '\t' || peek == ' ')
			{
				continue;
			}
			else if (peek == '\n')
			{
				line += 1;
			}
			else
			{
				cout << "breaking now" << endl;
				break;
			}
		}
		return tok;
	}

	void LexAnalysis(string filename)
	{
		ifstream fin;
		Lexer lex;
		fin.open(filename);
		if (fin.fail())
		{
			cout << "File opening failed!" << endl;
			exit(1);
		}
		while (!fin.fail())
		{
			Token temp;
			temp = scan(fin);
			temp.print_token();
		}
		fin.close();
	}

};