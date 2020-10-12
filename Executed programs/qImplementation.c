#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
int Q[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty(){
	if(front == -1 && rear == -1)
	return 1;
	else return 0;
}

int isFull(){
	if(rear == MAX_SIZE-1)
	return 1;
	else 
	return 0;
}

void push(int x){
	if (isFull())
	printf("\nQueue is Full.");
	else if (isEmpty()){
		front = rear = 0;
		printf("\nElement %d has been pushed onto the Queue succesfully!", x);
	}
	else{
		rear++;
		printf("\nElement %d has been pushed onto the Queue succesfully!", x);
	}
	Q[rear] = x;
}

void pop(){
	if(isEmpty())
	printf("\nQueue is Empty.");
	else if (front == rear){
		printf("\nElement %d has been popped succesfully and Queue has been reset", Q[front]);
		front = rear = -1;
	}
	else{
		printf("\nElement %d has been popped succesfully!", Q[front]);
		front++;
	}
	
}

void display(){
	if(isEmpty())
	printf("\nQueue is empty");
	else{
		printf("\n Elements of Queue are: ");
		for(int i = front; i<=rear; i++){
			printf("\n %d", Q[i]);
		}
	}
}

int main(){
	int ele, x;
	do{
		printf("\n\n*****************MENU**********************\t");
		printf("\n1. Push to Queue");
		printf("\n2. Pop from Queue");
		printf("\n3. Check if Queue is Full");
		printf("\n4. Check if Queue is Empty");
		printf("\n5. Display the contents of the Queue");
		printf("\n6. Exit");
		printf("\n Choose an option: ");
		scanf("%d", &x);
		switch(x){
			case 1: printf("\n Enter the element to be pushed to the Queue: ");
					scanf("%d", &ele);
					push(ele);
					break;
			case 2: pop();
					break;
			case 3: if(isFull())
					printf("\n Queue is full.");
					else printf("\n Queue is NOT Full.");
					break;
			case 4: if(isEmpty())
					printf("\n Queue is Empty.");
					else printf("\n Queue is NOT Empty.");
					break;
			case 5: display();
					break;
			case 6: exit(0);
					break;
			default: printf("\n ERROR! Invalid Option");
		}
		
	}while(x>=0 && x<=6);
	return 0;
}
