#pragma warning(disable:4996)
#include <stdio.h>
// 8320
#if 01
int main(void) {
	int n;
	int cnt = 0;
	(void)scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (i * j <= n) cnt++;
			else break;
		}
	}
	printf("%d\n", cnt);
}
#endif