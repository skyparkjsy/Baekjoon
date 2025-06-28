#include <iostream>
#include <algorithm>
#include <string.h>

#if 01
using namespace std;
#define MAX_N (8)
#define MAX_M (8)
int N, M;
int ans[MAX_M+1];
int v[MAX_N + 1];
void dfs(int n) {
	// [1] 종료조건
	if (n == M) {
		// 정답 관련 처리
		for (int j = 0; j < M; ++j) cout << ans[j] << " ";
		cout << '\n';
		return;
	}
	
	// [2] 하부함수 호출 (재귀)
	for (int j = 1; j <= N; ++j) {
		// 이미 사용한 숫자인 경우 사용하지 않음.
		if (v[j] != 0) continue;
		ans[n] = j;
		v[j] = 1; // 세 줄 쌍으로
		dfs(n+1);
		v[j] = 0; 
	}

}
int main(void) {
	cin >> N >> M;
	dfs(0);

	return 0;
}

#endif