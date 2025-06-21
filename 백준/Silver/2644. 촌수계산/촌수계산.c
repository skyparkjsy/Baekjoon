#pragma warning(disable:4996)
#include <stdio.h>
//b2644. 촌수 계산 https://www.acmicpc.net/problem/2644
#if 01
int n; // 전체 사람 수
int s; // 시작 번호
int d; // 목적지 번호

int front, rear;
typedef struct mystruct {
	int node;
	int cnt;
}mystruct_t;
mystruct_t queue[1000];
int arr[101][101];
int v[101];

void enqueue(int node, int cnt) {
	queue[rear].cnt = cnt;
	queue[rear++].node = node;
}

mystruct_t dequeue(void) {
	return queue[front++];
}
int bfs(void) {
	// 1. 생성
	int cnt = 0;
	int min = 100;
	mystruct_t curr;
	front = rear = 0;

	// 2. 단위 작업
	// 예외 경우
	if (arr[s][1] == 0) return -1;
	for (int i = 1; i <= arr[s][0]; ++i) {
		if (arr[s][i] == d) return 1;
	}
	// 초기
	v[s] = 1;
	enqueue(s, 0);

	// 3. 큐에 데이터 있는 동안
	while (front != rear) {
		curr = dequeue(); // 꺼내기
		for (int i = 1; i <= arr[curr.node][0]; ++i) {
			if (v[arr[curr.node][i]] != 0 && v[arr[curr.node][i]] < curr.cnt + 1) continue;
			enqueue(arr[curr.node][i], curr.cnt+1);

			v[arr[curr.node][i]] = curr.cnt+1; // 방문 표시
			if (v[d] > 0) { // 방문 되었으면 최소 촌수 구하기
				min = (curr.cnt + 1 < min) ? curr.cnt + 1 : min;
			}
		}
	}
	if (v[d] == 0) return -1;
	return min;
}
void input_arr(void) {
	int a, b, num;
	(void)scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		(void)scanf("%d %d", &a, &b);
		arr[a][0]++;
		arr[b][0]++;
		arr[a][arr[a][0]] = b;
		arr[b][arr[b][0]] = a;
	}
}

int main(void) {
	int ans;
	(void)scanf("%d %d %d", &n, &s, &d);
	input_arr();
	printf("%d\n", bfs());
	return 0;
}

#endif