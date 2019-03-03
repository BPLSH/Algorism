

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUSKET_NUMBER 100

typedef struct Entry {
	const char* key;
	const char* value;
	struct Entry* next;
}Entry;
typedef struct HashTable {
	struct Entry** buskets;
}HashTable;
HashTable* CreateHashTable() {
	HashTable* table = (struct HashTable*)malloc(sizeof(HashTable));
	table->buskets = (struct Entry**)malloc(sizeof(Entry*)*BUSKET_NUMBER);
	for (int i = 0; i < BUSKET_NUMBER; i++) {
		table->buskets[i] = NULL;
	}
	return table;
}
Entry* CreateEntry(const char* key, const char* value) {
	Entry* node = (Entry*)malloc(sizeof(Entry));
	node->key = (char*)malloc(strlen(key) + 1);
	node->value = (char*)malloc(strlen(value) + 1);
	node->key = key;
	node->value = value;
	//strcpy_s(node->key,sizeof(node->key), key);
	//strcpy_s(node->value, strlen(value) + 1, value);
	
	node->next = NULL;

	return node;
}
int GetHashCode(const char* key) {
	int hashCode = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hashCode += key[i];
	}
	return hashCode;
}
int Hash(unsigned int hashCode) { //¾î¶²°Ç int, u_int
	return hashCode % BUSKET_NUMBER;
}

int Equals(const char* str1, const char* str2) {
	if (strcmp(str1, str2) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int Find(Entry* node, const char* key) {
	Entry* cur = node;
	if (Equals(cur->key, key)) {
		return 1;
	}
	else {
		return 0;
	}
}
void Put(HashTable* table, const char* key, const char* value) {
	int index = Hash(GetHashCode(key));
	Entry* node = CreateEntry(key, value);

	if (table->buskets[index] == NULL) {
		table->buskets[index] = node;
	}
	else {
		Entry* cur = table->buskets[index];
		while (cur != NULL) {
			if (Find(cur, key)) {
				cur->value = value;
				return;
			}
			if (cur->next == NULL) {
				break;
			}
			cur = cur->next;
		}
		cur->next = node;
	}

}

const char* Get(HashTable* table, const char* key) {
	unsigned int index = Hash(GetHashCode(key));
	Entry* cur = table->buskets[index];
	if (cur == NULL) {
		return NULL;
	}
	while (cur != NULL) {
		if (Find(cur, key)) {
			return cur->value;
		}
		cur = cur->next;
	}
	if (cur == NULL) {
		return NULL;
	}
}
int main(void) {
	HashTable* table = CreateHashTable();
	Put(table, "Jane", "Sexy");
	Put(table, "Suzy", "Cute");
	Put(table, "Anna", "Pretty");
	Put(table, "Hazely", "Beautiful");

	printf("%s \n", Get(table, "Jane"));
	printf("%s \n", Get(table, "Suzy"));
	printf("%s \n", Get(table, "Anna"));
	printf("%s \n", Get(table, "Hazely"));

	Put(table, "Anna", "Ugly");

	printf("%s \n", Get(table, "Jane"));
	printf("%s \n", Get(table, "Suzy"));
	printf("%s \n", Get(table, "Anna"));
	printf("%s \n", Get(table, "Hazely"));

	getchar();
	return 0;
}