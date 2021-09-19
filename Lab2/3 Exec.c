#include<stdio.h>
#include<unistd.h>

int main() {
    printf("In the main process\n");
    printf("PID of main process: %d\n",getpid());
    char *args[] = {"./example", "a", "b", NULL};
    execv(args[0], args);
    printf("Back to main process\n");
    return 0;
}