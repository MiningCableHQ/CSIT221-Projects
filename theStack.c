#include <stdio.h>
#include <stdlib.h>

typedef int dataItem;
typedef struct node* nodeptr;

typedef struct node{
    dataItem data;
    nodeptr next;
}Stack_Node;

typedef struct{
    int count;
    nodeptr top;    
}Stack_Head;

typedef Stack_Head* Stack;

Stack createStack(){
    Stack s = (Stack)malloc(sizeof(Stack_Head));
    s->count = 0;
    s->top = NULL;
    return s;
}
int isEmpty(Stack s1){
    return s1->top == NULL;
}
void display(Stack s1){
    nodeptr ptr;
    ptr = s1->top;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
nodeptr createNode(int item){
    nodeptr temp = (nodeptr)malloc(sizeof(Stack_Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp->data = item;
    temp->next = NULL;
    return temp;
}
void push(Stack s1, dataItem item){
    nodeptr temp = createNode(item);
    temp->next = s1->top;
    s1->top = temp;
    (s1->count)++;
}
void pop(Stack s1){
    nodeptr temp = s1->top;
    s1->top = temp->next;
    temp->next = NULL;
    free(temp);
    (s1->count)--;
}
Stack dectobin(int dec){
    Stack s1 = createStack();
    int val = dec;
    while(val != 0){
        int rem = val % 2;
        push(s1, val % 2);
        val /= 2;
    }
    return s1;
}
Stack decto(int dec, int base){
    Stack s1=createStack();
    int val = dec;
    while(val != 0){
        int rem = val % base;
        push(s1, rem);
        val /= base;
    }
    return s1;
}

int isValid(char symbols[]){
    Stack s = createStack();
    int i, valid = 1;
    for(i=0; symbols[i] != '\0'; i++){
        char ch = symbols[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(s, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty(s)){
                valid = 0;
                break;
            }
            char topChar = s->top->data;
            if(ch == ')' && topChar == '(' ||
               ch == '}' && topChar == '{' ||
               ch == ']' && topChar == '['){
                pop(s);
            }
            else{
                valid = 0;
                break;
            }
        }
    }
    return valid && isEmpty(s);
}

int isValidOG(char symbols[]){
    Stack s = createStack();
    int i, valid = 1;
    for(i=0; symbols[i] != '\0'; i++){
        if(symbols[i] == '(' || symbols[i] == '{' || symbols[i] == '['){
            push(s, symbols[i]);
        }else if (symbols[i] == ')' || symbols[i] == '}' || symbols[i] == ']'){
            if(isEmpty(s)){
                valid = 0;
                break;
            }else{
                pop(s);
            }
        }
    }
    return valid && isEmpty(s);
}

int main(){
    /*
    Stack s1 = createStack();
    push(s1, 5);
    push(s1, 10);
    push(s1, 15);
    printf("Empty? %d\n", isEmpty(s1));
    display(s1);
    pop(s1);
    display(s1);
    */

    isValid("({[]})") ? printf("Valid\n") : printf("Invalid\n");
    isValid("({[})") ? printf("Valid\n") : printf("Invalid\n");
    return 0;
}