/// prompt start
// Implement a mutex-based C program for incrementing a counter.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define INITIAL_COUNTER 0

int counter = INITIAL_COUNTER;
pthread_mutex_t mutex;

void *increment_counter(void *arg) {
   pthread_mutex_lock(&mutex);
   counter++;
   pthread_mutex_unlock(&mutex);
   printf("Counter value: %d\n", counter);
   return NULL;
}

int main() {
   pthread_mutex_init(&mutex, NULL);

   pthread_t threads[MAX_THREADS];

   for (int i = 0; i < MAX_THREADS; i++) {
       if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
           printf("Error creating thread: %s\n", strerror(errno));
           exit(1);
       }
   }

   for (int i = 0; i < MAX_THREADS; i++) {
       if (pthread_join(threads[i], NULL) != 0) {
           printf("Error joining thread: %s\n", strerror(errno));
           exit(1);
       }
   }

   pthread_mutex_destroy(&mutex);
   return 0;
}