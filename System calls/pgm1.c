include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if (pid < 0)
    {
        printf("Child Process Creation Failed\n");
        exit(0);
    }
    else if(pid == 0)
    {
        printf("Inside Child Process\n");
        printf("Child Process ID : %d\n",getpid());
        printf("Parent Process ID : %d\n",getppid());
        exit(0);
    }
    else
    {
        printf("Inside Parent Process\n");
        printf("Child Process ID : %d\n",pid);
        printf("Parent Process ID : %d\n",getpid());
        wait(NULL);
        exit(0);
    }
    return 0;
}
