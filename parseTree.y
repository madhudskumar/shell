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
    char ch = ' ';
    while((ch = ip[i++] = getchar())!= '\n'){
         if(isalnum(ch)) return id;
         if(ch == '*' || ch == '/' || ch == '-' || ch == '+') return ch;
    }
    ip[i - 1] = '\0';
    return 0; 
    exit(0);
}

void push(char stack[], int *top, char ch){
    stack[++(*top)] = ch;
    printf("\npush : %c\n", ch);
}

char pop(char stack[], int *top){
    char c = stack[(*top)--];
    printf("\npop : %c\n", c);
    return c;
}

int prec(char ch){
    switch(ch){
    case '*':
    case '/':return 2;
    case '+':
    case '-':return 1;
    case '(':return 0;
    default :return -1;
    }
}

void infixToPostfix(char infix[]){
    char postfix[20], stack[20], stkSym, curSym;
    int top = -1, iptr = -1, pptr = -1;
    
    push(stack, &top, '\0');
    
    while((curSym = infix[++iptr]) != '\0'){
        switch(curSym){
        case '(':
            push(stack, &top, curSym);
            break;
        case ')':
            while((stkSym = pop(stack, &top)) != '(') postfix[++pptr] = stkSym;
            break;
        case '+':
        case '*':
        case '/':
        case '-':
            while(prec(stack[top]) > prec(curSym)) postfix[++pptr] = pop(stack, &top);
            push(stack, &top, curSym);
            break;
        default:
            if(isalnum(curSym) == 0) yyerror();
            postfix[++pptr] = curSym;
        }
    }
    
    while(top != -1) postfix[++pptr] = pop(stack, &top);
    puts(postfix);
}