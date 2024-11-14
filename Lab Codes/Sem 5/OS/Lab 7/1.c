#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#define MAXCAPACITY 100

int buff[MAXCAPACITY], item=0;
sem_t pmutex,cmutex,empty,full;
int in=1, out=1;
void *produce(void *);
void *consume(void *);
void *produce(void *arg)
{
	sem_wait(&empty);
    sem_wait(&pmutex);
    buff[in] = ++item;
    printf("Produced data %d\n",buff[in]);
    in= in % MAXCAPACITY + 1;
    sem_post(&pmutex);
    sem_post(&full);
    return 0;
}

void *consume(void * arg)
{
    sem_wait(&full);
    sem_wait(&cmutex);
    int citem = buff[out];
    printf(" Consumed Data = %d\n",buff[out]);
    out= out % MAXCAPACITY + 1;
    sem_post(&cmutex);
    sem_post(&empty);
   	return 0;
}

int main(int argc, const char * argv[])
{
    sem_init(&pmutex, 0, 1);
    sem_init(&cmutex, 0, 1);
    int i, NumThreads;
    sem_init(&full,0,0);
    sem_init(&empty,0,MAXCAPACITY);

    pthread_t *producers, *consumers;
    NumThreads = abs(atoi(argv[1]));
    producers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);
    consumers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);

    for (i = 0; i < NumThreads; i++)
    {
  	 	pthread_create(&consumers[i], NULL, &consume, NULL);
       	pthread_create(&producers[i], NULL, &produce, NULL);
    }
    for (i = 0; i < NumThreads; i++)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    return 0;
}