#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// b1260. DFS와 BFS
#define MAX_N (1000+1)

int case_n = 1; // 테스트 케이스 개수
int N; //정점 개수
int M; // 간선 개수 
int V; // 탐색 시작할 정점 번호

int arr[MAX_N][MAX_N]; // 연결이 표시된 배열
int arrIndex[MAX_N]; // 저장 위치 나타내는 인덱스
int visited[MAX_N]; // 방문 표시 배열

int BFSarr[MAX_N]; // bfs 탐색결과 저장 배열
int dfsIndex, bfsIndex; // 저장 위치 나타내는 인덱스

int queue[MAX_N];
int rear, front;


void print_arr(void);
void update_arr(int v1, int v2);
void set_data(void);
void print_arr1(int* arr1, int size);

void recursion(int vertex);
void solve_dfs(void);

void EnQueue(int data);
int DeQueue(void);
void solve_bfs(void);


int main(void) {
	if (0) {
		(void)freopen("b1260.txt", "r", stdin);
		(void)scanf("%d", &case_n);
	}
	for (int i = 0; i < case_n; ++i) {
		set_data();
		//print_arr();
		solve_dfs();
		printf("\n");
		solve_bfs();
		if (case_n != 1) printf("\n");
	}

	return 0;
}

// arr 프린트 (테스트용)
void print_arr(void) {
	for (int i = 0; i < 10; ++i) {
		printf("[%d] ", i);
		for (int j = 0; j < 10; ++j) {
			if (j == 0) printf("(%d) ", arr[i][j]);
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// arr 업데이트
void update_arr(int v1, int v2) {
	// 연결된 정점개수 업데이트
	++arr[v1][0];
	++arr[v2][0];
	// 저장할 위치 (인덱스) 업데이트
	++arrIndex[v1];
	++arrIndex[v2];
	// 연결된 정점 저장
	arr[v1][arrIndex[v1]] = v2;
	arr[v2][arrIndex[v2]] = v1;
}

int comp_int(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

// 입력 받아서 세팅
void set_data(void) {
	int v1, v2;
	(void)scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < MAX_N; ++i) {
		visited[i] = 0;
		arrIndex[i] = 0;
		for (int j = 0; j < MAX_N; ++j) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < M; ++i) {
		(void)scanf("%d %d", &v1, &v2); // 연결된 정점 v1, v2
		update_arr(v1, v2);
	}
	for (int i = 1; i <= N; ++i) {
		qsort(arr[i] + 1, arrIndex[i], sizeof(arr[i][0]), comp_int);
	}
}

void print_arr1(int* arr1, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

// DFS 
void recursion(int vertex) {
	if (vertex == 0) {
		return;
	}
	for (int i = 1; i <= arr[vertex][0]; ++i) {
		//printf("\nvertex:%d / i: %d\n", vertex, i);
		if (visited[arr[vertex][i]]) { //printf("check arr[%d][%d], visited[%d]\n", vertex, i, arr[vertex][i]); 
			continue; }

		visited[arr[vertex][i]] = 1;
		printf("%d ", arr[vertex][i]);
		recursion(arr[vertex][i]);
	}
}
void solve_dfs(void) {
	printf("%d ", V);
	visited[V] = 1;
	recursion(V);
}

//BFS
void EnQueue(int data) {
	printf("%d ", data);
	queue[rear++] = data;
}
int DeQueue(void) {
	return queue[front++];
}

void solve_bfs(void) {
	for (int i = 0; i < MAX_N; ++i) {
		visited[i] = 0;
		arrIndex[i] = 0;
	}
	rear = front = 0;
	EnQueue(V);
	visited[V] = 1;
	int curr;
	while (rear != front) {
		curr = DeQueue();
		for (int i = 1; i <= arr[curr][0]; ++i) {
			if (visited[arr[curr][i]]) { continue; }
			EnQueue(arr[curr][i]);
			visited[arr[curr][i]] = 1;
		}
	}
}