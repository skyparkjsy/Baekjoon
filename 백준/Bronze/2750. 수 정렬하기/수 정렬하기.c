#pragma warning(disable:4996)
#include <stdio.h>


// 2750
#if 01
int N;
int arr[1001];
int temp;
int main(void) {
	(void)scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", arr + i);
	}
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i; j < N; ++j) {
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		printf("%d\n", arr[i]);
	}
}
#endif