#include <stdio.h>
#include "matrix.h"

void display(int matrix[][COL], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%6d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void add(int matrixResult[][COL], int matrixA[][COL], int matrixB[][COL], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void subtract(int matrixResult[][COL], int matrixA[][COL], int matrixB[][COL], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
void multiply(int matrixResult[][COL], int matrixA[][COL], int matrixB[][COL], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrixResult[i][j] = 0;
        }
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < col; k++){
                matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}