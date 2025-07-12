#include <iostream>
// b1913. 달팽이

using namespace std;
int N, M;
int arr[1000 + 1][1000 + 1];

// 상 우 하 좌
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int dir = 0; // 초기: 상
int cnt = 0;
int max_cnt = 1; // 초기: 1
int flag = 0;
int cr, cc, nr, nc;
int find_r, find_c;

void input(void) {
	cin >> N >> M;
}

void solve(void){
	cr = N / 2;
	cc = N / 2;

	for (int i = 1; i <= N * N; ++i) {
		if (i == M) {
			// 좌표 offset 맞춰주기
			find_r = cr + 1;
			find_c = cc + 1;
		}
		arr[cr][cc] = i;
		nr = cr + dr[dir];
		nc = cc + dc[dir];

		if (++cnt == max_cnt) {
			// 방향 전환
			dir = (dir + 1) % 4;
			cnt = 0;

			// max_cnt update
			if (flag == 1) {
				flag = 0;
				max_cnt++;
			}
			else flag = 1;
		}

		cr = nr;
		cc = nc;
	}
}

void output(void) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << find_r << ' ' << find_c << '\n';
}

int main(void) {
	input();
	solve();
	output();
	return 0;
}