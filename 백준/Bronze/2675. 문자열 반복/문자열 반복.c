#pragma warning(disable: 4996)
#include <stdio.h>

// b2675. 문자열 반복
#if 01
#define MAX_LEN (20+1)
#define MAX_T (1000)
#define MAX_R (8)
int T; // 테스트 케이스 수. 1<= T <= 1000
int R; // 반복 횟수 (1 <= R <= 8)
char S[MAX_T][MAX_LEN]; // 입력 문자열 배열. (적어도 1글자, 20글자 넘지 않음.)
char P[MAX_T][MAX_LEN * MAX_R]; // 새로운 문자열 배열
void set_str(int index, int repeat, char* str);
void print_P(void);

int main(void) {
	(void)scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		(void)scanf("%d", &R);
		(void)getchar();
		gets(S[i]);
		set_str(i, R, S[i]);
	}
	print_P();
	return 0;
}

void set_str(int index, int repeat, char* str) {
	for (int i = 0; i < MAX_LEN; ++i) {
		if (*(str + i) == '\0') break;
		for (int j = 0; j < repeat; ++j) {
			P[index][i * repeat + j] = *(str + i);
		}
	}
}

void print_P(void) {
	for (int i = 0; i < T; ++i) {
		printf("%s\n", P[i]);
	}
}
#endif