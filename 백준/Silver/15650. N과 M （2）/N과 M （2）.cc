#include <iostream>

// b15650. N과 M (2) - 백트래킹 - 가능한 모든 경우 
#if 01
using namespace std;

int N, M;
int cnt;
int arr[9];
void dfs(int n, int num, int valid) {
	if (n == M) {
		if (valid == 1) {
			for (int j = 0; j < M; ++j) {
				cout << arr[j] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (valid == 1 && i > num) {
			arr[n] = i;
			dfs(n + 1, i, 1);
		}
		else {
			dfs(n + 1, i, 0);
		}
	}
}
int main(void) {
	cin >> N >> M;
	dfs(0, 0, 1);
	return 0;
}

#endif