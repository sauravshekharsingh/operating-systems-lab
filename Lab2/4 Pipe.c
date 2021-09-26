#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 16

int main(int argc, char *argv[]) {
    char inbuf[MSGSIZE];
    int fd[2];

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Could not create pipe\n");
        return 1;
    }

    char* msg1 = "hello, world #1";
    char* msg2 = "hello, world #2";

    // Write two messages to the pipe
    write(fd[1], msg1, MSGSIZE);
    write(fd[1], msg2, MSGSIZE);

    // Read the messages from the pipe
    for (int i = 0; i < 2; i++) {
        read(fd[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
    }

    return 0;
} 
 
