typedef struct node* nodeptr;
typedef struct node{
    int burstTime;
    int processId;
    nodeptr next;
}Queue_Node;

typedef struct{
    int count;
    nodeptr front;
    nodeptr rear;
}Queue_Head;
typedef Queue_Head* Queue;

Queue createQueue();
int isEmpty(Queue Q);
nodeptr createNode(int burstTime, int processId);
void enqueue(Queue Q, int burstTime, int processId);
int dequeue(Queue Q);
void display(Queue Q);

// FCFS scheduling fucntions
void calculateFCFS(Queue Q);
void displayResults(int burstTime[], int waitingTimes[], int turnaroundTimes[], int processCount);