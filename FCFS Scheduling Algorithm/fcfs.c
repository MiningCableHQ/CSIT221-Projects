#include <stdio.h>
#include <stdlib.h>
#include "fcfs.h"

Queue createQueue(){
    Queue Q = (Queue)malloc(sizeof(Queue_Head));
    Q->count = 0;
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}
int isEmpty(Queue Q){
    return Q->count == 0;
}
nodeptr createNode(int burstTime, int processId){
    nodeptr temp = (nodeptr)malloc(sizeof(Queue_Node));
    temp->burstTime = burstTime;
    temp->processId = processId;
    temp->next = NULL;
    return temp;
}
void enqueue(Queue Q, int burstTime, int processId){
    nodeptr temp = createNode(burstTime, processId);
    if(isEmpty(Q)){
        Q->front = temp;
    }else{
        Q->rear->next = temp;
    }
    Q->rear = temp;
    (Q->count)++;
}
int dequeue(Queue Q){
    nodeptr temp = Q->front;
    int burstTime = temp->burstTime;
    
    if(Q->count == 1){
        Q->front = NULL;
        Q->rear = NULL;
    }else{
        Q->front = temp->next;
        temp->next = NULL;
    }
    free(temp);
    (Q->count)--;
    
    return burstTime;
}
void display(Queue Q){
    nodeptr ptr = Q->front;
    printf("\nProcess\tBurst Time\n");
    while(ptr != NULL){
        printf("P%d\t%dms\n", ptr->processId, ptr->burstTime);
        ptr = ptr->next;
    }
}

// FCFS scheduling functions
void calculateFCFS(Queue Q){
    int burstTime[100];
    int currentTime = 0;
    int waitingTime[100];
    int turnaroundTime[100];
    int processCount = Q->count;
    
    for(int i = 0; !isEmpty(Q); i++){
        burstTime[i] = dequeue(Q);
        waitingTime[i] = currentTime;
        currentTime += burstTime[i];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }
    
    displayResults(burstTime, waitingTime, turnaroundTime, processCount);
}
void displayResults(int burstTime[], int waitingTimes[], int turnaroundTimes[], int processCount){
    int totalWaitingTimes = 0;
    int totalTurnAroundTimes = 0;
    
    for(int i = 0; i < processCount; i++){
        totalWaitingTimes += waitingTimes[i];
        totalTurnAroundTimes += turnaroundTimes[i];
    }
    
    double averageWaitingTime = (double) totalWaitingTimes / processCount;
    double averageTurnAroundTime = (double) totalTurnAroundTimes / processCount;
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------\t----------\t------------\t---------------\n");
    for(int i = 0; i < processCount; i++){
        printf("P%d\t%d ms\t\t%d ms\t\t%d ms\n", i+1, burstTime[i], waitingTimes[i], turnaroundTimes[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f ms\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f ms\n", averageTurnAroundTime);
}