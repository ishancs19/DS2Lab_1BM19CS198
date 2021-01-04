#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bill
{
	char name[50];
	int cost;
	struct Bill *next;
};
struct Bill *head_ref;


void push(char new_data[50], int new_cost) {
	struct Bill *new_node = (struct Bill*)malloc(sizeof(struct Bill));
	strcpy(new_node->name, new_data);
	new_node->cost = new_cost;
	new_node->next = NULL;
	if(head_ref == NULL) {
		head_ref = new_node;
	}
	else {
		new_node->next = head_ref;
		head_ref = new_node;
	}
}


void pop() {
	struct Bill *ptr = head_ref;
	if(head_ref == NULL){
		printf("\nList is empty.");
	}
	else {
		head_ref = ptr->next;
		ptr->next = NULL;
		free(ptr);
	}
}


void display() {
	struct Bill *node = head_ref;
	if (head_ref == NULL)
	{
		printf("\nList is Empty.");	
	}
	while(node != NULL) {
		printf("\n%s -> Rs.%d", node->name, node->cost);
		node = node->next;
	}
}


int main() {
	int x;
	char data[50];
	int c;
	do {
		printf("\n------MENU------");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display.");
		printf("\n4. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &x);
		switch(x) {
			case 1: printf("\nEnter name of item: ");
					scanf("%s", data);
					printf("\nEnter cost of item: ");
					scanf("%d", &c);
					push(data, c);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("\nInvalid option entered.");
		}
	} while(x >= 1 && x <= 4);
	return 0;
}
