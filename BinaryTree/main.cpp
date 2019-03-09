//BinaryTree
/*#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;
typedef struct binarytree {
	struct node* root;
}BinaryTree;
BinaryTree* CreateBinaryTree() {
	BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->root = NULL;
	
	return tree;
}
void DestroyBinaryTree(BinaryTree* tree) {
	free(tree);
}
Node* CreateNode(ElementType data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void DestroyNode(Node* node) {
	free(node);
}
void AppendNode(Node** root, Node* newNode) { //노드연결 //이부분질문
	if (*root == NULL) {//맨처음
		*root = newNode;
	
		return;
	}
	if (newNode->data < (*root)->data) { //left
		if ((*root)->left == NULL) {
			(*root)->left = newNode;
		}
		else {
			AppendNode(&((*root)->left), newNode);
		}
	}
	else {
		if ((*root)->right == NULL) {
			(*root)->right = newNode;
		}
		else {
			AppendNode(&((*root)->right), newNode);
		}
	}
}
/*Node* BinarySearch(Node** root, ElementType data) {
	if (data == (*root)->data) {
		return (*root);
	}
	else {
		if (data < (*root)->data) {
			BinarySearch(&((*root)->left), data);
		}
		else {
			BinarySearch(&((*root)->left), data);
		}
	}
}
Node* RemoveNode(Node** root, ElementType data) {
	Node* target = BinarySearch(root, data);
	printf("%d", target->data);

	return target;
}

void PreOrder(Node** root) { //root->left->right // 34-18-7-83-56-110-97
	if (*root != NULL){
		printf("%d ", (*root)->data);
		PreOrder(&((*root)->left));
		PreOrder(&((*root)->right));
	}
}

void InOrder(Node** root) { //left->root->right // 7-18-34-56-83-97-110
	if (*root != NULL) {
		InOrder(&((*root)->left));
		printf("%d ", (*root)->data);
		InOrder(&((*root)->right));
	}
}

void PostOrder(Node** root) { //left->right->root // 7-18-56-97-110-83-34
	if (*root != NULL) {
		PostOrder(&((*root)->left));
		PostOrder(&((*root)->right));
		printf("%d ", (*root)->data);
	}
}
int main(void) {
	BinaryTree* tree = CreateBinaryTree();
	
	AppendNode(&(tree->root), CreateNode(34));
	AppendNode(&(tree->root), CreateNode(18));
	AppendNode(&(tree->root), CreateNode(83));
	AppendNode(&(tree->root), CreateNode(7));
	AppendNode(&(tree->root), CreateNode(56));
	AppendNode(&(tree->root), CreateNode(110));
	AppendNode(&(tree->root), CreateNode(97));

	printf("PreOrder : "); PreOrder(&(tree->root)); printf("\n");
	printf("InOrder : "); InOrder(&(tree->root)); printf("\n");
	printf("PostOrder : "); PostOrder(&(tree->root)); printf("\n");
	
	//Node* rm_Node = RemoveNode(&(tree->root), 110);
	//printf("%d", rm_Node->data);
	//DestroyNode(rm_Node);
	
	//printf("PreOrder : "); PreOrder(&(tree->root)); printf("\n");
	//printf("InOrder : "); InOrder(&(tree->root)); printf("\n");
	//printf("PostOrder : "); PostOrder(&(tree->root)); printf("\n");

	getchar();
	return 0;
}*/
//BinaryTree
/*#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;
typedef struct binarytree {
	struct node* root;
}BinaryTree;
void CreateBinaryTree(BinaryTree** tree) {
	*tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*tree)->root = NULL;
}
void DestroyBinaryTree(BinaryTree* tree) {
	free(tree);
}
Node* CreateNode(ElementType data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void DestroyNode(Node* node) {
	free(node);
}
void AppendNode(Node** root, Node* newNode) { //노드연결 //이부분질문
	if (*root == NULL) {//맨처음
		*root = newNode;

		return;
	}
	if (newNode->data < (*root)->data) { //left
		if ((*root)->left == NULL) {
			(*root)->left = newNode;
		}
		else {
			AppendNode(&((*root)->left), newNode);
		}
	}
	else {
		if ((*root)->right == NULL) {
			(*root)->right = newNode;
		}
		else {
			AppendNode(&((*root)->right), newNode);
		}
	}
}
Node* BinarySearch(Node* root, ElementType data) {
	if (data == root->data) {
		return root;
	}
	else {
		if (data < root->data) {
			BinarySearch(root->left, data);
		}
		else {
			BinarySearch(root->right, data);
		}
	}
}
Node* TargetParentSearch(Node* root,Node* target) {
	
	if (root->left == target || root->right == target) {
		return root;
	}
	else {
	
		TargetParentSearch(root, target);
	}
}
Node* RemoveNode(Node** root, ElementType data) {
	Node* target = BinarySearch(*root, data);
	Node* parent = TargetParentSearch((*root), target);
	printf("%d", parent->data);
	if (target->left == NULL && target->right == NULL) {
		return target; 
	}
}

void PreOrder(Node* root) { //root->left->right // 34-18-7-83-56-110-97
	if (root != NULL) {
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(Node* root) { //left->root->right // 7-18-34-56-83-97-110
	if (root != NULL) {
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(Node* root) { //left->right->root // 7-18-56-97-110-83-34
	if (root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}
int main(void) {
	BinaryTree* tree = NULL;
	CreateBinaryTree(&tree);
	
	AppendNode(&(tree->root), CreateNode(34));
	AppendNode(&(tree->root), CreateNode(18));
	AppendNode(&(tree->root), CreateNode(83));
	AppendNode(&(tree->root), CreateNode(7));
	AppendNode(&(tree->root), CreateNode(56));
	AppendNode(&(tree->root), CreateNode(110));
	AppendNode(&(tree->root), CreateNode(97));

	//printf("PreOrder : "); PreOrder(tree->root); printf("\n");
	//printf("InOrder : "); InOrder(tree->root); printf("\n");
	//printf("PostOrder : "); PostOrder(tree->root); printf("\n");
	
	//Node* rm_Node = RemoveNode(&(tree->root), 110);
	//printf("%d", rm_Node->data);
	//DestroyNode(rm_Node);

	//printf("PreOrder : "); PreOrder(&(tree->root)); printf("\n");
	//printf("InOrder : "); InOrder(&(tree->root)); printf("\n");
	//printf("PostOrder : "); PostOrder(&(tree->root)); printf("\n");

	getchar();
	return 0;
}*/
//binarySearchTree
#include <stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;
typedef struct binarytree{
	struct node* root;
}BinaryTree;
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void DestroyNode(Node* node) {
	free(node);
}
void InsertNode(Node* root, Node* newNode) {
	if (newNode->data < root->data) { //left
		if (root->left == NULL) {
			root->left = newNode;
		}
		else {
			InsertNode(root->left, newNode);
		}
	}
	else {
		if (root->right == NULL) { //right
			root->right = newNode;
		}
		else {
			InsertNode(root->right, newNode);
		}
	}
}
Node* MinValueNode(Node* root) { //매개변수로 root->right
	if (root == NULL) {
		return NULL;
	}
	if (root->left != NULL) {
		MinValueNode(root->left);
	}
	else {
		return root;
	}
}
Node* DeleteNode(Node* root, int data) {
	if (root = NULL) {
		return NULL;
	}
	if (data < root->data) {
		root->left = DeleteNode(root->left, data);
	}
	else if(data > root->data){
		root->right = DeleteNode(root->right, data);
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			Node * min = MinValueNode(root->right);
			root->data = min->data;

		}
		Node* tmp = root->right;
		free(root);
		return tmp;
	}
}
/*Node* BinarySearch(Node* root, int data) {
	Node* target = root;
	if (target == NULL) {
		return NULL;
	}
	if (target->data == data) {
		return target;
	}
	else {
		if (data < target->data) { //left
			DeleteNode(target->left, data);
		}
		else { //right
			DeleteNode(target->right, data);
		}
	}

}*/

