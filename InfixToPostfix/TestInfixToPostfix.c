#include <stdio.h>
#include "InfixToPostfix.h"

int main(){
	char infix[100];
	char postfix[100];
	int result;
	
	printf("--- Infix to Postfix Converter and Evalator ---\n\n");
	
	printf("1. Infix to Postfix Conversion:\n");
	strcpy(infix, "a+b*c-d");
	infixToPostfix(infix, postfix);
	printf(" Infix String: %s\n", infix);
	printf(" Postfix String: %s\n\n", postfix);
	
	printf("2. Postfix Evaluation:\n");
	strcpy(postfix, "123*+4-");
	result = evaluatePostfix(postfix);
	printf(" Postfix String: %s\n", postfix);
	printf(" Result: %d\n", result);
	
	char response = 'y';
	while(response == 'y'){
		printf("\n3. Interactive Testing:\n");
		printf(" Enter an infix expression: ");
		scanf(" %[^\n]", infix);
		
		infixToPostfix(infix, postfix);
		printf(" Postfix result: %s\n", postfix);
		
		if(strspn(infix, "0123456789+-*/() ") == strlen(infix)){
			result = evaluatePostfix(postfix);
			printf(" Evaluation result: %d\n\n", result);
		}
		
		printf("Continue? [y/n]: ");
		scanf(" %c", &response);
	}
	
	
	return 0;
}
