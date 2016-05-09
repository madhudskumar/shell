%{
    #include<ctype.h>
    int i = 0;
    char ip[50];   
%}

%token id
%left '+' '-' '*' '/'

%%
E:S {infixToPostfix(ip);}

S:S'+'T | S'-'T
|T

T:T'*'F | T'/'F
|F

F:id | '('S')'
;
%%

#include"err.h"

main(){
    printf("\nEnter an expressin : ");
    yyparse();
}

yyerror(){
    err("invalid str", -1);
}

yylex(){
    char ch;
    while((ch = str[i++] = getchar())!='\n'){
         if(ch) return id;
         if(ch == '*' || ch == '/' || ch == '-' || ch == '+') return ch;
    }
    str[i--] = '\0'
    return 0; 
    exit 0;
}

void push(char stack[], int *top, char ch){
    stack[++(*top)] = ch;
}

char pop(char stack[], int *top){
    return stack[(*top)--];
}

infixToPostfix(char infix[]){
    
}