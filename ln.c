#include"err.h"

int main(int argc, char const *argv[]){
	if(argc < 4) err("arg err", -1);

	if(strcmp(argv[1],"-n") == 0)
		if(link(argv[2], argv[3]) == -1) err("link err", -2);
		else printf("\nlink successful\n");
	else if(strcmp(argv[1],"-s") == 0)
		if(symlink(argv[2], argv[3]) == -1) err("syslink err", -3);
		else printf("\nsyslink successful\n"); 
	else printf("\ninvalid argument\n");
		
	return 0;
}
