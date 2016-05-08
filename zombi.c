#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"err.h"

int main(int argc, const char *argv[]){
	pid_t pid;
	
	if((pid = fork()) < 0) err("frk err", -1);
	else if(pid == 0){
		printf("\nChild process : %d\n", getpid());
		sleep(2);
	}else{
		printf("\nparent process : %d\n", getppid());
		exit(0);
	}
	
	system("ps -ao pid,ppid,s,comm");
	return 0;
}