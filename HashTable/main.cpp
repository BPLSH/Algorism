/*#include <stdio.h>
#include <stdlib.h>
#define BUSKET_NUMBER 100

struct Entry
{
	char* key;
	char* value;
	struct Entry* next;
};

struct HashTable  
{
	struct Entry** buskets;
};

struct HashTable* createHashTable()
{
	struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
	table->buskets = (struct Entry**)malloc(sizeof(struct Entry*) * BUSKET_NUMBER);

	for (int i = 0; i < BUSKET_NUMBER; i++)
	{
		table->buskets[i] = NULL;
	}

	return table;
}

struct Entry* createEntry(char* key, char* value)
{
	struct Entry* node = (struct Entry*)malloc(sizeof(struct Entry));
	node->key = key;
	node->value = value;
	node->next = NULL;
	node->valueHashCode = 0;

	return node;
}

/*unsigned int getHashcode(char* str)
{
	char* runner = str;

	unsigned int hashCode = 0;
	while (*runner++)
	{
		hashCode += *runner;
	}

	return hashCode;
}

*unsigned int equals(char* str1, char* str2)
{
	int i = 0;

	for (; str1[i] != '\0'; i++)
	{
		if (str2[i] == '\0')
		{
			return 0;
		}

		if (str1[i] != str2[i])
		{
			return 0;
		}
	}

	return 1;
}

struct Entry* moveToTail(struct Entry* node)
{
	struct Entry* current = node;

	while (current)
	{
		current = current->next;
	}

	return current;
}

struct Entry* find(struct Entry* node, char* key)
{
	struct Entry* current = node;

	while (current)
	{
		if (equals(current->key, key))
		{
			return current;
		}

		current = current->next;
	}

	return NULL;
}


/*8int hash(int code)
{
	return code % BUSKET_NUMBER;
}

char* get(struct HashTable* table, const char* key)
{
	unsigned int code = getHashcode(key);

	unsigned int index = hash(code);

	if (table->buskets[index] == NULL)
	{
		return NULL;
	}

	struct Entry* found = find(table->buskets[index], key);
	if (found == NULL)
	{
		return NULL;
	}

	return found->value;
}

void put(struct HashTable* table,const char* key, const char* value)
{
	unsigned int code = getHashcode(key);
	unsigned int index = hash(code);
	struct Entry* node = createEntry(key, value);

	printf("%s hash : [%d] index : %d \n", key, code, index);

	if (table->buskets[index] == NULL)
	{
		table->buskets[index] = node;
	}
	else
	{
		struct Entry* current = table->buskets[index];

		if (current == NULL)
		{
			current = node;
			return;
		}

		if (equals(current->key, key))
		{
			current->value = value;
			return;
		}

		while (current->next)
		{
			if (equals(current->key, key))
			{
				current->value = value;
				return;
			}

			current = current->next;
		}

		current->next = node;
	}
}

int main(void)
{
	struct HashTable* table = createHashTable();
	put(table, "Samsung", "Samsung is the most famous company in korea.");
	put(table, "Apple", "Apple is the compay making useful phone.");
	put(table, "Hwanhee", "Hwanhee is a person.");
	put(table, "Hwanhef", "Hwanhef is a wrong word.");

	printf("%s \n", get(table, "Samsung"));
	printf("%s \n", get(table, "Apple"));
	printf("%s \n", get(table, "Hwanhee"));
	printf("%s \n", get(table, "Hwanhee2"));

	put(table, "Hwanhee", "Hwanhee is a good person.");

	printf("%s \n", get(table, "Hwanhee"));
	printf("%s \n", get(table, "Hwanhef"));

	getchar();
	return 0;
}*/

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