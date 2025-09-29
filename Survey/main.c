#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

int main(){
    int count = 0;
    int frequency[10];
    int frequencySize;
    
    Statistician answer = (int*)malloc(sizeof(int)*SIZE);
    
    add(answer, &count, &SIZE, 1);
    add(answer, &count, &SIZE, 2);
    add(answer, &count, &SIZE, 3);
    add(answer, &count, &SIZE, 4);
    add(answer, &count, &SIZE, 5);
    add(answer, &count, &SIZE, 6);
    add(answer, &count, &SIZE, 7);
    add(answer, &count, &SIZE, 8);
    add(answer, &count, &SIZE, 9);
    add(answer, &count, &SIZE, 1);
    add(answer, &count, &SIZE, 2);
    add(answer, &count, &SIZE, 3);
    add(answer, &count, &SIZE, 4);
    add(answer, &count, &SIZE, 5);
    add(answer, &count, &SIZE, 6);
    
    display(answer, count);
    
    printf("\nMean: %.2f\n", mean(answer, count));
    printf("Median: %.2f\n", median(answer, count));
    printf("Min: %d\n", min(answer, count));
    printf("Max: %d\n", max(answer, count));
    printf("Range: %d\n", range(answer, count));
    mode(frequency, &frequencySize, answer, count);
    printf("Mode(s): ");
    int isFirst = 1;
    for(int i = 1; i <= 9; i++) {
        if(frequency[i] == frequency[0]) {
            if(!isFirst) printf(", ");
            printf("%d", i);
            isFirst = 0;
        }
    }
    printf(" (appearing %d times)\n", frequency[0]);
    histogram(answer, count);
    
    return 0;
}