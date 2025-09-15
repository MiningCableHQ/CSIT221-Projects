#include <stdio.h>
#include "bitset.h"

int main() {
    BitSet A, B, result;
    int sizeA, sizeB, num;
    
    // Initialize sets
    initialize(A);
    initialize(B);
    
    // Input for Set A
    printf("Enter number of elements for Set A: ");
    scanf("%d", &sizeA);
    printf("Enter %d elements for Set A (0 to %d): ", sizeA, MAX-1);
    for(int i = 0; i < sizeA; i++) {
        scanf("%d", &num);
        if(num >= 0 && num < MAX) {
            add(num, A);
        }
    }
    
    // Input for Set B
    printf("Enter number of elements for Set B: ");
    scanf("%d", &sizeB);
    printf("Enter %d elements for Set B (0 to %d): ", sizeB, MAX-1);
    for(int i = 0; i < sizeB; i++) {
        scanf("%d", &num);
        if(num >= 0 && num < MAX) {
            add(num, B);
        }
    }
    
    // Display the sets
    printf("\nSet A: ");
    display(A);
    printf("Set B: ");
    display(B);
    
    // Perform and display operations
    getUnion(result, A, B);
    printf("Union: ");
    display(result);
    
    intersection(result, A, B);
    printf("Intersection: ");
    display(result);
    
    difference(result, A, B);
    printf("Difference (A - B): ");
    display(result);
    
    // Display properties
    printf("Cardinality of A: %d\n", cardinality(A));
    printf("Cardinality of B: %d\n", cardinality(B));
    printf("A is subset of B: %s\n", subset(A, B) ? "Yes" : "No");
    printf("Sets are equal: %s\n", equal(A, B) ? "Yes" : "No");
    printf("Sets are disjoint: %s\n", disjoint(A, B) ? "Yes" : "No");
    
    return 0;
}