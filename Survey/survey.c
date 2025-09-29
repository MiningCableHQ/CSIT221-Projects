#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

int SIZE = 10;

typedef int* Statistician;

void display(Statistician answer, int count){
    if(count == 0){
        printf("\n=== Empty Array ===\n");
        return;
    }
    printf("\n");
    for(int i = 0; i < count; i++){
        printf("%d ",answer[i]);
    }
    printf("\n");
}
void add(Statistician answer, int *count, int *SIZE, int item){
    if(item < 1 || item > 9) return;
    
    int i = *count - 1;
    
    if(*count >= *SIZE){
        *SIZE *= 2;
        answer = realloc(answer, sizeof(int)*(*SIZE));
    }
    while (i >= 0 && answer[i] > item){
        answer[i+1] = answer[i];
        i--;
    }
    answer[i+1] = item;
    (*count)++;
}
float mean(Statistician answer, int count){
    if(count == 0) return 0;
    float sum = 0;
    for(int i = 0; i < count; i++){
        sum += answer[i];
    }
    return sum / count;
}
float median(Statistician answer, int count){
    if(count == 0) return 0;
    float result = 0;
    if(count % 2 == 0){
        result = (answer[count/2-1] + answer[count/2]) / 2.0; 
    }else{
        result = answer[count/2];
    }
    return result;
}
int max(Statistician answer, int count){
    if(count == 0) return 0;
    return answer[count-1];
}
int min(Statistician answer, int count){
    if(count == 0) return 0;
    return answer[0];
}
int range(Statistician answer, int count){
    if(count == 0) return 0;
    return max(answer, count) - min(answer, count);
}
void mode(int freq[], int *freqsize, Statistician answer, int count) {
    int i;
    int maxFrequency = 0;
    
    for(i = 0; i <= 9; i++) {
        freq[i] = 0;
    }
    for(i = 0; i < count; i++) {
        int value = answer[i];
        if(value >= 1 && value <= 9) { 
            freq[value]++;
        }
    }
    for(i = 1; i <= 9; i++) {
        if(freq[i] > maxFrequency) {
            maxFrequency = freq[i];
        }
    }
    freq[0] = maxFrequency;
    *freqsize = 0;
    for(i = 1; i <= 9; i++) {
        if(freq[i] == maxFrequency) {
            (*freqsize)++;
        }
    }
}
void histogram(Statistician answer, int count) {
    int freq[10] = {0};
    int i, j;
    
    for(i = 0; i < count; i++) {
        int value = answer[i];
        if(value >= 1 && value <= 9) {
            freq[value]++;
        }
    }
    
    int maxFreq = 0;
    for(i = 1; i <= 9; i++) {
        if(freq[i] > maxFreq) {
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