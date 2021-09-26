#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    // Create child process
    int id = fork();
    int status;

    if(id == -1) {
        printf("Error occured with fork\n");\
        return 1;
    }

    if(id == 0) {
        printf("Child process\n");
        printf("PID=%d, PPID=%d\n",getpid(),getppid());
        
        exit(10);
    } else {
        printf("Parent process\n");
        printf("PID=%d, PPID=%d\n",getpid(),getppid());
        
        // Wait for child process
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Exit status of child: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
