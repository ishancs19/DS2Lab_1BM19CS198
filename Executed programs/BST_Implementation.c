#include<stdio.h>
#include<stdlib.h>
struct BST {
	struct BST *left;
	struct BST *right;
	int data;
};
struct BST *root = NULL;

struct BST *create() {
	int new_data;
	struct BST *temp = (struct BST*)malloc(sizeof(struct BST));
	printf("\nEnter new data: ");
	scanf("%d", &new_data);
	temp -> data = new_data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;

}

void insert (struct BST *root, struct BST *temp) {
	
	if (temp -> data < root -> data) {
		if (root->left != NULL)
			insert(root->left, temp);
		else
			root->left = temp;
	}

	if (temp -> data > root -> data) {
		if (root->right != NULL)
			insert(root->right, temp);
		else
			root->right = temp;
	} 
}

void inorder(struct BST *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("\n%d ", root->data);
		inorder(root->right);
	}
}

void postorder(struct BST *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("\n%d ", root->data);
	}
}

void preorder(struct BST *root) {
	if (root != NULL) {
		printf("\n%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	int x;
	struct BST* temp = NULL;
	do{
		printf("\n------MENU------");
		printf("\n1. Insert");
		printf("\n2. Inorder Display");
		printf("\n3. Postorder Display");
		printf("\n4. Preorder Display");
		printf("\n5. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &x);
		switch(x) {
			case 1: temp = create(); 
					insert(root, temp);
					break;
			case 2: inorder(root);
					break;
			case 3: postorder(root);
					break;
			case 4: preorder(root);
					break;
			case 5: exit(0);
					break;
			default: printf("\nInvalid option entered.");
		}
	} while(x >= 1 && x <= 5);

	return 0;
}
