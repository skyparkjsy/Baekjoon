#include <iostream>
#include <queue>
//b5014. 스타트링크
#if 01
using namespace std;
#define MAX_FLOOR (1000000)
int F; // 전체 층 수
int S; // 현재 위치
int G; // 목표 층
int U; // 위로 
int D; // 아래로
int v[MAX_FLOOR+1];

void bfs(void) {
	queue<int> q;
	int step = 0;
	int c = S;
	q.push(S);
	v[S] = 1;
	while (!q.empty()) {
		int len = q.size();
		for (int t = 0; t < len; ++t) { // 큐에 들어있는 것 모두 
			// 여기 반복문 내에서 q.size 하면 바뀔 수 있음.. 실수..! 위에서 len = q.size()해주기
			c = q.front();
			q.pop();
			if (c == G) {
				
				cout << step;
				return;
			}
			for (int i : {c + U, c - D}) {
				if (i < 1 || i > F || v[i] != 0) continue;
				q.push(i);
				v[i] = 1;
			}
		}
		step++;

	}

	cout << "use the stairs\n";
	return;

}


int main(void) {
	cin >> F >> S >> G >> U >> D;
	bfs();
	return 0;
}
#endif