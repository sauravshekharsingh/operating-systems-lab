#include<stdio.h>
#include<unistd.h>
int main() {
    int val = fork();
    printf("Process %d\n", val);
    return 0;
}