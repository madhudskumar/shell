#include<signal.h>
#include"err.h"

void notify(int msg){
	printf("\nsigmail encountered %d\n", msg);
}

int main(int argc, char* argv[]){
	signal(SIGALRM,notify);
	alarm(atoi(argv[1]));
	pause();
	return 0;
}