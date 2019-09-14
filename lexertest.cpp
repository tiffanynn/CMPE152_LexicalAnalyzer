#include "lexer.h"
using namespace std;

int main()
{
	Lexer lex;
	lex.getNextToken();
    lex.print();

    return 0;
}