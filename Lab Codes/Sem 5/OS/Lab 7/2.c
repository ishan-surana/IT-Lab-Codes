#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#define READERS 5
#define WRITERS 4

sem_t rwmutex, mutex;
int readcount = 0, resource = 0;
void *reader(void *arg);
void *writer(void *arg);

void *reader(void *arg)
{
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) sem_wait(&rwmutex);
    printf("Reader %d is reading value of resource as %d\n", (int)arg, resource);
    readcount--;
    if (readcount == 0) sem_post(&rwmutex);
    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg)
{
    sem_wait(&rwmutex);
    resource = (int)arg;
    printf("Writer %d is writing value of resource as %d\n", (int)arg, resource);
    sem_post(&rwmutex);
    return NULL;
}

int main(int argc, const char *argv[])
{
    sem_init(&rwmutex, 0, 1);
    sem_init(&mutex, 0, 1);
    pthread_t rthreads[READERS], wthreads[WRITERS];
    int i, j;
    for (i = 0, j = 0; i < READERS && j < WRITERS; i++, j++)
    {
        pthread_create(&rthreads[i], NULL, reader, (i + 1));
        pthread_create(&wthreads[j], NULL, writer, (j + 1));
    }
    for (i = 0; i < READERS; i++) pthread_join(rthreads[i], NULL);
    for (i = 0; i < WRITERS; i++) pthread_join(wthreads[i], NULL);
    return 0;
}
