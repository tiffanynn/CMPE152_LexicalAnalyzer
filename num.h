#include "token.h"


class Num : public Token{
    public:
    Num(int v);
    int  value; //final keyword 
    string toString();

};

Num::Num(int v){
    value = v;
}; //stuck on the constructor

string Num::toString(){
    return "" + value;
}