#include <stdio.h>
//시간복잡도는 선택정렬과 동일하지만
//실제시간은 훨씬 느림(가장 느림)

int main(void) {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, r, tmp;
	//n-1번비교
	//n-2번비교
	for (i = 0; i < 9; i++) {
		for(j = 0; j < 9-i; j++)
		if (arr[j+1] < arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
		}
		for (r = 0; r < 10; r++) {
			printf("%d ", arr[r]);
		}
		printf("\n");
	}
}

=>10 + 9+ 8 + 7+...+ 2 + 1 
=>n*(n+1)/2
->O(n^2)
