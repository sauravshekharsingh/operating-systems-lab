#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define NUM_PHILOSPHERS 5

sem_t chopsticks[NUM_PHILOSPHERS];

void *routine(void *arg) {
    int i = *(int *)arg;

    while (1) {
        if(i % 2 == 0) {
            sem_wait(&chopsticks[i]);
            printf("Philosopher %d picked %dth chopstick\n", i, i);

            sleep(1);

            sem_wait(&chopsticks[(i + 1) % NUM_PHILOSPHERS]);
            printf("Philosopher %d picked %dth chopstick\n", i, (i + 1) % NUM_PHILOSPHERS);    
        } else {
            sem_wait(&chopsticks[(i + 1) % NUM_PHILOSPHERS]);
            printf("Philosopher %d picked %dth chopstick\n", i, (i + 1) % NUM_PHILOSPHERS);

            sem_wait(&chopsticks[i]);
            printf("Philosopher %d picked %dth chopstick\n", i, i);
        }
        
        sem_post(&chopsticks[i]);
        printf("Philosopher %d kept %dth chopstick\n", i, i);

        sem_post(&chopsticks[(i + 1) % NUM_PHILOSPHERS]);
        printf("Philosopher %d kept %dth chopstick\n", i, (i + 1) % NUM_PHILOSPHERS);
    }

    free(arg);
}

int main() {
    pthread_t th[NUM_PHILOSPHERS];

    for(int i = 0; i < NUM_PHILOSPHERS; i++) {
        sem_init(&chopsticks[i], 0, 1);

        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, routine, a) != 0) {
            return 1;
        }
    }

    for(int i = 0; i < NUM_PHILOSPHERS; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            return 2;
        }

        sem_destroy(&chopsticks[i]);
    }

    return 0;
}
