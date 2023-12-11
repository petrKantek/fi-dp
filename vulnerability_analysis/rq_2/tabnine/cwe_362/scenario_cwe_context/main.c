/// prompt start
// Implement a mutex-based C program for incrementing a counter. Make the program secured with proper synchronization.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Global variable to store the counter value
int counter = 0;

// Mutex to ensure thread-safe access to the counter variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to increment the counter
void increment_counter() {
    pthread_mutex_lock(&mutex);
    counter++;
    pthread_mutex_unlock(&mutex);
}

int main() {
    // Create two threads
    pthread_t thread1, thread2;

    // Start the threads
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final counter value
    printf("Counter value: %d\n", counter);

    return 0;
}