#define _GNU_SOURCE
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

#define NUM_THREADS 2

pthread_mutex_t mutex;

void *routine() {
    // Lock mutex
    pthread_mutex_lock(&mutex);

    // pid_t tid = gettid();
    printf("Thread: %d", gettid());

    // Unlock mutex
    // pthread_mutex_unlock(&mutex);
}

int main() {
    // Create thread variable
    pthread_t th[NUM_THREADS];

    // Initialize thread mutex
    pthread_mutex_init(&mutex, NULL);

    // Create thread instance
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&th[i], NULL, routine, NULL) != 0) {
            return 1;
        }
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        // Wait for thread to finish execution
        if(pthread_join(th[i], NULL) != 0) {
            return 2;
        }
    }
    
    return 0;
}
