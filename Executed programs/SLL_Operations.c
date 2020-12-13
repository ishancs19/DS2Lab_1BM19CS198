#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *head_ref;
struct Node *head2;
struct Node *head3;


void push(struct Node *head, int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(head == NULL) {
		head = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}
}


void append(struct Node *head, int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = head;
	new_node->data = new_data;
	new_node->next = NULL;
	if (head == NULL){
		head = new_node;
		return;
	}
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}


void pop(struct Node *head) {
	struct Node *ptr = head;
	if(head == NULL){
		printf("\nList is empty.");
	}
	else {
		head = ptr->next;
		ptr->next = NULL;
		free(ptr);
	}
}

void reverse(struct node *head) {
	struct Node *next_ptr = NULL;
	struct Node *prev = NULL;
	struct Node *current = head;
	while(current != NULL) {
		next_ptr = current -> next;
		current -> next = prev;
		prev = current;
		current = next_ptr;
	}
	head = prev;
}


struct Node* concat(struct Node *headref2, struct Node *headref3) {
	struct Node* temp;
	if(headref2 == NULL){
		return headref3;
	}
	else if(headref3 == NULL) {
		return headref2;
	}

	temp = headref2;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	ptr -> link = headref3;
	return headref2;
}


void display(struct Node *head) {
	struct Node *node = head;
	if (head == NULL)
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
	int ll;
	do {
		printf("\n------MENU------");
		printf("\n1. Push");
		printf("\n2. Enqueue");
		printf("\n3. Pop");
		printf("\n4. Dequeue");
		printf("\n5. Reverse");
		printf("\n6. Display.");
		printf("\n7. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &x);
		switch(x) {
			case 1: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					printf("\nSelect Linked List to Push to: ");
					scanf("%d", &ll);
					switch(ll){
						case 1: push(&head_ref, data);
						break;
						case 2: push(&head2, data);
						break;
						case 3: push(&head3, data);
						break;
					}
					push(data);
					break;
			case 2: printf("\nEnter data to be inserted: ");
					scanf("%d", &data);
					append(data);
					break;
			case 3: pop();
					break;
			case 4: pop();
					break;
			case 5: reverse();
					break;
			case 6: display();
					break;
			case 7: exit(0);
					break;
			default: printf("\nInvalid option entered.");
		}
	} while(x >= 1 && x <= 7);
	return 0;
}
