#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "survey.h"

#define SIZE 30

int main(){
    int frequency[10];
    int frequencySize;
    
    StatisticianList answer = NULL;
    
    srand(time(NULL));
    printf("Generating %d random survey responses (1-9):\n", SIZE);
    for(int i = 0; i < SIZE; i++){
        int randomValue = (rand() % 9) + 1;
        add(&answer, randomValue);
        printf("%d ", randomValue);
    }
    printf("\n\n");
    
    printf("RESPONSES: ");
    display(answer);
    
    printf("Mean: %.2f\n", mean(answer));
    printf("Median: %.2f\n", median(answer));
    printf("Max: %d\n", max(answer));
    printf("Min: %d\n", min(answer));
    printf("Range: %d\n", range(answer));
    
    mode(frequency, &frequencySize, answer);
    printf("Mode(s): ");
    int isFirst = 1;
    for(int i = 1; i <= 9; i++){
        if(frequency[i] == frequency[0]){
            if(!isFirst) printf(", ");
            printf("%d", i);
            isFirst = 0;
        }
    }
    printf(" (appearing %d times)\n", frequency[0]);
    histogram(answer);

    return 0;
}