#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[]){
	if(argc < 3){
		printf("\nWrong usage\n");
		exit(-2);
	}

	if(link(argv[1], argv[2]) == -1){
		printf("\nError\n");
		exit(-1);
	}else{
		printf("\nn successful\n");
	}

	return 0;
}
