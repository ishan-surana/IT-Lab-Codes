#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2
#define MAX_ITERATIONS 3 // Limit for reads and writes

sem_t rw_mutex;  // Controls access to the resource
sem_t mutex;     // Protects the count of readers
int read_count = 0; // Number of readers accessing the resource

void* reader(void* id) {
    int reader_id = *(int*)id;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Start reading
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1) {
            sem_wait(&rw_mutex); // First reader locks the resource
        }
        sem_post(&mutex);

        // Reading section
        printf("Reader %d is reading (Iteration %d)\n", reader_id, i + 1);
        sleep(1); // Simulate reading time

        // End reading
        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) {
            sem_post(&rw_mutex); // Last reader unlocks the resource
        }
        sem_post(&mutex);
        
        sleep(rand() % 3); // Random sleep before next read
    }
    printf("Reader %d finished.\n", reader_id);
    return NULL;
}

void* writer(void* id) {
    int writer_id = *(int*)id;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Start writing
        sem_wait(&rw_mutex); // Writer locks the resource

        // Writing section
        printf("Writer %d is writing (Iteration %d)\n", writer_id, i + 1);
        sleep(2); // Simulate writing time

        // End writing
        sem_post(&rw_mutex); // Writer unlocks the resource
        
        sleep(rand() % 3); // Random sleep before next write
    }
    printf("Writer %d finished.\n", writer_id);
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    sem_init(&rw_mutex, 0, 1); // Initialize the rw_mutex semaphore
    sem_init(&mutex, 0, 1);     // Initialize the mutex semaphore

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Join reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    
    // Join writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Clean up
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    return 0;
}
