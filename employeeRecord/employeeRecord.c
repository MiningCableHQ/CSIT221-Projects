#include <stdio.h>
#include "employeeRecord.h"

//----- FUNCTIONS -----
void readName(payrecord payroll[], int i){
    printf("Enter First Name: ");
    scanf(" %[^\n]",payroll[i].name.first);
    printf("Enter Middle Name: ");
    scanf(" %[^\n]",payroll[i].name.middle);
    printf("Enter Last Name: ");
    scanf(" %[^\n]",payroll[i].name.last);
}
void printName(payrecord payroll[], int i){
    printf("Employee Name: %s %s %s\n", payroll[i].name.first, payroll[i].name.middle, payroll[i].name.last);
}
void readRecords(payrecord payroll[], int n){
    printf("------------ READING RECORDS ------------\n");
    for(int i = 0; i < n; i++){
        printf("Employee [%d]:\n",i+1);
        printf("Enter ID Number: ");
        scanf("%d",&payroll[i].id);
        readName(payroll, i);
        printf("Enter Hours Worked: ");
        scanf("%f",&payroll[i].hours);
        printf("Enter Work Rate: ");
        scanf("%f",&payroll[i].rate);
        printf("\n");
    }
    printf("\n");
}
float calculateTax(double gross){
    float taxRate;
    if(gross < 500){
        taxRate = gross * 0.15;
    }else if(gross < 1000){
        taxRate = gross * 0.28;
    }else{
        taxRate = gross * 0.33;
    }
    return taxRate;
}
double calcRecords(payrecord payroll[], int n, double *taxptr){
    double totalGrossPay = 0;
    for(int i = 0; i < n; i++){
        if(payroll[i].hours <= 40){
            payroll[i].regular = payroll[i].hours * payroll[i].rate;
            payroll[i].overtime = 0;
        }else{
            payroll[i].regular = 40 * payroll[i].rate;
            payroll[i].overtime = (payroll[i].hours - 40) * payroll[i].rate * 1.5;
        }
        
        payroll[i].gross = payroll[i].regular + payroll[i].overtime;
        totalGrossPay += payroll[i].gross;
        payroll[i].tax_withheld = calculateTax(payroll[i].gross);
        *taxptr += payroll[i].tax_withheld;
        payroll[i].net = payroll[i].gross - payroll[i].tax_withheld;
    }
    return totalGrossPay;
}
void printRecords(payrecord payroll[], int n){
    printf("------------ PRINTING RECORDS ------------\n");
    for(int i = 0; i < n; i++){
        printf("Employee [%d]:\n",i+1);
        printf("ID Number: %d\n",payroll[i].id);
        printName(payroll, i);
        printf("Hours Worked: %.2f hrs\n",payroll[i].hours);
        printf("Work Rate: %.2f\n",payroll[i].rate);
        printf("Regular: %.2f\n",payroll[i].regular);
        printf("Overtime: %.2f\n",payroll[i].overtime);
        printf("Gross Salary: Php %.2f\n",payroll[i].gross);
        printf("Tax Withheld: Php %.2f\n",payroll[i].tax_withheld);
        printf("Net Salary: Php %.2f\n\n",payroll[i].net);
    }
}
void printSummary(double gross, double tax){
    printf("\n---------- TOTAL SUMMARY ----------\n");
    printf("Total Gross Pay: Php %.2f\n",gross);
    printf("Total Tax Withheld: Php %.2f\n",tax);
}