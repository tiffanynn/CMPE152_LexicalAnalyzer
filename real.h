#include "token.h"


class Real : public Token{
    public:
    Real(float v);
    float value; //final keyword 
    string toString();

};

Real::Real(float v){
    value = v;
}; //stuck on the constructor

string Real::toString(){
    return "" + value;
}