#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2


sem_t empty;
sem_t full;
sem_t mutex;


typedef struct
{

	int buffer[BUFFER_SIZE];
	int in;
	int out;
} Buffer;

Buffer shared_buffer= { .buffer= {0, .in=0,.out=0}

void *producer(void *arg)
{
	int num_items=(*(int *)arg);
	int item;

	for(int i=0;i<num_items;i++)
	{
		item=i;
		sem_wait(&empty);
		sem_wait(&mutex);
		shared_buffer.buffer[shared_buffer.in]=item;
		printf("Consumer consumed item %d\n",item);
		shared_buffer.out=(shared_buffer.out+1)%BUFFER_SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
		pthread_exit(NULL);
	}

void main()
{
	int num_produce,num_consume;
	printf("Enter the number of items to produce :");
	scanf("%d",&num_produce);
	printf("Enter the number of items to consume : ");
	scanf("%d",&num_consume);

	pthread_t producers[NUM_PRODUCERS];
	pthread_t consumers[NUM_CONSUMERS];

	sem_init(&empty,0,BUFFER_SIZE);
	sem_init(&full,0,0);
	sem_INIT(&mutex,0,0);

	for(int i=0; i<NUM_PRODUCERS;i++)
	{
		pthread_create(&producers[i],NULL,producer,&num_produce);
	}

	for(int i=0; i<NUM_CONSUMERS;i++)
        {
                pthread_create(&consumers[i],NULL,consumer,&num_consume);
        }


	for(int i=0; i<NUM_PRODUCERS;i++)
        {
                pthread_join(producers[i],NULL);
        }

	for(int i=0; i<;i++)
        {
                pthread_join(consumers[i],NULL);
        }

	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);
}
