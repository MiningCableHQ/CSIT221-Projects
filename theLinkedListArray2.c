#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
typedef struct node{
    int data;
    nodeptr next;//Link to the nextnode
}Node;
typedef Node* List;

List createList(){
    List head;
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
    return head;
}
nodeptr createNode(int item){
    nodeptr temp = (nodeptr)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
}
List addFront(List head, int item){
    nodeptr temp = createNode(item);
    temp->next = head;
    head = temp;
    return head;
}
List addEnd(List head, int item){
    nodeptr temp = createNode(item);
    nodeptr ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}
List addAt(List head, int item, int pos){
    nodeptr temp = createNode(item);
    nodeptr ptr = head;
    int i = 1;
    if (pos == 1) {
        temp->next = head;
        head = temp;
    }else{
        while (i < pos - 1){
            ptr = ptr->next;
            i++;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}
List deleteFront(List head){
    if(head == NULL){
        return NULL;
    }
    nodeptr temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);

    return head;
}
List deleteEnd(List head){
    nodeptr temp;
    nodeptr ptr = head;

    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);

    return head;
}
List deleteAt(List head, int pos){
    if(head == NULL){
        return NULL;
    }
    
    nodeptr temp;
    nodeptr ptr = head;
    
    int i = 1;
    if (pos == 1) {
        temp = head;
        head = temp->next;
    }else{
        while (i < pos - 1){
            ptr = ptr->next;
            i++;
        }
        temp = ptr->next;
        ptr->next = temp->next;
    }
    temp->next = NULL;
    free(temp);
    return head;
}
void displayList(List head){
    nodeptr ptr = head; //i = 0
    while(ptr != NULL){ //i < SIZE
        printf("%d ",ptr->data);
        ptr = ptr->next; //i++;
    }
    printf("\n");
}
int computeSum(List head){
    int sum = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}
int count(List head){
    int ctr = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        ctr++;
        ptr = ptr->next;
    }
    return ctr;
}
int countPos(List head){
    int ctr = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data > 0){
            ctr++;
        }
        ptr = ptr->next;
    }
    return ctr;
}   
int countNeg(List head){
    int ctr = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data < 0){
            ctr++;
        }
        ptr = ptr->next;
    }
    return ctr;
}
int countEven(List head){
    int ctr = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data % 2 == 0){
            ctr++;
        }
        ptr = ptr->next;
    }
    return ctr;
}
int countOdd(List head){
    int ctr = 0;
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data % 2 != 0){
            ctr++;
        }
        ptr = ptr->next;
    }
    return ctr;
}
int findItem(List head, int item){
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data == item){
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}
int findMax(List head){
    nodeptr ptr = head;
    int max = ptr->data;
    ptr = ptr->next;
    while(ptr != NULL){
        if(ptr->data > max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}
int findMin(List head){
    nodeptr ptr = head;
    int min = ptr->data;
    ptr = ptr->next;
    while(ptr != NULL){
        if(ptr->data < min){
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    return min;
}

int main(){
    List head = NULL;
    head = createList();
    int item = 5;

    head = addAt(head, 5, 3);
    displayList(head);
    head = deleteFront(head);
    displayList(head);
    head = deleteEnd(head);
    displayList(head);
    head = deleteAt(head, 2);
    displayList(head);

    return 0;
}