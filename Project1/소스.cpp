#include<stdio.h> 
#include<stdlib.h> 

typedef struct node
{
	int key;
	struct node *left, *right;
} Node;

Node* newNode(int item)
{
	Node *temp = (Node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node* node, int key)
{
	if (node == NULL) {
		return newNode(key);
	}

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else {
		node->right = insert(node->right, key);
	}

	return node;
}

Node* minValueNode(Node* node)
{
	struct node* current = node;

	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

Node* deleteNode(Node* root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		if (root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}

		Node* temp = minValueNode(root->right);

		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
int main()
{
	Node* root = NULL;
	root = insert(root, 37);
	root = insert(root, 14);
	root = insert(root, 65);
	root = insert(root, 4);
	root = insert(root, 21);
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 9);

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 4\n");
	root = deleteNode(root, 4);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	/*printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);
	*/
	getchar();

	return 0;
}