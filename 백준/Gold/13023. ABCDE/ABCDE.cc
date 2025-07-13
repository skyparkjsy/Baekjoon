#include <iostream>
#include <vector>
#include <cstring>

// b13023. ABCDE
#if 01
using namespace std;

// b13023. ABCDE
int N, M; // 사람 수, 친구관계 수
vector<int> adj[2000 + 1]; // 번호별 친구 리스트
int v[2000 + 1];
int ans;

void dfs(int n, int node) { // n: 연결된 사람 수
	if (ans) return;
	if (n >= 5) { // A-B-C-D-E 총 5명 연결되면 성공
		ans = 1;
		return;
	}

	// node의 친구 찾기
	for (int next : adj[node]) {
		if (v[next] == 0) {
			v[next] = 1;
			dfs(n + 1, next);
			v[next] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a); // 양방향 
	}

	for (int i = 0; i < N; ++i) {
		memset(v, 0, sizeof(v));
		v[i] = 1;
		dfs(1, i); // n(나는 연결되어 있으니깐 1부터 시작), 번호
		if (ans) break;
	}

	cout << ans << '\n';
	return 0;
}

#endif