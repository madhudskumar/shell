#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"err.h"

#define BUFF_SIZE 4028

int main(int argc, const char *argv[]){
	int fd;
	char buffer[BUFF_SIZE];

	if(argc != 2) err("arg err", -12);	

	if((fd = open(argv[1], O_WRONLY)) == -1) err("open err", -1);
	
	if(mkfifo(argv[1], S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO) != -1){
		printf("file created : %d", getpid());
	}

	printf("\nwrite some data \n : \n");
	gets(buffer);

	if(write(fd,buffer,BUFF_SIZE) == -1) err("Write error", -4);

	else{
		printf("\nwrite job done : %d\n", getpid());
		close(fd);
	}

	return 0;
} 
