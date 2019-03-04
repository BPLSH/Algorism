//doubleLinkedList

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	char* data; //문자열 메모리
	struct tagNode* next;
	struct tagNode* prev;
}Node;
Node* head = NULL;

Node* CreateNode(const char* data) { //const
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(data) + 1); //동적할당
	strcpy_s(newNode->data, strlen(data) + 1, data);
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
void AppendNode(Node* newNode) { //노드추가

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		newNode->prev = tmp;
	}
}
void InsertBeforeNode(Node* newNode, const char* data) {

	Node* tmp = head;

	while (tmp != NULL) {
		if (strcmp(tmp->data, data) == 0) {
			tmp->prev->next = newNode;
			newNode->next = tmp;
			newNode->prev = tmp->prev;
			tmp->prev = newNode;

			return;
		}

		tmp = tmp->next;
	}
	if (tmp == NULL) {
		printf("check data again\n");
		return;
	}
}

Node* RemoveNode(const char* data) {
	Node* tmp = head;
	
	if (head != NULL) {
		if (strcmp(tmp->data, data) == 0) { //head->data == data 인 경우
			head = head->next;
			return tmp;
		}
		while (tmp != NULL) {
			if (strcmp(tmp->data, data) == 0) {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;

				return tmp;
			}
			tmp = tmp->next;
		}
	}

	printf("check data again\n");
	return NULL;
}

void DestroyNode(Node* node) {
	free(node->data);
	free(node);
}
void PrintList() {
	for (Node* tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%s ", tmp->data);
	}
	printf("\n");
}
int main(void) {
	AppendNode(CreateNode("hi"));
	AppendNode(CreateNode("my"));
	AppendNode(CreateNode("name"));
	AppendNode(CreateNode("is"));
	AppendNode(CreateNode("sangho"));
	PrintList();
	
	printf("sangho 앞에 not 삽입\n");
	InsertBeforeNode(CreateNode("not"), "sangho");
	PrintList();
	
	printf("hi 삭제\n");
	DestroyNode(RemoveNode("hi"));
	PrintList();


	getchar();
	return 0;
}