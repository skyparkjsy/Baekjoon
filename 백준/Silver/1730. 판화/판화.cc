#include <iostream>
#include <string>
#if 01
using namespace std;
int N;
int arr[10 + 1][10 + 1];
string s;
string s_ans = ".|-+"; 
int r, c;
int main(void) {
	cin >> N >> s;
	for (int i = 0; s[i] != NULL; ++i) {
		switch (s[i]) {
		// 행 이동 (set bit[1])
		case 'U':
			if (r - 1 < 0) break;
			arr[r][c] |= 1; // 현재 위치
			arr[--r][c] |= 1; // 이동할 위치
			break;
		case 'D':
			if (r + 1 >= N) break;
			arr[r][c] |= 1;
			arr[++r][c] |= 1;
			break;
		// 열 이동 (set bit[2])
		case 'L':
			if (c - 1 < 0) break;
			arr[r][c] |= 2;
			arr[r][--c] |= 2;
			break;
		case 'R':
			if (c + 1 >= N) break;
			arr[r][c] |= 2;
			arr[r][++c] |= 2;
			break;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << s_ans[arr[i][j]];
		}
		cout << '\n';
	}
	return 0;
}
#endif