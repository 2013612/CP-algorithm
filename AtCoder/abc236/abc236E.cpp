#include<iostream>
using namespace std;

long long n, a[100006];

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	long long left = 0;
	long long right = 2e13;
	while (left < right) {
		long long mid = (left + right + 1) / 2;
		long long dp[100006][2];
		dp[0][0] = dp[0][1] = 0;
		for (int i = 0; i < n; i++) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1]) + a[i] * 1000 - mid;
			dp[i + 1][1] = dp[i][0];
		}
		if (max(dp[n][0], dp[n][1]) >= 0) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	printf("%lf\n", (double) left / 1000);
	left = 0;
	right = 2e9;
	while (left < right) {
		long long mid = (left + right + 1) / 2;
		long long dp[100006][2];
		dp[0][0] = dp[0][1] = 0;
		for (int i = 0; i < n; i++) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1]) + (a[i] >= mid ? 1 : -1);
			dp[i + 1][1] = dp[i][0];
		}
		if (max(dp[n][0], dp[n][1]) > 0) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	printf("%lld\n", left);
	return 0;
}
