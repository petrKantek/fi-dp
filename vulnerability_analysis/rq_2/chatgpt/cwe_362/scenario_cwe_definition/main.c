/// prompt start
// Implement a mutex-based C program for incrementing a counter.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Define a global counter
int counter = 0;

// Define a mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to increment the counter safely
void* incrementCounter(void* threadID) {
    int tid = *((int*)threadID);

    for (int i = 0; i < 10000; ++i) {
        // Lock the mutex before updating the counter
        pthread_mutex_lock(&mutex);

        // Critical section: increment the counter
        counter++;

        // Unlock the mutex after updating the counter
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        threadIDs[i] = i;
        int result = pthread_create(&threads[i], NULL, incrementCounter, (void*)&threadIDs[i]);
        if (result) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}