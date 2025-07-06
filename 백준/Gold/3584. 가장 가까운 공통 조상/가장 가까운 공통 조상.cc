#include <iostream>
#include <queue>
#include <vector>
#include <set>

#if 01
using namespace std;
int N, T;
vector<int> adj[10000 + 1]; // parent 인접리스트
set<int> s1;
set<int> s2;
int solve(int n1, int n2) {
	for (int i : s1) {
		if (i == n2) return n2;
	}
	for (int i : s2) {
		if (i == n1) return n1;
	}
	for (int i : s1) {
		for (int j : s2) {
			if (i == j) return i;
		}
	}

	if (n1 == n2) return n1;
	return -1;
}
int main(void) {
	int a, b, n1, n2;
	int parent;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		for (int j = 0; j < N - 1; ++j) {
			cin >> a >> b; // a가 b의 부모
			adj[b].push_back(a);
		}

		cin >> n1 >> n2; // 공통 조상 구할 노드들
		int child = n1;
		while (!adj[child].empty()) {
			parent = adj[child].back();
			adj[child].pop_back();
			s1.insert(parent); // set에 넣기
			child = parent;
		}
		child = n2;
		while (!adj[child].empty()) {
			parent = adj[child].back();
			adj[child].pop_back();
			s2.insert(parent); // set에 넣기
			child = parent;
		}

		cout << solve(n1, n2) << '\n';

		// 인접 리스트 초기화해주기
		for (int j = 1; j <= N; ++j) {
			adj[j].clear();
			s1.clear();
			s2.clear();
		}
	}

}
#endif