#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#define MSGSIZE 40

int main(int argc, char *argv[]) {
    // Create a child process
    int id = fork();
    if(id == -1) {
        printf("Could not fork process\n");
        return 1;
    }

    if(id > 0) {
        int a, b;
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        printf("Sum: %d", a + b);
    } else {
        int t;
        printf("Enter time to sleep: ");
        scanf("%d", &t);
        sleep(t);
    }
    
    wait(NULL);

    return 0;
} 
