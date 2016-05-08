#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;
char **e_ptr;

void main(){
	for(e_ptr = environ; *e_ptr; e_ptr++) printf("\n%s\n",*e_ptr);
}
