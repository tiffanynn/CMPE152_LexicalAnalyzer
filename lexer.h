#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "token.h"
using namespace std;

class Lexer
{
    public:
        Lexer();
        vector<Token> obtained_tokens;
        vector<Token> getNextToken();
        void print();
        char file_contents[100];
        int size;
};

Lexer::Lexer()
{
    obtained_tokens.push_back(Token("", ""));
    size = 0;
}

//is this a function that we can use
vector<Token> Lexer::getNextToken()
{
    /*
     Was thinking first, scan the file in here
     Get all the tokens and print them out when file is done scanned
     */

    ifstream in_stream;
    char c;
    in_stream.open("test.txt");
    if (!in_stream)
    {

        cout << "Cannot open file." << endl;
        exit(1);
    }

    /*
     1. Scan characters from the file into an array or something lol
     2. Have a for-loop comparing the characters and tokens
     3. Push into the vector
     */
    while (in_stream.get(c))
    {
//        if (isspace(c) || c == '/n')
//        {
//            continue;
//        }
        file_contents[size] = c;
        size++;

    }
    in_stream.close();

    //need to consider keywords and stuff

    for (int i = 0; i < size; i++)
    {

        string temp = ""; //need this to store in symbols/letters
        //checking if there's letters first
        if (isalpha(file_contents[i]))
        {
            int j = 0;
            for (j = i; j < size; j++)
            {
                if (!isalpha(file_contents[j]))
                {
                    break;
                }
                else
                {
                    temp += file_contents[j];
                }
            }

            i = j-1;

            if (temp == "while")
            {

                Token something(temp, "while");
                obtained_tokens.push_back(something);

            }
            else if (temp == "int")
            {
                Token something(temp, "BASE_TYPE");
                obtained_tokens.push_back(something);
            }
            else if (temp == "float")
            {
                Token something(temp, "BASE_TYPE");
                obtained_tokens.push_back(something);
            }
            else if (temp == "bool")
            {
                Token something(temp, "BASE_TYPE");
                obtained_tokens.push_back(something);
            }
            else if (temp == "true")
            {
                Token something(temp, "true");
                obtained_tokens.push_back(something);
            }
            else if (temp == "do")
            {
                Token something(temp, "do");
                obtained_tokens.push_back(something);
            }
            else if (temp == "false")
            {
                Token something(temp, "false");
                obtained_tokens.push_back(something);
            }
            else if (temp == "else")
            {
                Token something(temp, "else");
                obtained_tokens.push_back(something);
            }
            else if (temp == "break")
            {
                Token something(temp, "break");
                obtained_tokens.push_back(something);
            }
            else if (temp == "if")
            {
                Token something(temp, "if");
                obtained_tokens.push_back(something);
            }
            else
            {
                Token something(temp, "ID");
                obtained_tokens.push_back(something);
            }

        }

        else if (isdigit(file_contents[i]))
        {
            int j = 0;
            for (j = i; j < size; j++)
            {
                if (!isdigit(file_contents[j]))
                {
                    if (file_contents[j] == '.')
                    {
                        temp += file_contents[j];
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    temp += file_contents[j];
                }

            }
            int found = temp.find('.');
            i = j-1;
            if (found != -1)
            {
                Token something(temp, "FLOAT");
                obtained_tokens.push_back(something);
            }
            else
            {
                Token something(temp, "NUM");
                obtained_tokens.push_back(something);

            }
        }
        //considering the symbols
        else if (file_contents[i] == '{' || file_contents[i] == '}')
        {
            string symbol(1, file_contents[i]);
            Token something(symbol, symbol);
            obtained_tokens.push_back(something);
        }

        else if (file_contents[i] == ';' || file_contents[i] == '+')
        {
            string symbol(1, file_contents[i]);
            Token something(symbol, symbol);
            obtained_tokens.push_back(something);
        }
        else if (file_contents[i] == '-' || file_contents[i] == '*')
        {
            string symbol(1, file_contents[i]);
            Token something(symbol, symbol);
            obtained_tokens.push_back(something);
        }
        else if (file_contents[i] == '(' || file_contents[i] == ')')
        {
            string symbol(1, file_contents[i]);
            Token something(symbol, symbol);
            obtained_tokens.push_back(something);
        }
        else if (file_contents[i] == '/')
        {
            string symbol(1, file_contents[i]);
            Token something(symbol, symbol);
            obtained_tokens.push_back(something);
        }
        else if (file_contents[i] == '!')
        {
            temp += file_contents[i];
            if (file_contents[i + 1] == '=')
            {
                temp += file_contents[i + 1];
                Token something(temp, "NE");
                obtained_tokens.push_back(something);
                i = i + 1;
            }

            else
            {
                Token something(temp, temp);
                obtained_tokens.push_back(something);
            }

        }
        else if (file_contents[i] == '>' || file_contents[i] == '<')
        {
            temp = file_contents[i];
            if (file_contents[i] == '>')
            {
                if (file_contents[i + 1] == '=')
                {
                    temp += file_contents[i + 1];
                    Token something(temp, "GE");
                    obtained_tokens.push_back(something);
                    i = i + 1;
                }
                else
                {
                    Token something(temp, temp);
                    obtained_tokens.push_back(something);
                }
            }

            else if (file_contents[i] == '<')
            {
                if (file_contents[i + 1] == '=')
                {
                    temp += file_contents[i + 1];
                    Token something(temp, "LE");
                    obtained_tokens.push_back(something);
                    i = i + 1;
                }
                else
                {
                    string symbol(1, file_contents[i]);
                    Token something(symbol, symbol);
                    obtained_tokens.push_back(something);
                }
            }

        }
        else if (file_contents[i] == '&')
        {
            temp += file_contents[i];
            if (file_contents[i + 1] == '&')
            {

                temp += file_contents[i + 1];
                Token something(temp, "AND");
                obtained_tokens.push_back(something);
                i = i + 1;
            }

            else
            {
                Token something(temp, temp);
                obtained_tokens.push_back(something);
            }
        }
        else if (file_contents[i] == '=')
        {
            temp += file_contents[i];
            if (file_contents[i + 1] == '=')
            {

                temp += file_contents[i + 1];
                Token something(temp, "EQ");
                obtained_tokens.push_back(something);
                i = i + 1;
            }

            else
            {
                Token something(temp, temp);
                obtained_tokens.push_back(something);
            }
        }

    }
    Token end("EOF", "EOF");
    obtained_tokens.push_back(end);

    return obtained_tokens;
}

void Lexer::print()
{
    int vector_size = obtained_tokens.size();
    for (int i = 0; i < vector_size; i++)
    {
        cout << obtained_tokens[i].lexerme << '\t'
                << obtained_tokens[i].token_value << endl;
    }
}
