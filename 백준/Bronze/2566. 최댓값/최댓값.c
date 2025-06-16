#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
// b2566. 최댓값
/*

*/
#if 01
#define ARR_SIZE (9+1)

int arr[ARR_SIZE][ARR_SIZE];

void input_arr(void) {
	for (int i = 1; i < ARR_SIZE; ++i) {
		for (int j = 1; j < ARR_SIZE; ++j) {
			(void)scanf("%d", arr[i] + j);
		}
	}
}
void solve(void) {
	int max = -1;
	int max_r = 1, max_c = 1;
	for (int i = 1; i < ARR_SIZE; ++i) {
		for (int j = 1; j < ARR_SIZE; ++j) {
			if (max < arr[i][j]) {
				//printf("arr[%d][%d] %d\n", i, j, arr[i][j]);
				max = arr[i][j];
				max_r = i;
				max_c = j;
			}
		}
	}
	printf("%d\n%d %d", max, max_r, max_c);
}
int main(void) {
	//(void)freopen("b2566.txt", "r", stdin);
	input_arr();
	solve();
	return 0;
}

#endif