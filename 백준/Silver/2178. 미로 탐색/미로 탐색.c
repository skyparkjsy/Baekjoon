#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
// b2178. 미로 탐색 (250426)
/* 타임라인 */
// 21:31 입력 구현 / 10분 휴식
// 22:13 테스트 
#if 01
#define MAX_N (100+1)
int testcase_n = 1;
int N, M;
char* inputStr;
int mazeArr[MAX_N][MAX_N];

typedef struct queue{
	int r;
	int c;
}queue_t;

queue_t queue[MAX_N * MAX_N];
int rear, front;

void set_mazeArr(void) {
	inputStr = (char*)calloc(M + 1, sizeof(char));
	if (inputStr == NULL) {
		exit(1);
	}
	for (int i = 1; i <= N; ++i) {
		(void)scanf("%s", inputStr);
		for (int j = 1; j <= M; ++j) {
			mazeArr[i][j] = *(inputStr + j - 1) - '0';
		}
	}
}
void print_mazeArr(void) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			printf("%d", mazeArr[i][j]);
		}
		printf("\n");
	}
}
void destroy_inputStr(void) {
	free(inputStr);
	inputStr = 0;
}

void EnQueue(int r, int c) {
	queue[rear].r = r;
	queue[rear++].c = c;
}
queue_t DeQueue(void) {
	return queue[front++];
}
void init_var(void) {
	rear = front = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			mazeArr[i][j] = 0;
		}
	}
	destroy_inputStr();
}

int check_range(int nr, int nc) {
	return (nr <= 0 || nc <= 0 || nr > N || nc > M);
}

void solve_maze(void) {
	queue_t curr;
	int nr, nc;
	int currArrVal; 
	int dr[4] = { 0, -1, 0, 1 };
	int dc[4] = { -1, 0, 1, 0 };
	
	EnQueue(1, 1);
	mazeArr[1][1] = 2;
	while (front != rear) {
		curr = DeQueue();
		currArrVal = mazeArr[curr.r][curr.c];
		for (int i = 0; i < 4; ++i) {
			nr = curr.r + dr[i];
			nc = curr.c + dc[i];
			if (check_range(nr, nc) || mazeArr[nr][nc] != 1) {
				continue;
			}
			EnQueue(nr, nc);
			mazeArr[nr][nc] = currArrVal + 1;
			if ((nr == N) && (nc == M)) {
				printf("%d\n", mazeArr[nr][nc] - 1);
				return;
			}
		}
	}
	printf("이상 종료\n");
	return;
}
int main(void) {
	if (0) {
		(void)freopen("b2178.txt", "r", stdin);
		(void)scanf("%d", &testcase_n);
	}
	for (int _ = 0; _ < testcase_n; ++_) {
		(void)scanf("%d %d", &N, &M);
		init_var();
		set_mazeArr();
		//print_mazeArr();
		solve_maze();
	}
	return 0;
}
#endif