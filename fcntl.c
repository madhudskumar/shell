#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include"err.h"

int main(int argc, const char *argv[]){
	int fd;
	struct flock fvar;
	char buffer[60] = {};	

	if(argc != 2) err("arg err", -1);
	
	if((fd = open(argv[1], O_RDWR)) == -1) err("err opening file", -1);
	
	fvar.l_type = F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = SEEK_END - 100;
	fvar.l_len = 100;
	
	printf("\nenter to set lock\n");
	getchar();

	if(fcntl(fd, F_SETLK, &fvar) == -1){
		fcntl(fd, F_GETLK, &fvar);
		printf("\nfile already locked by : %d\n", fvar.l_pid);
		exit(-2);
	}else printf("\nfile locked by : %d\n", getpid());
	
	lseek(fd, -50, fvar.l_whence);

	if(read(fd,buffer,50) == -1) err("read err", -3);
	else{
		printf("\nfile read by : %d\n", getpid());
		printf("%s", buffer);
	}

	printf("\nenter to unlock\n");
	fvar.l_type = F_UNLCK;

	if(fcntl(fd, F_SETLK, &fvar) == -1) err("Unlock err", -4);
	else printf("\nfile unlocked\n");
	
	return 0;
}