/*Node* DeleteNode(Node* root, int data) {
	if (root == NULL)
	{
		return root;
	}

	if (data < root->data) {
		root->left = DeleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = DeleteNode(root->right, data);
	}
	else
	{
		if (root->left == NULL) //오른쪽만 있는경우 //둘다 없는 경우
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		if (root->right == NULL) //왼쪽만 있는 경우 
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}

		//Node* temp = MinValueNode(root->right); //둘다 있는경우

		//root->data = temp->data;
		//root->right = DeleteNode(root->right, temp->data);
	}
	return root;
}*/
void PreOrder(Node* root) {//root->left->right
	if (root != NULL) {
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(Node* root) { //left->root->right
	if (root != NULL) {
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}
void PostOrder(Node* root) {//left->right->root
	if (root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}
int main(void) {
	Node* root = NULL;

	root = CreateNode(47);
	InsertNode(root, CreateNode(36));
	InsertNode(root, CreateNode(76));
	InsertNode(root, CreateNode(17));
	InsertNode(root, CreateNode(54));
	InsertNode(root, CreateNode(109));
	InsertNode(root, CreateNode(30));
	InsertNode(root, CreateNode(66));
	InsertNode(root, CreateNode(151));
	InsertNode(root, CreateNode(121));
	InsertNode(root, CreateNode(179));

	printf("PreOrder : "); PreOrder(root); printf("\n");
	printf("InOrder : "); InOrder(root); printf("\n");
	printf("PostOrder : "); PostOrder(root); printf("\n");

	printf("%d\n",DeleteNode(root, 109)->data);

	printf("PreOrder : "); PreOrder(root); printf("\n");
	printf("InOrder : "); InOrder(root); printf("\n");
	printf("PostOrder : "); PostOrder(root); printf("\n");

	getchar();
	return 0;
}