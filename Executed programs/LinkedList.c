#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *head_ref;


void push(int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(head_ref == NULL) {
		head_ref = new_node;
	}
	else {
		new_node->next = head_ref;
		head_ref = new_node;
	}
}


void append(int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (head_ref == NULL){
		head_ref = new_node;
		return;
	}
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}

void insert_pos(int new_data, int pos) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *ptr = head_ref;
	new_node->data = new_data;
	if (pos == 1) {
		new_node->next = ptr;
		head_ref = new_node;
		return;
	}
	for (int i = 1; i < pos-1; i++)
	{
		ptr = ptr->next;
	}
	if (ptr == NULL)
		printf("\nInvalid position");
	else {
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}


void pop() {
	struct Node *ptr = head_ref;
	if(head_ref == NULL){
		printf("\nList is empty.");
	}
	else {
		head_ref = ptr->next;
		ptr->next = NULL;
		free(ptr);
	}
}


void end_delete() {
	struct Node *ptr = head_ref, *ptr1;
	if (head_ref == NULL)
	{
		printf("\nList is empty.");
	}
	else if (head_ref->next == NULL) {
		head_ref = NULL;
		free(head_ref);
	}
	else {
		while(ptr->next != NULL) {
			ptr1 = ptr;
			ptr = ptr->next;
		}
		ptr1->next = NULL;
		free(ptr);
	}
}

void delete_any(int pos) {
	struct Node *ptr = head_ref;
	struct Node *ptr1;
	for (int i = 0; i < pos; i++)
	{
		ptr1 = ptr;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		printf("\nInvalid position");
	else {
		ptr1->next = ptr->next;
		free(ptr);
	}
}


void display() {
	struct Node *node = head_ref;
	if (head_ref == NULL)
	{
		printf("\nList is Empty.");	
	}
	while(node != NULL) {
		printf("\n%d ", node->data);
		node = node->next;
	}
}


int main() {
	int x;
	int data;
	int position;
	do {
		printf("\n------MENU------");
		printf("\n1. Insert at beginning.");
		printf("\n2. Insert at end.");
		printf("\n3. Insert from any position.");
		printf("\n4. Delete from beginning.");
		printf("\n5. Delete from end.");
		printf("\n6. Delete from any position.");
		printf("\n7. Display.");
		printf("\n8. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &x);
		switch(x) {
			case 1: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					push(data);
					break;
			case 2: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					append(data);
					break;
			case 3: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					printf("\nEnter position of insertion: ");
					scanf("%d", &position);
					insert_pos(data, position);
					break;
			case 4: pop();
					break;
			case 5: end_delete();
					break;
			case 6: printf("\nEnter position of deletion.");
					scanf("%d", &position);
					delete_any(position);
					break;
			case 7: display();
					break;
			case 8: exit(0);
					break;
			default: printf("\nInvalid option entered.");
		}
	} while(x >= 0 && x <= 8);
	return 0;
}
