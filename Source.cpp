#include "Lexer.h"

int main()
{
	Token *tokarr = new Token[50];
	Lexer lex;
	lex.LexAnalysis("test.txt");
}


