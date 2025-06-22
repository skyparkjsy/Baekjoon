#include <iostream>
#include <iomanip>
using namespace std;

#if 01
int main(void) {
	int N;
	double arr[10000] = { 0.0f, };
	double mul = 1.000f;
	double max = 0.0f;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		mul = 1.000f;
		for (int j = i; j < N; ++j) {
			mul *= arr[j];
			if (mul > max) max = mul;
		}
	}
	cout << fixed << setprecision(3) << max << '\n';
}
#endif