#include"err.h"

int exe(const char *cmd){
    pid_t pid;
    int status;
    if (cmd == NULL) err("no cmd", -1);
    
    if((pid = fork()) < 0) err("fork err", -2);
    else if(pid == 0){
        system(cmd);
    }else{
        while(waitpid(pid,&status,0) == -1) err("wait err", -3);
    }
    
    return status;
}

int main(int argc, const char * argv[]){
    char cmd[77];
    
    while(1){
        printf("\n # > ");
        gets(cmd);
        if(exe(cmd) < 0) printf("cmd err");
    }
}