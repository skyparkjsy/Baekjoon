#include <iostream>
#include <climits>
#include <algorithm>
//b28215. 대피소
#if 01
using namespace std;
int N, K;
struct node {
	int x;
	int y;
};
node house[50]; // 집 좌표
node shelter[3]; // 대피소 좌표
int min_dist; // 집과 대피소 거리
int max_val; // 최단거리들 중 최대
int ans = INT_MAX;

int is_shelter(int i) {
	// 대피소인지 검사
	for (int j = 0; j < K; ++j) {
		if ((house[i].x == shelter[j].x) && (house[i].y == shelter[j].y)) return 1;
	}
	return 0;
}

void dfs(int n, int start) { // n은 선택한 대피소 수
	if (n == K) {
		max_val = 0;
		// 모든 집에 대해, 가장 가까운 대피소 좌표
		for (int i = 0; i < N; ++i) { 
			if (is_shelter(i)) continue; // 이 집이 대피소면 continue
			min_dist = INT_MAX;
			// 대피소들 중 최단거리
			for (int j = 0; j < K; ++j) { 
				min_dist = min(min_dist, abs(house[i].x - shelter[j].x) + abs(house[i].y - shelter[j].y)); 
			}
			// 최단거리들 중 최대거리
			max_val = max(max_val, min_dist); 
		}
		ans = min(ans, max_val); // 정답 (최대거리가 최소일 때)
		return;
	}
	for (int i = start; i < N; ++i) {
		// 대피소 좌표 설정 (house[i]를 대피소로)
		shelter[n] = house[i];
		// 다음 대피소 선택 (i+1번째부터)
		dfs(n + 1, i + 1);
	}
}

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> house[i].x >> house[i].y;
	}
	dfs(0, 0); // n, start
	cout << ans << '\n';
	return 0;
}
#endif