//mergesort
#include<stdio.h>
#define max 1000
int sorted[max] = { 0 };
void merge(int *arr, int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;
	int t;
	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (t = j; t <= end; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else {
		for (t = i; t <= middle; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	for (t = start; t <= end; t++) {
		arr[t] = sorted[t];
	}
}
void mergesort(int *arr, int start, int end) {
	
	if (start < end) {
		int middle = (start + end) / 2;
		mergesort(arr, start, middle);
		mergesort(arr, middle+1, end);
		merge(arr, start, middle, end);
	}
}
int main(void) {
	int i, t, num;
	int arr[max] = { 0 };
	printf("개수를 입력하시오:");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("before sorting : ");
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	mergesort(arr, 0, num - 1);

	for (t = 0; t < num; t++) {
		printf("%d ", arr[t]);
	}
	return 0;
}
