#include<stdio.h>
#include<pthread.h>

int num = 0;
pthread_mutex_t lock;

void* modifyNum() {
    pthread_mutex_lock(&lock);
    num = num + 1;
    printf("%d ", num);
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t tid[2];
    pthread_mutex_init(&lock, NULL);
    pthread_create(&tid[0], NULL, &modifyNum, NULL);
    pthread_create(&tid[1], NULL, &modifyNum, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}
