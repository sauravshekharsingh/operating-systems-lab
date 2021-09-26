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
        char* msg1 = "This is a message";
        char* msg2 = "This is another message";

        // Write two messages to the pipe in the parent process
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);

    } else {
        // Read the messages from the pipe in the child process
        for (int i = 0; i < 2; i++) {
            printf("%d ", i);
            read(fd[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }

    return 0;
} 
 
