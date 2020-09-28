#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int s[MAX_SIZE], top = -1;
void push(int a) {
	if (top == MAX_SIZE-1){
		printf("\nStack is Full!!");
	}
	else{
		printf("\n%d has been pushed into the stack!!", a);
		top++;
		s[top] = a;
	}
}

void pop(){
	if (top == -1){
		printf("\nStack is empty!!");
	}
	else{
		printf("\n%d has been popped!!", s[top]);
		top--;
	}
}

void display(){
	if (top == -1){
		printf("\nStack is empty!!");
	}
	else{
		printf("\nElements of stack are : ");
		for(int i = top; i>=0 ; i--)
		printf("\n%d", s[i]);
	}
}

int main(){
	int val, x;
	do{
		printf("\n\t***MENU***\t\n");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nSelect an option: ");
		scanf("%d", &x);
		switch(x){
			case 1: printf("\nEnter a number to be pushed to the stack: ");
					scanf("%d", &val);
					push(val);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("\nError, Invalid option selected");
		}
	}while(x>=0 && x<=4);
	return 0;
}
