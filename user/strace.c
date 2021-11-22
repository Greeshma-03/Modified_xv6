#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stddef.h>

int main(int argc,char** argv)
{        
    int pid=fork();
    if(pid<0){
        printf("Fork failed!!\n");
    }
    else if(pid==0)
    {        
    trace(atoi(argv[1]));
    if(exec(argv[2],argv+2)<0)
    printf("my eror in exec\n");
    }
    else
    {
        int status;
        wait(&status);
    } 
    exit(0);
}