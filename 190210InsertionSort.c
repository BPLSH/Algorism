#include<stdio.h>
void insertionSort(int *ptr, int len) {
	int i, j, tmp;

	for (i = 1; i < len; i++) {
		if (ptr[i - 1] < ptr[i]) {
			continue;
		}
		for (j = 0; j < i; j++) {
			if (ptr[i] < ptr[j]) {
				tmp = ptr[i];
				memmove(&ptr[j + 1], &ptr[j], sizeof(int)*(i - j));
				ptr[j] = tmp;
			}
		}
	}
}
int main(void) {
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(int);
	printf("before sort: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	insertionSort(arr, len);
	printf("after sort: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	

	return 0;
}

/*
arr[j=0]~arr[j=i-1]까지 arr[i]와 비교
if(arr[i] < arr[j])일 경우
i-j까지 데이터를 한칸씩 이동시킨다
arr[j] = arr[i]
데이터가 정렬되어있을경우 n-1로 가장 빠르다.
*/
