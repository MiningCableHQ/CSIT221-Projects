#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
typedef struct node{
    int data;
    nodeptr next;//Link to the nextnode
}Node;
typedef Node* List;


int main(){
    List head = NULL;
    int i = 1;
    nodeptr ptr = head;
    head = (nodeptr)malloc(sizeof(Node));
    //scanf("%d",&head->data);
    head->data = i;

    ptr = head;
    for(i = 2; i <= 5; i++){
        ptr->next = (nodeptr)malloc(sizeof(Node));
        //scanf("%d",&ptr->next->data);
        ptr->next->data = i;
        ptr = ptr->next;//Lets ptr move to the next node
    }
    ptr->next=NULL;


    ptr = head; //i = 0
    while(ptr != NULL){ //i < SIZE
        printf("%d ",ptr->data);
        ptr = ptr->next; //i++;
    }
    
    return 0;
}