#include <stdio.h>
#include <stdlib.h>
#include "survey.h"


void display(StatisticianList answer){
    if(answer == NULL){
        printf("Empty List :/");
        return;
    }
    
    Nodeptr ptr = answer;
    
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void add(StatisticianList* answer, int item){
    if(item < 1 || item > 9) return;
    
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    
    if(*answer == NULL || item < (*answer)->data){
        newNode->next = *answer;
        *answer = newNode;
        return;
    }
    
    Nodeptr ptr = *answer;
    while(ptr->next != NULL && ptr->next->data < item){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
float mean(StatisticianList answer){
    if(answer == NULL) return 0;
    
    float sum = 0;
    int count = 0;
    
    Nodeptr ptr = answer;
    while(ptr != NULL){
        sum += ptr->data;
        count++;
        ptr = ptr->next;
    }
    return sum / count;
}
float median(StatisticianList answer){
    if(answer == NULL) return 0;
    
    int count = 0;
    Nodeptr ptr = answer;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    
    ptr = answer;
    if(count % 2 == 1){
        for(int i = 0; i < count/2; i++){
            ptr = ptr->next;
        }
        return ptr->data;
    }else{
        for(int i = 0; i < count/2-1; i++){
            ptr = ptr->next;
        }
        return (ptr->data + ptr->next->data) / 2.0;
    }
}
int max(StatisticianList answer){
    if(answer == NULL) return 0;
    
    Nodeptr ptr = answer;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;

}
int min(StatisticianList answer){
    if(answer == NULL) return 0;
    
    return answer->data;
}
int range(StatisticianList answer){
    if(answer == NULL) return 0;
    
    return max(answer) - min(answer);
}
void mode(int freq[], int* freqsize, StatisticianList answer){
    int i, maxFrequency = 0;
    
    for(i = 0; i <= 9; i++){
        freq[i] = 0;
    }
    
    Nodeptr ptr = answer;
    while(ptr != NULL){
        int value = ptr->data;
        if(value >= 1 && value <= 9){
            freq[value]++;
        }
        ptr = ptr->next;
    }
    
    for(i = 1; i <= 9; i++){
        if(freq[i] > maxFrequency){
            maxFrequency = freq[i];
        }
    }
    
    freq[0] = maxFrequency;
    *freqsize = 0;
    for(i = 1; i <= 9; i++){
        if(freq[i] == maxFrequency){
            (*freqsize)++;
        }
    }
}
void histogram(StatisticianList answer){
    int freq[10] = {0};
    int i, j;
    
    Nodeptr ptr = answer;
    while(ptr != NULL){
        int value = ptr->data;
        if(value >= 1 && value <= 9){
            freq[value]++;
        }
        ptr = ptr->next;
    }
    
    int maxFreq = 0;
    for(i = 1; i <= 9; i++){
        if(freq[i] > maxFreq){
            maxFreq = freq[i];
        }
    }
    
    printf("\nHISTOGRAM:\n");
    printf("Value | Frequency | Graph\n");
    printf("------+-----------+------------------------------------\n");
    for(i = 1; i <= 9; i++) {
        printf("  %d   |    %2d     | ", i, freq[i]);
        for(j = 0; j < freq[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}