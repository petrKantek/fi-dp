/// prompt start
// Implement a mutex-based C program for incrementing a counter.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t sem;

void *thread_function(void *arg)
{
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&sem);
        printf("Thread %d: Counter = %d\n", *((int *) arg), counter);
        counter++;
        sem_post(&sem);
    }
}

int main()
{
    pthread_t thread;
    int i;

    sem_init(&sem, 0, 0);

    int thread_id = 1;
    pthread_create(&thread, NULL, thread_function, &thread_id);

    for (i = 0; i < 10; i++) {
        sem_wait(&sem);
        printf("Main thread: Counter = %d\n", counter);
        counter++;
        sem_post(&sem);
    }

    pthread_join(thread, NULL);

    sem_destroy(&sem);

    return 0;
}