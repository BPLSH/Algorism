#include<stdio.h>

int main(void) {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, t, min, tmp, index = 0;
	for (i = 0; i<10 ;i++) {
		min = arr[i];
		for (j = i+1; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		//tmp = arr[i];
		//arr[i] = arr[index];
		//arr[index] = tmp;

		arr[index] = arr[i];
		arr[i] = min;
		printf("\n");
		printf("결과:");
		for (t = 0; t < 10; t++) {
			printf("%d ", arr[t]);
		}
		printf("\n");
	}
}
