#pragma warning(disable:4996)
#include <stdio.h>

// b17127. 벚꽃 정보섬
/*
	DFS를 통해 모든 경우의 수 체크 (level, remain 넘겨주기)
	arr[1], arr[2], arr[3], arr[4]에 각 그룹 벚꽃나무 수를 대입
	level은 1부터 4까지 (그룹 번호)
	level이 4가 되면 arr[1]~arr[4] 보고 곱의 합 구해서, 
	max 값과 비교해 최댓값 change
*/
#if 01
#define MAX_N (10+1)

int N; // 벚꽃나무 수
int flower[MAX_N]; // 벚꽃나무 배열
int arr[5];
int max;

void input_arr(void) {
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", flower + i);
	}
}

int recur(int level, int remain) {
	if (level > 4) {
		int sum = 0, index = 0, mul = 1;
		for (int i = 1; i <= 4; ++i) {
			mul = 1;
			for (int j = index; j < index + arr[i]; ++j) {
				mul *= flower[j];
			}
			sum += mul;
			index += arr[i];
		}
		max = (sum > max) ? sum : max;
		return max;
	}

	for (int i = remain - (4 - level); i >= 1; --i) {
		arr[level] = i;
		recur(level + 1, remain - i);
	}

}

void print_arr(void) {
	for (int i = 0; i < N; ++i) {
		printf("%d ", flower[i]);
	}
	printf("\n");
}
void solve(void) {
	recur(1, N);
	printf("%d\n", max);
}
int main(void) {
	//(void)freopen("b17127.txt", "r", stdin);
	(void)scanf("%d", &N);
	input_arr();
	solve();
	return 0;
}

#endif