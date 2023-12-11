/// prompt start
// Implement a mutex-based C program for incrementing a counter.
/// prompt end
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000

int counter = 0;
pthread_mutex_t counter_mutex;

void* increment_counter(void* arg) {
    pthread_mutex_lock(&counter_mutex);
    counter++;
    pthread_mutex_unlock(&counter_mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&counter_mutex, NULL);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&counter_mutex);

    printf("Final counter value: %d\n", counter);
    return 0;
}