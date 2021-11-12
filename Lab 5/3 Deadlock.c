#include<stdio.h>

int main() {
    int resources, processes, need;

    printf("Number of processes: ");
    scanf("%d", &processes);
    
    printf("Need of each process: ");
    scanf("%d", &need);

    resources = processes * (need - 1) + 1;

    printf("Minimum number of resources: %d\n", resources);
    
    return 0;
}
