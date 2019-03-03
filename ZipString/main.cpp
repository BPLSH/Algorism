#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 127

char* Zip(const char* ptr) { //지역변수
	char * dptr = (char*)malloc(sizeof(char)*ASCII);

	int i = 0;
	char *str = (char*)malloc(sizeof(char)*ASCII);

	for (int i = 0; i < ASCII; i++) {
		printf("index : %d : %d\n", i,*(dptr + i));
	}
	while (*ptr) {
		int i = *ptr;
		*ptr++;
		dptr[i]++;

	}
	printf("-----------------\n");
	for (int i = 0; i < ASCII; i++) {
		printf("index : %d : %d\n", i, *(dptr + i));
	}

	return str;
}
int main(void) {
	char* zipMessage = Zip("aaabbbccc");
	//printf("%s", zipMessage);
	getchar();
	return 0;
}