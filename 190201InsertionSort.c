#include<stdio.h>
int main(void) {
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int i, j, tmp;
	for (int t = 0; t < 10; t++) {
		printf("%d ", arr[t]);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		j = i;
		while (arr[j] > arr[j + 1]) {
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;

			j--;
		}
		for (int t = 0; t < 10; t++) {
			printf("%d ", arr[t]);
		}
		printf("\n");
	}
	return 0;
}

/*
=>10+9+8+7..+2+1
=>O(N^2)
실제로는 연산횟수가 가장적어서 빠름
*/
