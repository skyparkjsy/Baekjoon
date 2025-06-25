#include <iostream>
// b10163. 색종이 (가리기 - 면적)
#if 01
using namespace std;
#define MAX_X (1001)
#define MAX_N (100)
int N; // 색종이 장수
int arr[MAX_X][MAX_X];
int area[MAX_N + 1];

int main(void) {
	int x, y, a, b;
	cin >> N;
	for (int n = 1; n <= N; ++n) {
		// 왼쪽 아래 (x, y) 좌표 , 너비(x), 높이(y)
		cin >> x >> y >> a >> b;
		for (int cx = x; cx < x + a; ++cx) {
			for (int cy = y; cy < y + b; ++cy) {
				arr[cy][cx] = n;
			}
		}
	}


	for (int i = 0; i < MAX_X; ++i) {
		for (int j = 0; j < MAX_X; ++j) {
			area[arr[i][j]]++;
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << area[i] << '\n';
	}
}
#endif