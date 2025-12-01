typedef char stackDataItem;

typedef struct charNode{
    stackDataItem data;
    struct charNode* next;
}CharNode;

typedef struct{
    int count;
    CharNode* top;    
}CharStackHead;
typedef CharStackHead* CharStack;

typedef int evalDataItem;

typedef struct intNode{
	evalDataItem data;
	struct intNode* next;
}IntNode;

typedef struct{
	int count;
	IntNode* top;
}IntStackHead;

typedef IntStackHead* IntStack;

CharStack createCharStack();
int isCharStackEmpty(CharStack s);
void pushChar(CharStack s, stackDataItem item);
stackDataItem popChar(CharStack s);
stackDataItem peekCHar(CharStack s);
void displayCharStack(CharStack s);

IntStack createIntStack();
int isIntStackEmpty(IntStack s);
void pushInt(IntStack s, evalDataItem item);
evalDataItem popInt(IntStack s);
evalDataItem peekInt(IntStack s);
void displayIntStack(IntStack s);

void infixToPostfix(const char* infix, char* postfix);
int evaluatePostfix(const char* postfix);
int getPrecedence(char operator);
int isOperator(char c);
