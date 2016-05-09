#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void check(char *name, int parm){
	#ifdef parm
		printf("\nSS");
	#else
		printf("\nSDS");
	#endif
	printf(" %s",name);
}

void main(){
	check("job ctrl",_POSIX_JOB_CONTROL);
	check("saved ids",_POSIX_SAVED_IDS);
	check("chown rest",_POSIX_CHOWN_RESTRICTED);
	check("posix vd",_POSIX_VDISABLE);
} 
