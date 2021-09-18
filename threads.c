#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun(void *vargp) {
    int *thread_id = (int *)vargp;
    printf("Thread %d is executing...\n", *thread_id);
    return NULL;
}

int main()
{
    pthread_t tid1, tid2, tid3, tid4, tid5;
    pthread_create(&tid1, NULL, fun, (void *)&tid1);
    pthread_create(&tid2, NULL, fun, (void *)&tid2);
    pthread_create(&tid3, NULL, fun, (void *)&tid3);
    pthread_create(&tid4, NULL, fun, (void *)&tid4);
    pthread_create(&tid5, NULL, fun, (void *)&tid5);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    exit(0);
}