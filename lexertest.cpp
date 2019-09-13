/*testing*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char tempstorage[]){
char keywords[32][10] = {"and","base_type","break","do","else","eq","false","for","ge","id","if","le","ne","num","or", "true","struct","real","while","return","short","signed","sizeof","static","switch","unsigned"};

int i, flag = 0;
    
for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], tempstorage) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    char ch, tempstorage[15], operators[] = "+-*/%=";
    ifstream fin;
    fin.open("test.txt");
    int i,j=0;
    if(!fin.is_open()){
        cout<<"File cannot be read\n";
        exit(0);
    }
    
    while(!fin.eof()){
        ch = fin.get();
    
        for(i = 0; i < 6; ++i){
            if(ch == operators[i])
                cout<<ch<<" is an operator\n";
        }
        
        if(isalnum(ch)){
            tempstorage[j++] = ch;
        }
        
        else if((ch == ' ' || ch == '\n') && (j != 0)){
            tempstorage[j] = '\0';
            j = 0;
            
            if(isKeyword(tempstorage) == 1)
                cout<<tempstorage<<" is a keyword\n";
            
            else
                cout<<tempstorage<<" is an identifier\n";
        }
    }
    fin.close();
    return 0;
}
