#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

struct message
{
    int flag;
    int turn;
    int user1_up;
    int user2_up;
    char msg[SIZE];
};
struct message* mptr;

int main()
{
    int fd;
    fd=shm_open("Akhi", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    if(ftruncate(fd, SIZE) == -1)
    {
        perror("ftruncate");
        exit(1);
    }

    mptr=mmap(mptr, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
    if(mptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    mptr->flag=1;
    mptr->turn=1;
    while(mptr->flag == 1)
    {
        while(mptr->turn != 1);
        if(mptr->user2_up == 1)
        {
            printf("Message from USER2 : %s\n",mptr->msg);
            mptr->user2_up=0;
        }
        if(mptr->user1_up == 0 && mptr->user2_up!=1)
        {
            printf("Enter the message (USER1) : ");
            scanf(" %[^\n]",mptr->msg);
            if(strcmp(mptr->msg,"stop") == 0)
            {
                mptr->flag=0;
            }
            mptr->user1_up=1;
        }
        mptr->turn=2;
    }
    if(munmap(mptr, SIZE) == -1)
    {
        perror("munmap");
        exit(1);
    }
    close(fd);
    if(shm_unlink("Akhi") == -1)
    {
        perror("shm_unlink");
        exit(1);
    }
    return 0;
}
