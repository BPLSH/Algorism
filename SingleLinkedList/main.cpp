//BinaryTree
#include <stdio.h>
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
*/
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
}