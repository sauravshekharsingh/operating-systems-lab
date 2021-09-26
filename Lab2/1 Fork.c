#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    // Create child process
    int id = fork();
    
    printf("Process %d\n", id);

    // Wait for the child process to finish
    wait(NULL);
    return 0;
}
