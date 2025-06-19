#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

// b1010. 다리놓기

/*
	조합 - MCN 구하기 (M개 중 N개 선택만 하면 됨)
*/

#if 01
#define MAX_N (30+1)
int T;
int N, M;

long double factorial(long double n) {
	if (n <= 1.0) {
		return 1.0;
	}
	return (n * factorial(n - 1));
}

void solve(void) {
	printf("%.0Lf\n", factorial(M) / (factorial(N) * factorial(M - N)));
}

int main(void) {
	//(void)freopen("b1010.txt", "r", stdin);
	(void)scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		(void)scanf("%d %d", &N, &M);
		solve();
	}
	return 0;
}

#endif