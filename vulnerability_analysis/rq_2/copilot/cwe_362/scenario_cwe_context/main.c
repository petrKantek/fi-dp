/// prompt start
// Implement a mutex-based C program for incrementing a counter. Make the program secured with proper synchronization.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

// Shared counter
int counter = 0;

// Mutex for synchronizing access to the counter
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function that each thread will execute
void* increment_counter(void* arg) {
    // Lock the mutex before accessing the counter
    pthread_mutex_lock(&counter_mutex);

    // Increment the counter
    counter++;

    // Unlock the mutex
    pthread_mutex_unlock(&counter_mutex);

    return NULL;
}

int main() {
    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            return 2;
        }
    }

    // Print the final counter value
    printf("Final counter value: %d\n", counter);

    return 0;
}