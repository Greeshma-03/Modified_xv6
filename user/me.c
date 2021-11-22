#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"


int main(int argc,char** argv)
{
    // char buffer[20]="\0";
    // int fd=open(argv[0],O_RDWR);
    // printf("File descriptor: %d\n",fd);
    // printf("%s\n",argv[1]);
    
    // int num=read(fd,buffer,15);
    // printf("New buffer value is %s and no. is %d\n",buffer,num);

    // printf("Helloo!!This is me :)\n");
    char* new_args[20];
    for(int i=2;i<argc;i++)
    {
    printf("Argument i is %d- %s\n",i,argv[i]);
    strcpy(new_args[i-2],argv[i]);
    }
    
    exec(new_args[0],new_args);
    exit(0);
}