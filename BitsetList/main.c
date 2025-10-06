#include <stdio.h>
#include <stdlib.h>
#include "bitsetlist.h"

int main() {
    printf("=== BitSet using Linked List Test ===\n\n");
    
    BitSet setA = initialize();
    BitSet setB = initialize();
    
    printf("Adding elements to Set A: {3, 5, 7, 9}\n");
    setA = add(3, setA);
    setA = add(5, setA);
    setA = add(7, setA);
    setA = add(9, setA);
    
    printf("Adding elements to Set B: {2, 5, 6, 7, 8}\n");
    setB = add(2, setB);
    setB = add(5, setB);
    setB = add(6, setB);
    setB = add(7, setB);
    setB = add(8, setB);
    
    printf("Set A: ");
    display(setA);
    printf("Set B: ");
    display(setB);
    
    printf("\n--- Basic Operations ---\n");
    printf("Is setA empty? %s\n", isEmpty(setA) ? "Yes" : "No");
    printf("Cardinality of setA: %d\n", cardinality(setA));
    printf("Does setA contain 5? %s\n", contains(setA, 5) ? "Yes" : "No");
    printf("Does setA contain 4? %s\n", contains(setA, 4) ? "Yes" : "No");
    
    printf("\n--- Set Operations ---\n");
    BitSet unionSet = getUnion(setA, setB);
    printf("Union of A and B: ");
    display(unionSet);
    
    BitSet interSet = intersection(setA, setB);
    printf("Intersection of A and B: ");
    display(interSet);
    
    BitSet diffResult = initialize();
    diffResult = difference(diffResult, setA, setB);
    printf("Difference A - B: ");
    display(diffResult);
    
    printf("\n--- Set Relationships ---\n");
    printf("Are A and B equal? %s\n", equal(setA, setB) ? "Yes" : "No");
    printf("Are A and B disjoint? %s\n", disjoint(setA, setB) ? "Yes" : "No");
    printf("Is A a subset of B? %s\n", subset(setA, setB) ? "Yes" : "No");
    
    printf("\n--- Subset Test ---\n");
    BitSet setC = initialize();
    setC = add(5, setC);
    setC = add(7, setC);
    printf("Set C: ");
    display(setC);
    printf("Is C a subset of A? %s\n", subset(setC, setA) ? "Yes" : "No");
    printf("Is C a subset of B? %s\n", subset(setC, setB) ? "Yes" : "No");
    
    free(setA);
    free(setB);
    free(setC);
    
    return 0;
}