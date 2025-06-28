#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
// b1325. 효율적인 해킹
#if 01
using namespace std;
#define MAX_N (10000)
int N; // 컴퓨터 개수
int M; // 신뢰 관계 수
vector<int> adj[MAX_N+1];
int cnt_arr[MAX_N + 1]; // 해킹할 수 있는 pc 수


void bfs(void) {
	queue<int> q;
	int v[MAX_N + 1];
	int curr;

	// 1번부터 N번까지 다 검사해보기
	for (int pc = 1; pc <= N; ++pc) {
		// visited 초기화
		memset(v, 0, sizeof(v));
		q.push(pc);
		v[pc] = 1;
		while (!q.empty()) {
			curr = q.front();
			q.pop();
			for (int n : adj[curr]) {
				if (v[n] != 0) continue;
				v[n] = 1;
				q.push(n);
				cnt_arr[pc]++;
			}
		}
	}
}
void print_ans(void) {
	vector<int> ans;
	int max = 0;
	for (int i = 1; i <= N; ++i) {
		if (max == cnt_arr[i]) {
			ans.push_back(i);
		}
		else if (max < cnt_arr[i]) {
			max = cnt_arr[i];
			ans.clear();
			ans.push_back(i);
		}
	}
	for (int i : ans) cout << i << ' ';
}
int main(void) {
	int a, b;
	cin >> N >> M;
	for (int _ = 0; _ < M; ++_) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	bfs();
	print_ans();
	return 0;
}
#endif