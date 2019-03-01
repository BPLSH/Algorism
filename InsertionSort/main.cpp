//Insertionsort

#include <stdio.h>
#include <string.h>

void InsertionSort(int *ptr, int len) {
	int i, j, tmp;

	for (i = 1; i < len; i++) {
		for (j = 0; j < i; j++) {
			if (ptr[i] < ptr[j]) {
				tmp = ptr[i];

				memmove(&ptr[j+1], &ptr[j], (i - j) * sizeof(ptr[0]));
				ptr[j] = tmp;
			}
		}
	}
}
void PrintArr(int* ptr, int len) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");
}
int main(void) {
	int arr[] = { 5,2,10,8,3,1,9,7,6,4 };
	int len = sizeof(arr) / sizeof(arr[0]);

	printf("before sort : ");
	PrintArr(arr, len);

	InsertionSort(arr, len);
	printf("after sort : ");
	PrintArr(arr, len);

	getchar();

	return 0;
}
