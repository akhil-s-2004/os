#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid < 0)
    {
        printf("Process Creation Failed\n");
        exit(0);
    }
    else if( pid==0 )
    {
        if (execlp("./add","add",NULL) ==  -1)
        {
            printf("Program loading Failed\n");
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Child Process has exited\n");
        exit(0);
    }
    return 0;
}
