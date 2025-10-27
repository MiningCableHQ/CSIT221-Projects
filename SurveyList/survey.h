typedef struct node* Nodeptr;
typedef struct node{
    int data;
    Nodeptr next;
}Node;

typedef Nodeptr StatisticianList;

void display(StatisticianList answer);
void add(StatisticianList* answer, int item);
float mean(StatisticianList answer);
float median(StatisticianList answer);
int max(StatisticianList answer);
int min(StatisticianList answer);
int range(StatisticianList answer);
void mode(int freq[], int* freqsize, StatisticianList answer);
void histogram(StatisticianList answer);