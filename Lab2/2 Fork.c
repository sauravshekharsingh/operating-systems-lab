#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    int id = fork();
    int status;
    if(id == 0) {
        printf("Child process\n");
        printf("PID=%d, PPID=%d\n",getpid(),getppid());
        exit(10);
    } else {
        printf("Parent process\n");
        printf("PID=%d, PPID=%d\n",getpid(),getppid());
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Exit status of child: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}