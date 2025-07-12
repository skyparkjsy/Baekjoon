#include <iostream>
// b1913. 달팽이
#if 01
using namespace std;
int N, M;
int arr[1000 + 1][1000 + 1];
int ans_r, ans_c;

// 방향: 하 우 상 좌
int dir = 0; // 초기 방향: 아래
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void input(void) {
	cin >> N; 
	cin >> M; // 찾을 자연수
}

void solve(void) {
	// 맨 왼쪽 위 좌표를 (0,0)으로
	int cr = 0, cc = 0; 
	int nr, nc;
	// 시작은 맨 왼쪽 위부터
	for (int n = N * N; n >= 1; --n) {
		// 다음 좌표 계산
		arr[cr][cc] = n;

		// 찾는 자연수인지 체크
		if (n == M) {
			ans_r = cr;
			ans_c = cc;
		}
		nr = cr + dr[dir];
		nc = cc + dc[dir];
		
		// 범위 밖 또는 값이 있으면 -> 방향 바꾸기
		if (nr < 0 || nr >= N || nc < 0 || nc >= N || arr[nr][nc] != 0) {
			dir = (dir + 1) % 4;
			cr = cr + dr[dir];
			cc = cc + dc[dir];
		}
		else {
			cr = nr;
			cc = nc;
		}
		
	}
}
int main(void) {
	input();
	solve();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans_r + 1 << ' ' << ans_c + 1<< '\n';
	return 0;
}
#endif