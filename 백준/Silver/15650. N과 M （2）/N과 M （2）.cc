#include <iostream>
#if 01
using namespace std;

int arr[8 + 1];
int N, M;
void dfs(int n, int start) { // 고른 개수 n, 시작 start
	if (n == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= N; ++i) {
		arr[n] = i;
		dfs(n + 1, i + 1);
	}
}
int main(void) {
	cin >> N >> M;
	dfs(0, 1);
}
#endif