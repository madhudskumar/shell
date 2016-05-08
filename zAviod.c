#include"err.h"

int main(int argc, const char * argv[]){
	pid_t pid;
	
	if((pid = fork()) < 0) err("frk err", -1);
	else if(pid == 0){
		if((pid = fork()) < 0) err("frk err", -2);
		else if(pid == 0){
			sleep(2);
			printf("\nchild process ppid %d\n",getppid());
		}else exit(0);
	}else exit(0);
	
	if(waitpid(pid,NULL,0) != pid) err("wait err", -3);
	return 0;
}