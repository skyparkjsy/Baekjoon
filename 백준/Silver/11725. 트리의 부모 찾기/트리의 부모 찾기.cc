#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

//b11725. 트리의 부모 찾기
// bfs 풀이 추가.
#if 01
using namespace std;
#define MAX_N (100000)
int N;
set<int> s;
vector<int> adj[MAX_N + 1];
int parent[MAX_N + 1];
int v[MAX_N + 1];
void dfs(int n, int prev);
void bfs(void) {
	queue<int> q;
	int curr;
	q.push(1);
	v[1] = 1;

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (int next : adj[curr]) {
			if (v[next] != 0) continue;
			v[next] = curr; // visited 배열에 직전 노드(부모노드 번호) 저장
			q.push(next);

		}
	}
	for (int i = 2; i <= N; ++i) {
		cout << v[i] << '\n';
	}
}
int main(void) {
	int a, b;
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//dfs(1, 1);
	bfs();

	return 0;
}

void dfs(int n, int prev) {
	if (s.size() == N) {
		// 부모노드 print
		for (int i = 2; i <= N; ++i) {
			cout << parent[i] << '\n';
		}
		return;
	}

	// adj[n] 꺼 다 꺼내기
	for (int i : adj[n]) {
		auto temp = s.find(i);
		if (temp == s.end()) {
			parent[i] = n;
			s.insert(i);
			dfs(i, n);
		}

	}

}
#endif
