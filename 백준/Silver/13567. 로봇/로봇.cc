#include <iostream>
#include <string>
// b13567. 로봇
#if 01
using namespace std;
int M, n; // 한변길이, 명령어 개수
int arr[1000 + 1][1000 + 1];
int d; // MOVE d

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int cr = 0, cc = 0;
int dir = 1;
int nr, nc;

void input(void) {
	cin >> M >> n;
}

void turn(void) {
	if (d == 1) dir = (dir + 1) % 4; // 오른쪽 90도
	else {// 왼쪽 90도
		if (dir == 0) dir = 3;
		else dir = dir - 1;
	}
}

int move(void) {
	nr = cr + d * dr[dir];
	nc = cc + d * dc[dir];
	if (nr < 0 || nr > M || nc < 0 || nc > M) return -1;
	cr = nr;
	cc = nc;
	return 1;
	// 범위 밖이면 return -1;
}

int main(void) {
	string str;
	input();
	for (int i = 0; i < n; ++i) {
		cin >> str;
		cin >> d;

		if (str == "TURN") turn();
		else if (str == "MOVE") {
			if (move() == -1) {
				cout << -1;
				return 0;
			}
		}

	}
	cout << cc << ' ' << cr << '\n';
	return 0;
}
#endif