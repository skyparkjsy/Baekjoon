#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (101)
int N;
int connect_n;
int(*pc)[MAX_N];
int* queue;
int* check;
int front, rear;

void init(void);
void set_pcarray(void);
void push(int* queue, int c);
int pop(int* queue);
void destroy(void);
int cnt_virus(void);


int main(void) {
	//(void)freopen("b2606.txt", "r", stdin);
	(void)scanf("%d", &N);
	init();
	set_pcarray();
	printf("%d\n", cnt_virus());
	destroy();
	return 0;
}

void init(void) {
	pc = (int(*)[MAX_N])calloc(N + 1, sizeof(int[MAX_N]));
	queue = (int*)calloc(N * N, sizeof(int));
	check = (int*)calloc(N + 1, sizeof(int));
	if (pc == NULL || check == NULL) {
		printf("메모리 할당 오류\n");
		return;
	}
	return;
}

void set_pcarray(void) {
	int a, b;
	(void)scanf("%d", &connect_n);
	for (int i = 1; i <= connect_n; ++i) {
		(void)scanf("%d %d", &a, &b);
		pc[a][b] = 1;
		pc[b][a] = 1;
	}
}


int cnt_virus(void) {
	int PC1 = 1;
	int PC2 = 2;
	int LASTPC = N;
	int cnt;
	int nextPC;
	front = rear = 0;
	cnt = 0;

	push(queue, PC1);
	while (front < rear) {
		nextPC = pop(queue);
		if (!check[nextPC]) {
			check[nextPC] = 1;
			++cnt;
		}
		for (int i = PC2; i <= LASTPC; ++i) {
			if (pc[nextPC][i] == 1) {
				push(queue, i);
				pc[nextPC][i] += 1;
			}
		}
	}
	return cnt - 1;
}

void push(int* queue, int c) {
	queue[rear++] = c;
}
int pop(int* queue) {
	return queue[front++];
}

void destroy(void) {
	free(pc);
	free(queue);
	free(check);
}

#endif