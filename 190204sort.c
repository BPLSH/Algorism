//bubblesort
#include <stdio.h>
#define max 1000
void Selectionsort(int* arr, int start, int end) {
//선택정렬
//비교해서 가장 작은 것을 앞으로 보내면서 앞부터 채우는 정렬
	int i, j, min, tmp;

	for (i = 0; i < end; i++) {
		min = i;
		for (j = i + 1; j <= end; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
	
}
void Bubblesort(int* arr, int start, int end) { 
//버블정렬
//전후를 비교하여 순차적으로 뒤에부터 채우는 정렬
	int i, j, tmp;

	for (i = 0; i < end; i++) {
		for (j = 0; j < end - i; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void Insertionsort(int* arr, int start, int end) {
//삽입정렬
//순차적으로 적절한 위치에 삽입
//삽입이라고하면 어려우니 교환
	int i, j, tmp;

	for (i = 1; i <= end; i++) {
		for (j = i; j>0; j--) {
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}
void fpQuicksort(int* arr, int start, int end) {
//pivot이 맨 앞
//pivot을 기준으로 작은 값은 앞으로, 큰 값은 뒤로
//재귀
	int i = start + 1;
	int j = end; 
	int p = start;
	int	tmp;

	if (start > end) {
		return;
	}
	while (i < j) {
		while (arr[i] < arr[p]) {
			i++; //왜 무한루프안돌지?
		}
		while (arr[j] > arr[p]) {
			j--; //왜 무한루프안돌지?
		}
		if (i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		else {
			tmp = arr[j];
			arr[j] = arr[p];
			arr[p] = tmp;
		}
	}
	fpQuicksort(arr, start, j - 1);
	fpQuicksort(arr, j + 1, end);
}
void mpQuicksort(int* arr, int start, int end) {
//pivot이 가운데
//pivot을 기준으로 작은 값은 앞으로, 큰 값은 뒤로
//재귀
	int i = start + 1;
	int j = end;
	int p = start;
	int	tmp;

	
}
void rpQuicksort(int* arr, int start, int end) {
//pivot이 맨뒤
//pivot을 기준으로 작은 값은 앞으로, 큰 값은 뒤로
//재귀
	int i = start;
	int j = end-1;
	int p = end;
	int	tmp;

	if (start>end) {
		return;
	}
	while (i < j) {
		while (arr[i] < arr[p]) {
			i++;
		}
		while (arr[j] > arr[p]) {
			j--;
		}
		if (i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		else {
			tmp = arr[i];
			arr[i] = arr[p];
			arr[p] = tmp;
		}
	}
	rpQuicksort(arr, start, i - 1);
	rpQuicksort(arr, i + 1, end);
}
int sorted[max] = { 0 };
void Mergesort(int* arr, int start, int end) {
//일단 개별로 나누고
// 2^i 개로 합친다음 sorted에 대입한후
// arr에 대입
	int i, j, tmp, mid;
	while()
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
	Mergesort(arr, 0, num - 1);

	for (t = 0; t < num; t++) {
		printf("%d ", arr[t]);
	}
	return 0;
}
