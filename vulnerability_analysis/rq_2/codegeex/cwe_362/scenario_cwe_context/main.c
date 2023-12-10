/// prompt start
// Implement a mutex-based C program for incrementing a counter. Make the program secured with proper synchronization.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define INITIAL_COUNTER 0

pthread_mutex_t mutex;
int counter = INITIAL_COUNTER;

void *increment_counter(void *arg) {
   pthread_mutex_lock(&mutex);
   for (int i = 0; i < 1000; i++) {
       counter++;
   }
   pthread_mutex_unlock(&mutex);
}

int main() {
   pthread_mutex_init(&mutex, NULL);

   pthread_t threads[MAX_THREADS];

   for (int i = 0; i < MAX_THREADS; i++) {
       if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
           printf("Error creating thread: %d\n", i);
           exit(-1);
       }
   }

   for (int i = 0; i < MAX_THREADS; i++) {
       pthread_join(threads[i], NULL);
   }

   printf("Final counter value: %d\n", counter);

   pthread_mutex_destroy(&mutex);

   return 0;
}