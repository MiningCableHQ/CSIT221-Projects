typedef struct node* Nodeptr;

typedef struct node{
    int data;
    Nodeptr next;
}Node;

typedef Nodeptr BitSet;

BitSet initialize();
BitSet add(int elem, BitSet s);
void display(BitSet s);
BitSet getUnion(BitSet s1, BitSet s2);
BitSet intersection(BitSet s1, BitSet s2);
BitSet difference(BitSet result, BitSet s1, BitSet s2);
int isEmpty(BitSet s);
int contains(BitSet s, int elem);
int disjoint(BitSet s1, BitSet s2);
int equal(BitSet s1, BitSet s2);
int cardinality(BitSet s);
int subset(BitSet s1, BitSet s2);