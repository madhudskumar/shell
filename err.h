#pragma once

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#ifdef err
#undef err
#endif

void err(char *e_msg, int e_no){
	printf("\n%s\n", e_msg);
	exit(e_no);
}
