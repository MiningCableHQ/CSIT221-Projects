//----- STRUCTURES -----
typedef struct namerec{
    char last[15];
    char first[15];
    char middle[15];
}namerec;

typedef struct payrecord{
    int id;
    namerec name;
    float hours, rate;
    float regular, overtime;
    float gross, tax_withheld, net;
}payrecord;

//----- FUNCTIONS -----
void readName(payrecord payroll[], int i);
void printName(payrecord payroll[], int i);
void readRecords(payrecord payroll[], int n);
float calculateTax(double gross);
double calcRecords(payrecord payroll[], int n, double *taxptr);
void printRecords(payrecord payroll[], int n);
void printSummary(double gross, double tax);