#include <iostream>
//b11727. 2xn 타일링 2
#if 01
using namespace std;
int N;
int dp[1001]; // n 위치 만드는 방법
int main(void) {
	cin >> N;
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] += (dp[i - 1] + dp[i - 2] * 2) % 10007; //  % 안해주면 틀림 ..
	}
	cout << dp[N] << '\n';
	return 0;
}
#endif