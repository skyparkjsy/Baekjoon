#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
	N장의 카드
	M을 넘지 않으면서, M과 최대한 가깝게
	배열 입력받아서, 오름차순으로 정렬 // 수정 - 정렬 안 해도 됨

	3장의 합 구하기
	0 1 2
	0 1 3
	... 가면서 다 더하고, 
	합한 값이 M보다 작으면서 차이가 가장 적을 때 계속 best를 업데이트.
	다 탐색 후 best 출력
*/
#if 01
#define MAX_N (100)

int N, M;
int* arr;
int* visited;
int best = 0;


void input_arr(void) {
	arr = (int*)malloc(N * sizeof(int));
	visited = (int*)calloc(N, N * sizeof(int));
	if (arr == NULL) {
		exit(1);
	}
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", arr + i);
	}
}

void recur(int L, int start, int sum) {
	if (L >= 3) {
		if (sum <= M && sum > best) {
			best = sum;
		}
		return;
	}
	for (int i = start; i < N; ++i) {
		recur(L + 1, i+1,  sum + arr[i]);
	}

}
void solve(void) {
	recur(0, 0, 0);
	printf("%d\n", best);
}

void print_arr(void) {
	for (int i = 0; i < N; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	//(void)freopen("b2798.txt", "r", stdin);
	(void)scanf("%d %d", &N, &M);
	input_arr();
	solve();
	return 0;
}
#endif