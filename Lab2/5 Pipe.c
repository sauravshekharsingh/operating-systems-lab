#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#define MSGSIZE 40

int main(int argc, char *argv[]) {
    char inbuf[MSGSIZE];
    int fd[2];

    int id = fork();

    // Create a child process
    if(id == -1) {
        printf("Could not fork process\n");
        return 1;
    }

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Could not create pipe\n");
        return 2;
    }

    if(id > 0) {
        printf("Parent process\n");

        char* msg1 = "This is a message";
        char* msg2 = "This is another message";

        // Write two messages to the pipe in the parent process
        printf("Write message 1\n");
        write(fd[1], msg1, MSGSIZE);
        printf("Write message 2\n");
        write(fd[1], msg2, MSGSIZE);
    } else {
        printf("Child process\n");

        int nbytes;
        // Read the messages from the pipe in the child process
        while((nbytes = read(fd[0], inbuf, MSGSIZE)) > 0) {
            printf("%s\n", inbuf);
        }

        printf("Finished reading\n");
    }

    return 0;
} 
 
