#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"err.h"

void printChar(const char *str){
	const char *c;
	setbuf(stdout, NULL);
	for(c = str; *c != '\0'; c++) putc(*c, stdout);
}

int main(){
	pid_t pid;
	
	if((pid = fork()) == -1) err("fork err", -1);
	else if(pid == 0) printChar("\nthis is parent\n");
	else printChar("\nThis is child\n");
	
	return 0;
		
}		
