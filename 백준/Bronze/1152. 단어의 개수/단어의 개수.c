#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
// b1152. 단어의 개수 (250427)
#if 01
#define MAX_N (1000000+2)


int main(void){
	char string[MAX_N];
	char* strPtr;
	int cnt, i;

	gets(string);
	strPtr = string;

	// 시작이 공백인 경우
	if (*strPtr != ' ' && *strPtr != '\0') {
		++cnt;
	}

	for (i = 0; i < MAX_N; ++i) {
		// 읽었더니 '\0' -> 종료
		if (*strPtr == '\0') break;

		// 공백이 입력되었고, 끝이 공백이 아닐 때 cnt++
		if (*strPtr == ' ' && (*(strPtr + 1) != '\0')) {  
			cnt++;
		}
		++strPtr;
	}
	printf("%d\n", cnt);
	return 0;
}
#endif