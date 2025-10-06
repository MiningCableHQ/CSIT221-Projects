#include "bitsetlist.h"
#include <stdio.h>
#include <stdlib.h>

BitSet initialize() {
    return NULL;
}

BitSet add(int elem, BitSet s){
    Nodeptr newNode, current, previous;
    
    newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = NULL;

    if(s == NULL || elem < s->data){
        newNode->next = s;
        return newNode;
    }
    
    if(elem == s->data){
        free(newNode);
        return s;
    }
    
    current = s;
    while(current != NULL && current->data < elem){
        previous = current;
        current = current->next;
    }
    
    if(current != NULL && current->data == elem){
        free(newNode);
        return s;
    }
    
    newNode->next = current;
    previous->next = newNode;
    
    return s;
}

void display(BitSet s){
    Nodeptr current = s;
    
    printf("{");
    while(current != NULL){
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

BitSet getUnion(BitSet s1, BitSet s2){
    BitSet result = initialize();
    Nodeptr p1 = s1, p2 = s2;
    Nodeptr tail = NULL;
    
    while(p1 != NULL && p2 != NULL){
        Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
        
        if(p1->data < p2->data){
            newNode->data = p1->data;
            p1 = p1->next;
        }else if (p1->data > p2->data){
            newNode->data = p2->data;
            p2 = p2->next;
        }else{
            newNode->data = p1->data;
            p1 = p1->next;
            p2 = p2->next;
        }
    
        newNode->next = NULL;
        
        if(result == NULL){
            result = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    while(p1 != NULL){
        Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
        newNode->data = p1->data;
        newNode->next = NULL;
        
        if(result == NULL){
            result = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        p1 = p1->next;
    }
    
    while(p2 != NULL){
        Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
        newNode->data = p2->data;
        newNode->next = NULL;
        
        if(result == NULL){
            result = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        p2 = p2->next;
    }
    return result;
}

BitSet intersection(BitSet s1, BitSet s2){
    BitSet result = initialize();
    Nodeptr p1 = s1, p2 = s2;
    Nodeptr tail = NULL;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            p1 = p1->next;
        }else if (p1->data > p2->data){
            p2 = p2->next;
        }else{
            Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
            newNode->data = p1->data;
            newNode->next = NULL;
            
            if(result == NULL){
                result = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return result;
}

BitSet difference(BitSet result, BitSet s1, BitSet s2){
    Nodeptr current = result;
    while(current != NULL){
        Nodeptr temp = current;
        current = current->next;
        free(temp);
    }
    result = initialize();
    
    Nodeptr p1 = s1, p2 = s2;
    Nodeptr tail = NULL;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
            newNode->data = p1->data;
            newNode->next = NULL;
            
            if(result == NULL){
                result = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            p1 = p1->next;
        }else if(p1->data > p2->data){
            p2 = p2->next;
        }else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    while(p1 != NULL){
        Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
        newNode->data = p1->data;
        newNode->next = NULL;
        
        if(result == NULL){
            result = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        p1 = p1->next;
    }
    
    return result;
}

int isEmpty(BitSet s){
    return (s == NULL);
}

int contains(BitSet s, int elem){
    Nodeptr current = s;
    
    while(current != NULL){
        if(current->data == elem){
            return 1;
        }
        if(current->data > elem){
            break;
        }
        current = current->next;
    }
    
    return 0;
}

int disjoint(BitSet s1, BitSet s2){
    BitSet inter = intersection(s1, s2);
    int result = isEmpty(inter);
    
    Nodeptr current = inter;
    while(current != NULL){
        Nodeptr temp = current;
        current = current->next;
        free(temp);
    }
    
    return result;
}

int equal(BitSet s1, BitSet s2){
    Nodeptr p1 = s1, p2 = s2;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->data != p2->data){
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return (p1 == NULL && p2 == NULL);
}

int cardinality(BitSet s){
    int count = 0;
    Nodeptr current = s;
    
    while(current != NULL){
        count++;
        current = current->next;
    }
    
    return count;
}

int subset(BitSet s1, BitSet s2){
    Nodeptr p1 = s1, p2 = s2;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            return 0;
        }else if (p1->data > p2->data){
            p2 = p2->next;
        }else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return (p1 == NULL);
}