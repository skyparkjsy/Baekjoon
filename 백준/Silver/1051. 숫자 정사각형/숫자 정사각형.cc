#include <iostream>
#include <algorithm>
#include <string>
#if 01
using namespace std;
int N, M, l;
int arr[55][55];

void input_arr(void) {
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < M; ++j) {
			arr[i][j] = s[j] - '0';
		}
	}
}
int solve(void) {
	int max_len = min(N, M);
	for (int len = max_len; len > 1; --len) {
		for (int i = 0; i < N - len + 1; ++i) {
			for (int j = 0; j < M - len + 1; ++j) {
				if ((arr[i][j] == arr[i + len - 1][j]) && (arr[i][j] == arr[i][j + len - 1]) && (arr[i][j] == arr[i + len - 1][j + len - 1])) {
					return (len*len);
				}
			}
		}
	}
	return 1;
}
int main(void) {
	cin >> N >> M;
	input_arr();
	cout << solve();
	return 0;
}

#endif