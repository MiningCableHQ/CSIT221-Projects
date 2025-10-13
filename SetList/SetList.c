#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
typedef struct node{
    int data;
    nodeptr next;
}Node;
typedef Node* Set;

Set initialize(){
    return NULL;
}
void display(Set s){
    nodeptr ptr = s;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
Set add(Set s, int elem){
    nodeptr temp = (nodeptr)malloc(sizeof(Node));
    temp->data = elem;
    temp->next = NULL;
    
    if(s == NULL){
        return temp;
    }
    
    nodeptr ptr = s;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    
    ptr->next = temp;
    return s;
}
int contains(Set s, int elem){
    nodeptr ptr = s;
    while(ptr != NULL){
        if(ptr-> data == elem){
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}
Set getUnion(Set s1, Set s2){
    Set s = initialize();
    nodeptr ptr;
    
    ptr = s1; 
    while(ptr != NULL){
        if(!contains(s, ptr->data)){
            s = add(s, ptr->data);
        }
        ptr = ptr->next;
    }
    
    ptr = s2; 
    while(ptr != NULL){
        if(!contains(s, ptr->data)){
            s = add(s, ptr->data);
        }
        ptr = ptr->next;
    }
    return s;
}
Set intersection(Set s1, Set s2){
    Set s = initialize();
    nodeptr ptr;
    
    ptr = s1;
    while(ptr != NULL){
        if(contains(s2, ptr->data)){
            if(!contains(s, ptr->data)){
                s = add(s, ptr->data);
            }
        }
        ptr = ptr->next;
    }
    
    ptr = s2;
    while(ptr != NULL){
        if(contains(s1, ptr->data)){
            if(!contains(s, ptr->data)){
                s = add(s, ptr->data);
            }
        }
        ptr = ptr->next;
    }
    return s;
}
Set difference(Set s1, Set s2){
    Set s = initialize();
    nodeptr ptr = s1;
    
    while(ptr != NULL){
        if(!contains(s2, ptr->data)){
            if(!contains(s, ptr->data)){
                s = add(s, ptr->data);
            }
        }
        ptr = ptr->next;
    }
    return s;
}
Set symmetricdifference(Set s1, Set s2){
    Set sUnion = getUnion(s1, s2);
    Set sIntersection = intersection(s1, s2);
    Set s = difference(sUnion, sIntersection);
    
    return s;
}
int subset(Set s1, Set s2){
    nodeptr ptr = s1;
    while(ptr != NULL){
        if(!contains(s2, ptr->data)){
            return 0;
        }
        ptr = ptr->next;
    }
    return 1;
}
int disjoint(Set s1, Set s2){
    nodeptr ptr = s1;
    while(ptr != NULL){
        if(contains(s2, ptr->data)){
            return 0;
        }
        ptr = ptr->next;
    }
    return 1;
}
int equal(Set s1, Set s2){
    return subset(s1, s2) && subset(s2, s1);
}
void printLines(){
    printf("------------------------------------------------------\n");
}

int main(){
    Set s1 = initialize();
    Set s2 = initialize();
    Set s3 = initialize();
    int size1, size2;
    
    printf("Enter size of Set 1: ");
    scanf("%d",&size1);
    printf("Enter size of Set 2: ");
    scanf("%d",&size2);
    
    printf("Enter %d numbers in the Set 1: ",size1);
    for(int i = 1; i <= size1; i++){
        int input;
        scanf("%d",&input);
        s1 = add(s1, input);
        
    }
    printf("Enter %d numbers in the Set 2: ",size2);
    for(int i = 1; i <= size2; i++){
        int input;
        scanf("%d",&input);
        s2 = add(s2, input);
        
    }
    
    printLines();
    printf("\t\tOutput Display\n");
    printf("Set 1: ");
    display(s1);
    printf("Set 2: ");
    display(s2);
    printLines();
    
    s3 = getUnion(s1, s2);
    printf("Union Set: ");
    display(s3);
    
    s3 = intersection(s1, s2);
    printf("Intersection Set: ");
    display(s3);
    
    s3 = difference(s1, s2);
    printf("Difference Set: ");
    display(s3);
    
    s3 = symmetricdifference(s1, s2);
    printf("Symmetric Difference Set: ");
    display(s3);
    
    printLines();
    printf("Is Set 1 subset of Set 2?: %s",subset(s1, s2) ? "Yes\n" : "No\n");
    printf("Is Set 1 and Set 2 a disjoint?: %s",disjoint(s1, s2) ? "Yes\n" : "No\n");
    printf("Is Set 1 and Set 2 equal?: %s",equal(s1, s2) ? "Yes\n" : "No\n");
    printLines();
    
    free(s1);
    free(s2);
    free(s3);

    return 0;
}