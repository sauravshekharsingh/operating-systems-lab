#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv) {
    printf("In the exec process\n");
    printf("PID of exec process: %d\n",getpid());
    puts(argv[1]);
    puts(argv[2]);
    return 0;
}
