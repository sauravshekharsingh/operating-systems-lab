#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    // Create child process
    int id = fork();
    printf("Process %d\n", id);
    wait(NULL);
    return 0;
}
