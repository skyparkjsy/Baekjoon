#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int H, W;
int arr[5][5];
int check[5][5];
int num;

void check_num(void) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (num == arr[i][j]) check[i][j] = 1;
		}
	}
}
int check_bingo(void) {
	int cnt = 0;
	int bingo = 0;
	//열페크
	for (int i = 0; i < 5; ++i) {
		cnt = 0;
		for (int j = 0; j < 5; ++j) {
			if (check[i][j]) cnt++;
		}
		if (cnt == 5) bingo++;
		if (bingo >= 3) return 1;
	}
	//행체크
	for (int i = 0; i < 5; ++i) {
		cnt = 0;
		for (int j = 0; j < 5; ++j) {
			if (check[j][i]) cnt++;
		}
		if (cnt == 5) bingo++;
		if (bingo >= 3) return 1;
	}
	//대각선체크
	cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (check[i][i]) cnt++;
	}		
	if (cnt == 5) bingo++;
	if (bingo >= 3) return 1;

	cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (check[i][4 - i]) cnt++;
	}
	if (cnt == 5) bingo++;
	if (bingo >= 3) return 1;
	return 0;

}
int main(void) {
	int result;
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cnt++;
			cin >> num;
			check_num();
			result = check_bingo();
			if (result != 0) {
				cout << cnt << '\n';
				return 0;
			}
		}
	}


	return 0;
}


