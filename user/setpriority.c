#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,char** argv)
{
    if(argc<3)
    printf("Invalid number of arguments\n");

    int priority=atoi(argv[1]);
    int pid=atoi(argv[2]);
    
    set_priority(priority,pid);
    
    exit(0);
}