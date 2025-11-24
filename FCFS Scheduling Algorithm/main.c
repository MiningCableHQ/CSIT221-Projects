#include <stdio.h>
#include "fcfs.h"

int main(){
    Queue Q = createQueue();
    int numProcesses;
    
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);
    
    printf("\nEntering Burst Time For Process:\n");
    for(int i = 0; i < numProcesses; i++){
        int burstTime;
        printf("P%d: ",i+1);
        scanf("%d",&burstTime);
        enqueue(Q, burstTime, i+1);
    }
    
    calculateFCFS(Q);
    
    return 0;
}