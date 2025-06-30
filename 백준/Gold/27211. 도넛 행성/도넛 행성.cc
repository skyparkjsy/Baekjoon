#include <iostream>
#include <queue>
#include <cstring>
//b27211. 도넛 행성
#if 01
using namespace std;
#define MAX_N (1000)
#define MAX_M (1000)
int N, M;
int arr[MAX_N + 1][MAX_M + 1];
int v[MAX_N + 1][MAX_M + 1];
typedef struct node {
	int r;
	int c;
}node;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
void bfs(int r, int c) {
	queue<node> q;
	node curr;
	int nr, nc;
	q.push({ r, c });
	v[r][c] = 1;

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			nr = (curr.r + dr[i] + N) % N;
			nc = (curr.c + dc[i] + M) % M;
			if (v[nr][nc] || arr[nr][nc]) continue;
			v[nr][nc] = 1;
			q.push({ nr, nc });

		}

	}
}
int main(void) {
	int region = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (arr[r][c] == 1) continue;
			if (v[r][c]) continue;
			bfs(r, c);
			region++;
		}
	}
	cout << region << '\n';
	return 0;
}

#endif