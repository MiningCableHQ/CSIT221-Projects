#include "bitset.h"
#include <stdio.h>

void initialize(BitSet s){
    for(int i = 0; i < MAX; i++){
        s[i] = 0;
    }
}
void add(int elem, BitSet s){
    s[elem] = 1;
}
void display(BitSet s){
    printf("{");
    int firstElementFound = 0;
    for(int i = 0; i < MAX; i++){
        if(s[i] == 1){
            if(firstElementFound){
                printf(", ");
            }
            printf("%d", i);
            firstElementFound = 1;
        }
    }
    printf("}\n");
}
void getUnion(BitSet result, BitSet s1, BitSet s2){
    initialize(result);
    for(int i = 0; i < MAX; i++){
        result[i] = s1[i] == 1 || s2[i] == 1;
    }
}
void intersection(BitSet result, BitSet s1, BitSet s2){
    initialize(result);
    for(int i = 0; i < MAX; i++){
        result[i] = s1[i] == 1 && s2[i] == 1;
    }
}
void difference(BitSet result,BitSet s1,BitSet s2){
    initialize(result);
    for(int i = 0; i < MAX; i++){
        result[i] = s1[i] == 1 && s2[i] == 0;
    }
}

int isEmpty(BitSet s){
    for(int i = 0; i < MAX; i++){
        if(s[i] == 1){
            return 0;
        }
    }
    return 1;
}
int contains(BitSet s, int elem){
    return s[elem];
}
int disjoint(BitSet s1,BitSet s2){
    BitSet result;
    intersection(result, s1, s2);
    if(isEmpty(result)){
        return 1;
    }else{
        return 0;
    }
}
int equal(BitSet s1,BitSet s2){
    for(int i = 0; i < MAX; i++){
        if(s1[i] != s2[i]){
            return 0;
        }
    }
    return 1;
}
int cardinality(BitSet s){
    int count = 0;
    for(int i = 0; i < MAX; i++){
        if(s[i] == 1){
            count++;
        }
    }
    return count;
}
int subset(BitSet s1,BitSet s2){
    for(int i = 0; i < MAX; i++){
        if(s1[i] == 1 && s2[i] == 0){
            return 0;
        }
    }
    return 1;
}