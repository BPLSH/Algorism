//bubblesort

#include <stdio.h>
void BubbleSort(int *ptr, int len) {
	int i, j, tmp;

	for (i = 0; i < (len - 1); i++) {
		for (j = 0; j < (len - 1) - i; j++) {
			if (ptr[j] > ptr[j + 1]) {
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
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

	BubbleSort(arr, len);
	printf("after srot : ");
	PrintArr(arr, len);

	getchar();

	return 0;
}
