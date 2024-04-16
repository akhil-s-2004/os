#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX 100

int s=1;
int turn=0;

void wait(int* arg)
{
    while(s<=0 || turn!=*arg);
    s--;
}

void signal()
{
    s++;
    turn=1-turn;
}

void *print_numbers(void *arg)
{
    int *type = (int *)arg;
    int i;
    int start = (*type == 0 ? 0 : 1);
    for(i = start; i <= MAX; i += 2) {
        wait(arg);
        sleep(1);
        if (*type == 0)
            printf("Even Number: %d\n", i);
        else
            printf("Odd Number: %d\n", i);
        signal();
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t et,ot;
    int even_arg=0;
    int odd_arg=1;
    pthread_create(&et,NULL,print_numbers,(void *)&even_arg);
    pthread_create(&ot,NULL,print_numbers,(void *)&odd_arg);
    pthread_join(et,NULL);
    pthread_join(ot,NULL);
    return 0;
}
