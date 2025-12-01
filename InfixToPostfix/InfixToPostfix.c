#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

CharStack createCharStack(){
	CharStack newStack = (CharStack)malloc(sizeof(CharStackHead));
	if(newStack != NULL){
		newStack->count = 0;
		newStack ->top = NULL;
	}
	return newStack;
}
int isCharStackEmpty(CharStack s){
	return (s == NULL || s->top == NULL);
}
void pushChar(CharStack s, stackDataItem item){
	if(s == NULL) return;
	
	CharNode* newNode = (CharNode*)malloc(sizeof(CharNode));
	if(newNode != NULL){
		newNode->data = item;
		newNode->next = s->top;
		s->top = newNode;
		s->count++;
	}
}
stackDataItem popChar(CharStack s){
	if(isCharStackEmpty(s)){
		return '\0';
	}
	
	CharNode* temp = s->top;
	stackDataItem poppedItem = temp->data;
	s->top = s->top->next;
	s->count--;
	free(temp);
	return poppedItem;
}
stackDataItem peekChar(CharStack s){
	if(isCharStackEmpty(s)){
		return '\0';
	}
	return s->top->data;
}

IntStack createIntStack(){
	IntStack newStack = (IntStack)malloc(sizeof(IntStackHead));
	if(newStack != NULL){
		newStack->count = 0;
		newStack->top = NULL;
	}
	return newStack;
}
int isIntStackEmpty(IntStack s){
	return (s == NULL || s->top == NULL);
}
void pushInt(IntStack s, evalDataItem item){
	if(s == NULL) return;
	
	IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
	if(newNode != NULL){
		newNode->data = item;
		newNode->next = s->top;
		s->top = newNode;
		s->count++;
	}
}
evalDataItem popInt(IntStack s){
	if(isIntStackEmpty(s)){
		return 0;
	}
	
	IntNode* temp = s->top;
	evalDataItem poppedItem = temp->data;
	s->top = s->top->next;
	s->count--;
	free(temp);
	return poppedItem;
}

int isOperator(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int getPrecedence(char operator){
	switch(operator){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}

void infixToPostfix(const char* infix, char* postfix){
	CharStack stack = createCharStack();
	int i, j = 0;
	char token, topToken;
	
	for(i = 0; infix[i] != '\0'; i++){
		token = infix[i];
		
		if(token == ' ')continue;
		
		if(isalnum(token)){
			postfix[j++] = token;
		}else if(token == '('){
			pushChar(stack, token);
		}else if(token == ')'){
			while(!isCharStackEmpty(stack) && peekChar(stack) != '('){
				postfix[j++] = popChar(stack);
			}
			popChar(stack);
		}else if(isOperator(token)){
			while(!isCharStackEmpty(stack) && getPrecedence(peekChar(stack)) >= getPrecedence(token)){
				postfix[j++] = popChar(stack);
			}
			pushChar(stack, token);
		}
	}
	
	while(!isCharStackEmpty(stack)){
		postfix[j++] = popChar(stack);
	}
	
	postfix[j] = '\0';
	
	free(stack);
}

int evaluatePostfix(const char* postfix){
	IntStack stack = createIntStack();
	int i, operand1, operand2, result;
	char token;
	
	for(i = 0; postfix[i] != '\0'; i++){
		token = postfix[i];
		
		if(token == ' ') continue;
		
		if(isdigit(token)){
			pushInt(stack, token - '0');
		}else if(isOperator(token)){
			operand2 = popInt(stack);
			operand1 = popInt(stack);
			
			switch(token){
				case '+': result = operand1 + operand2; break;
				case '-': result = operand1 - operand2; break;
				case '*': result = operand1 * operand2; break;
				case '/': result = operand1 / operand2; break;
				default: result = 0;
			}
			
			pushInt(stack, result);
		}
	}
	
	result = popInt(stack);
	free(stack);
	return result;
}
