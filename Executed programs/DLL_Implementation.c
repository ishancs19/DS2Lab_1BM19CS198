#include<stdio.h>
#include<stdlib.h>
struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
};
	struct Node* head;

void insert(int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	if(head == NULL){
		head = new_node;
	}
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}


void delete(int val) {
	struct Node *ptr, *temp;
	ptr = head;
	while (ptr -> data != val){
		ptr = ptr -> next;
	}
	temp = ptr -> prev;
	if(ptr == NULL) {
		printf("\nCan't delete\n");
	}
	else if (ptr == head) {
		if(ptr -> next == NULL){
			head = NULL;
			free(ptr);
			printf("\nNode Deleted\n");
		}
		else {
			ptr -> next -> prev = head;
			head = ptr -> next;
			free(ptr);
			printf("\nNode Deleted\n");
		}
	}
	else if(temp -> next -> next == NULL) {
		temp ->next  = NULL;
		printf("\nNode Deleted\n");
	}
	else {
		temp -> next = ptr -> next;
		ptr -> next -> prev = temp;
		free(ptr);
		printf("\nNode Deleted\n");
	}
}


void display() {
	struct Node *temp = head;
	if(temp == NULL) {
		printf("\nList is empty");
	}
	else {
		while(temp != NULL){
			printf("\n%d ", temp->data);
			temp = temp->next;
		}
	}
}

int main() {
	int x;
	int data;
	int val;
	do {
		printf("\n------MENU------");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &x);
		switch(x) {
			case 1: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					insert(data);
					break;
			case 2: printf("\nEnter data to be deleted: ");
					scanf("%d", &val);
					delete(val);
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
