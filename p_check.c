#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int res;

void checkSys(char *name,int parm){
	printf("\n%s",name);
	if((res = sysconf(parm)) == -1) printf("\nSDS : %d\n",parm);
	else printf("\nres:%d ;; %d\n",res,parm);
}

void checkPath(char *name,int parm){
	printf("\n%s",name);
	if((res = pathconf("/", parm)) == -1) printf("\nSDS: %d\n",parm);
	else printf("\nres:%d ;; %d\n",res,parm);
}

void main(){
	checkSys("clock TCK",_SC_CLK_TCK);  
	checkSys("child process",_SC_CHILD_MAX);  
	checkSys("max open",_SC_OPEN_MAX);  

	checkPath("max path",_PC_PATH_MAX);  
	checkPath("max name",_PC_NAME_MAX);  
}
