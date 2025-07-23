#include <iostream>
#include <algorithm>
#include <climits>

#if 01
using namespace std;
int N;
int arr[100001];
int dp[100001]; // 자신부터 연속된 수 선택했을 때의 최댓값
int ans = INT_MIN;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	dp[N - 1] = arr[N - 1];
	for (int i = N - 1; i >= 0; --i) {
		dp[i] = max(arr[i], dp[i + 1] + arr[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}
#endif