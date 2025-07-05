#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
//b21735. 눈덩이 굴리기
#if 01
using namespace std;
#define MAX_N (100)
int N, M;
int a[MAX_N + 1];
int max_val = INT_MIN;
void dfs(int n, int size, int time) { // n : 눈덩이가 위치할 칸
	if (n == N || time == M) {
		max_val = max(size, max_val);
		return;
	}

	if (time+1 <= M) {
		if(n+1 <= N) dfs(n + 1, size + a[n + 1], time + 1);
		if(n+2 <= N) dfs(n + 2, size / 2 + a[n + 2], time + 1);
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> a[i];
	}
	dfs(0, 1, 0);
	cout << max_val << '\n';
	return 0;
}
#endif