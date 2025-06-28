#include <iostream>
#include <queue>
using namespace std;
//b16953. A->B
#if 01
#define MAX_N (1000000000)
int a, b;
struct node {
	long long val;
	int cnt;
};

void bfs(int num) {
	queue<node> q;
	node curr;
	int ans = 0;
	q.push({ num, 1 });

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr.val == b) {
			ans = curr.cnt;
			break;
		}
		if (curr.val > b) continue;
		q.push({ curr.val * 2, curr.cnt + 1 });
		q.push({ curr.val * 10 + 1, curr.cnt + 1 });
	}
	if (ans == 0) cout << -1;
	else cout << ans;
}
int main(void) {
	cin >> a >> b;
	bfs(a);

	return 0;
}
#endif