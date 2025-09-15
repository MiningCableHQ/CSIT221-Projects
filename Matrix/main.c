 #include <stdio.h>
 #include "matrix.h"
 
 int main(){
     
     int matrixA[ROW][COL] = {
         {1, 2, 3, 4, 5, 6},
         {7, 8, 9, 10, 11, 12},
         {13, 14, 15, 16, 17, 18}, 
         {19, 20, 21, 22, 23, 24}, 
         {25, 26, 27, 28, 29, 30}, 
         {31, 32, 33, 34, 35, 36}};
         
     int matrixB[ROW][COL] = {
         {36, 35, 34, 33, 32, 31},
         {30, 29, 28, 27, 26, 25},
         {24, 23, 22, 21, 20, 19}, 
         {18, 17, 16, 15, 14, 13}, 
         {12, 11, 10, 9, 8, 7}, 
         {6, 5, 4, 3, 2, 1}};
         
     int matrixSum[ROW][COL];
     int matrixDifference[ROW][COL];
     int matrixProduct[ROW][COL];
     
     display(matrixA, ROW, COL);
     display(matrixB, ROW, COL);
     
     add(matrixSum, matrixA, matrixB, ROW, COL);
     display(matrixSum, ROW, COL);
     
     subtract(matrixDifference, matrixA, matrixB, ROW, COL);
     display(matrixDifference, ROW, COL);
     
     multiply(matrixProduct, matrixA, matrixB, ROW, COL);
     display(matrixProduct, ROW, COL);
     
     return 0;
 }