#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=5,x=0;
void Producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("The producer produces %d",x);
    ++mutex;
}
void Consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes %d",x);
    x--;
    ++mutex;
}
void main()
{
    int n,i;
    printf("PRODUCER---CONSUMER\n");
    printf("1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    for(i=1;i>0;i++)
    {
        printf("Enter your choice: ");
        scanf("%d",&n);
    
    switch(n)
    {
        case 1: if((mutex==1) && (empty!=0))
                {
                    Producer();
                }
                else
                {
                    printf("Buffer full!!!!");
                }
                break;
        case 2: if((mutex==1)& (full!=0))
                {
                    Consumer();
                }
                else
                {
                    printf("Buffer empty!!");
                }
                break;
        case 3: exit(0);
                break;
    };
    }
    
}
