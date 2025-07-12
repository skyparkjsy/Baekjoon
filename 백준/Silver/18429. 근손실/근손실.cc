#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

//b18429. 근손실
#if 01
using namespace std;
#define MAX_K (50)
int N;
int K;
int kit[MAX_K+1];
int v[MAX_K + 1];
int ans;
void dfs(int n, int power) {
	if (n == N) {
		if (power >= 500) ans++;
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (v[i] || power - K + kit[i] < 500) continue;
		v[i] = 1;
		dfs(n + 1, power - K + kit[i]);
		v[i] = 0;
	}
}
int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> kit[i];
	}
	dfs(0, 500);
	cout << ans << '\n';
	return 0;
}
#endif