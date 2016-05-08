#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"err.h"
#include<sys/types.h>

#define BUFF_SIZE 4028

int main(int argc, const char *argv[]){
	int fd;
	char buff[BUFF_SIZE];

	if(argc != 2) err("Arg err", -1);

	if((fd = open(argv[1],O_RDONLY)) == -1) err("open err", -2);
	else
		if(read(fd,buff,BUFF_SIZE) == -1) err("read err", -2);
		else{
			printf("\nread by %d\n", getpid());
			printf("\n%s\n",buff);
			close(fd);
		} 

	printf("\nread process done : %d\n", getpid());

	return 0;
} 
