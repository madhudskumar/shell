/*
 * TODO : parse "if E then S" and "if E then S else S"
 */

#include"err.h"

int ln = 0, cur = 0, i, j;
char ip[100], stmt[3][100];

void gen(){
    int l1 = 101, l2 = 102, l3 = 103;
    printf("\nIF %s GOTO %d\n", stmt[0], l1);
    printf("\n %d\n", l3);
    printf("\n%d : %s\n",l1,stmt[1]);
    
    if(cur < 3) printf("\n%d : STOP\n", l3);
    else{
        printf("\n%d :ELSE %s\n", l2, stmt[2]);
        printf("\n%d : STOP\n", l3);
    }
    //or something like 
}

int main(){
    int index = 0;
    printf("\nEnter the stmt\n");
      gets(ip);
      
    ln = strlen(ip);
    
    for (i = 0; i < ln && ip[i] != ';'; i++)
    {
        if(ip[i] == '('){
            for(j = i+1; ip[j] != ')'; j++) stmt[cur][index++] = ip[j];
            index = 0;
            cur++;
            i = j; 
        }
    }
    
    gen();
    return 0;
}