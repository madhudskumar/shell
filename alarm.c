#include<signal.h>
#include"err.h"

void notify(int msg){
	printf("\nsigmail encountered %d\n", msg);
}

void alarmFunc(int dur){
	signal(SIGALRM,notify);
	alarm(dur);
	pause();
}

int main(int argc, char* argv[]){
	alarmFunc(atoi(argv[1]));
	return 0;
}