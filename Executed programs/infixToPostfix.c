#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50
int s[MAX_SIZE], top = -1;
void push(char a) {
	if (top == MAX_SIZE-1){
		printf("\nStack is Full!!");
	}
	else{
		printf("\n%c has been pushed into the stack!!", a);
		top++;
		s[top] = a;
	}
}

void pop(){
	if (top == -1){
		printf("\nStack is empty!!");
	}
	else{
		printf("\n%c has been popped!!", s[top]);
		top--;
	}
}

int pr(char a){
	if(a == '^')
	return 3;
	else if(a == '*' || a == '/')
	return 2;
	else if(a == '+' || a == '-')
	return 1;
	else return 0;
}

int main(){
	char postFix[50], inFix[50];
	int k = 0;
	printf("\nEnter the infix expression: ");
	gets(inFix);
	push('#');
	for(int i = 0; i < strlen(inFix); i++){
		if ((inFix[i] >= 'A' &&inFix[i] <= 'Z')||(inFix[i] >= 'a' && inFix[i] <= 'z')){
			postFix[k++] = inFix[i];
		}
		else if (inFix[i] == '('){
			push(inFix[i]);
		}
		else if(inFix[i] == ')'){
			while(s[top] != '(' ){
				postFix[k++] = s[top];
				pop();
			}
			pop();
		}
		else{
			while (pr(s[top]) >= pr(inFix[i])){
				postFix[k++] = s[top];
				pop();
			}
			push(inFix[i]);
		}
	}
	while(s[top] != '#'){
		postFix[k++] = s[top];
		pop();
	}
	postFix[k++] = '\0';
	printf("\nPostfix expression is : %s", postFix);
	return 0;
}
