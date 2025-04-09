#include<iostream>
using namespace std;

int n;
long long a[300006], dp[300006][2], dp2[300006][2];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	dp[0][0] = a[0];
	dp[0][1] = 2e9;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = dp[i - 1][0];
	}
	dp2[0][0] = 2e9;
	dp2[0][1] = a[n - 1];
	for (int i = 1; i < n - 1; i++) {
		dp2[i][0] = min(dp2[i - 1][0], dp2[i - 1][1]) + a[i];
		dp2[i][1] = dp2[i - 1][0];
	}
	
	printf("%lld\n", min(min(dp[n - 1][0], dp[n - 1][1]), min(dp2[n - 2][0], dp2[n - 2][1])));
	return 0;
}