#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex, full, empty;
int buffer[5], in = 0, out = 0, data = 0;

void *produce(void *arg)
{
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[in] = ++data;
    printf("Produced data %d\n", buffer[in]);
    in = (in + 1) % 5;
    sem_post(&mutex);
    sem_post(&full);
}

void *consume(void *arg)
{
    sem_wait(&full);
    sem_wait(&mutex);
    int cdata = buffer[out];
    printf("Consumed data %d\n", cdata);
    out = (out + 1) % 5;
    sem_post(&mutex);
    sem_post(&empty);
}

// int main()
// {
//     sem_init(&mutex, 0, 1);
//     sem_init(&full, 0, 0);
//     sem_init(&empty, 0, 5);
//     pthread_t producers[5], consumers[5];
//     for(int i=0;i<5;i++) pthread_create(&producers, NULL, &produce, NULL);
//     for(int i=0;i<5;i++) pthread_create(&consumers, NULL, &consume, NULL);
//     for(int i=0;i<5;i++) pthread_join(producers[i], NULL);
//     for(int i=0;i<5;i++) pthread_join(consumers[i], NULL);
//     return 0;
// }

sem_t mutex, rwmutex;
int rcount = 0;

void *reader(void *arg)
{
    sem_wait(&mutex);
    rcount++;
    if(rcount == 1) sem_wait(&rwmutex);
    printf("Data read by reader %d is %d\n", (int)arg, data);
    rcount--;
    if(rcount == 0) sem_post(&rwmutex);
    sem_post(&mutex);
}

void *writer(void *arg)
{
    sem_wait(&rwmutex);
    data = (int)arg;
    printf("Data written by writer %d is %d\n", (int)arg, data);
    sem_post(&rwmutex);
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&rwmutex, 0, 1);
    pthread_t readers[5], writers[5];
    for(int i=0;i<5;i++) pthread_create(&readers, NULL, &reader, (void *)(i+1));
    for(int i=0;i<5;i++) pthread_create(&writers, NULL, &writer, (void *)(i+1));
    for(int i=0;i<5;i++) {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }
    return 0;
}