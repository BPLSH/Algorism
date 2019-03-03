
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void Reverse(char* str) {
	
	int len = strlen(str);
	
	char tmp;
	for (int i = 0; i < len/2; i++) {
		int j = 4-i;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	
}
int main(void) {
	char str[] = "hello";
	printf("before : %s ", str);
	Reverse(str);
	
	printf("after : %s", str);
	getchar(); 
}