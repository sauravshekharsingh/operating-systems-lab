#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#define MSGSIZE 40

int main(int argc, char *argv[]) {
    char readmessage[MSGSIZE];
    int fd[2];

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Could not create pipe\n");
        return 2;
    }

    // Create a child process
    int id = fork();
    if(id == -1) {
        printf("Could not fork process\n");
        return 1;
    }

    if(id > 0) {
        char* msg1 = "This is a message";
        char* msg2 = "This is another message";

        // Write two messages to the pipe in the parent process
        printf("Write message 1: %s\n", msg1);
        write(fd[1], msg1, MSGSIZE);
        
        printf("Write message 2: %s\n", msg2);
        write(fd[1], msg2, MSGSIZE);
    } else {
        int nbytes;
        
        // Read the messages from the pipe in the child process
        while((nbytes = read(fd[0], readmessage, MSGSIZE)) > 0) {
            printf("Read message: %s\n", readmessage);
        }
    }

    return 0;
} 
