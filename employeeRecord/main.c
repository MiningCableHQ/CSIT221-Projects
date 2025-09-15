#include <stdio.h>
#include "employeeRecord.h"

int main(){
    int size = 0;
    double totalTaxWithheld = 0;
    
    printf("Enter number of Employees: ");
    scanf("%d",&size);
    printf("\n");
    payrecord payroll[size];
    
    readRecords(payroll, size);
    double totalGrossPay = calcRecords(payroll, size, &totalTaxWithheld);
    
    printRecords(payroll, size);
    printSummary(totalGrossPay, totalTaxWithheld);
    
    return 0;
}