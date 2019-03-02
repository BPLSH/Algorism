#include<stdio.h>
int Partition(int *ptr, int start, int end) {
	int p = start; //pivot = ptr의 첫번째 인덱스
	int tmp = 0;
	++start;
	
	while (start <= end) {
		while (ptr[start] < ptr[p] && start <= end) {
			++start;
		}
		while (ptr[end] > ptr[p]) {
			--end;
		}
		if (start < end) {
			tmp = ptr[start];
			ptr[start] = ptr[end];
			ptr[end] = tmp;

			++start;
			--end;
		}
	}

	tmp = ptr[end];
	ptr[end] = ptr[p];
	ptr[p] = tmp;

	return end;
}
void QuickSort(int *ptr, int start, int end) {
	
	if (start < end) {
		int p = Partition(ptr, start, end);

		QuickSort(ptr, start, p - 1);
		QuickSort(ptr, p + 1, end);
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

	QuickSort(arr, 0, len-1);
	printf("after sort : ");
	PrintArr(arr, len);

	getchar();

	return 0;
}