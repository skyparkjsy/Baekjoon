#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
// b10798. 세로 읽기
/*
	단어 개수: 5개
	최대 길이: 15
	arr[5][17] 만들기
	arr[n][0] 에는 n번째 단어의 길이가 들어감
	arr[0~4][1] 부터 체크하면서 쭉
*/
#if 01
#define MAX_LEN (15+1)
#define STR_NUM (5)
char arr[STR_NUM][MAX_LEN];

void solve(void) {
	for (int i = 0; i < MAX_LEN; ++i) {
		for (int j = 0; j < STR_NUM; ++j) {
			if (arr[j][i] != NULL) printf("%c", arr[j][i]);
		}
	}
}
void input_arr(void) {
	for (int i = 0; i < STR_NUM; ++i) {
		gets(arr + i);
	}
}

int main(void) {
	//(void)freopen("b10798.txt", "r", stdin);
	input_arr();
	solve();
	return 0;
}

#endif