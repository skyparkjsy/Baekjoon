#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
//b2644. 촌수 계산
#if 01
#define MAX_N (100)
int n; // 전체 사람 수
int s, d;
int m; // 관계 개수
int arr[MAX_N + 1][MAX_N + 1];
int ans;
int v[MAX_N + 1];
int bfs(void) {
	queue<int> q;
	int curr;

	q.push(s);
	v[s] = 0;

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr == d) {
			return v[curr];
		}
		for (int i = 1; i <= n; ++i) {
			if (arr[curr][i] == 0) continue;
			if (v[i] != 0) continue;
			q.push(i);
			v[i] = v[curr] + 1;
		}
	}
	return -1;
}
int main(void) {
	int a, b;
	cin >> n >> s >> d >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	cout << bfs();
}
#endif
