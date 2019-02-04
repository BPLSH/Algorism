void quicksort(int *arr, int start, int end) {
	int i = start+1, j = end, tmp;
	int key = start;
	if (start >= end) {
		return;
	}
	while (i <= j) {
		while (arr[i] <= arr[key]) {
			i++;
		}
		while (arr[j] >= arr[key] && j > start) {
			j--;
		}
		if (i > j) {
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
		else {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end);
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
	quicksort(arr, 0, num - 1);
	
	for (t = 0; t < num; t++) {
		printf("%d ", arr[t]);
	}

	return 0;
}
