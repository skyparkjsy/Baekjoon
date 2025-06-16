#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// b1157. 단어공부
#if 01
#define MAX_LEN (1000000+1)
#define ALPHABET_NUM ('z' - 'A' + 1)
char str[MAX_LEN];

typedef struct mystruct {
	int cnt;
	int index;
}mystruct_t;

mystruct_t map[ALPHABET_NUM];
int comp_struct(void* a, void* b) {
	return ((mystruct_t*)b)->cnt - ((mystruct_t*)a)->cnt;
}

int main(void) {
	int max_cnt = 0;
	int max_alph;
	int str_length;
	//(void)freopen("b1157.txt", "r", stdin);
	(void)scanf("%s", str);
	for (char* p = str; *p != NULL; ++p) {
		if (*p >= 'a') {
			map[*p - 'a'].cnt += 1;
			map[*p - 'a'].index = *p - ('a' - 'A');
		}
		else {
			map[*p - 'A'].cnt += 1;
			map[*p - 'A'].index = *p;
		}
	}

	qsort(map, ALPHABET_NUM, sizeof(map[0]), comp_struct);
	max_alph = map[0].index;

	if (map[0].cnt == map[1].cnt) printf("?\n");
	else printf("%c", (max_alph >= 'a') ? max_alph - ('a' - 'A') : max_alph);

	return 0;
}
#endif
