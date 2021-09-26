#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    // File descriptors & fd[0] - read & fd[1] - write
    int fd[2];

    if(pipe(fd) == -1) {
        printf("Error in creating the pipe\n");
        return 1;
    }

    // Create a child process
    int id = fork();
    if(id == -1) {
        printf("Error occured with fork\n");
        return 2;
    }

    if(id == 0) {
        // Reading from the pipe in the child process
        close(fd[0]);
        
        int x = 10;
        if(write(fd[1], &x, sizeof(int)) == -1) {
            printf("Error in writing to the pipe\n");
            return 3;
        }
        
        close(fd[1]);
    } else {
        // Writing to the pipe in the child process
        close(fd[1]);
        
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1) {
            printf("Error in reading from the pipe\n");
            return 4;
        }
        close(fd[0]);

        printf("Data from the child process: %d\n", y);
    }

    wait(NULL);

    return 0;
}
