#include<iostream>
using namespace std;

int n, a[200006];
long long dp[200006][2];
int main() {
	scanf("%d", &n);
	dp[0][1] = -1e18;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i] * 2);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
	}
	
	printf("%lld\n", max(dp[n][0], dp[n][1]));
	return 0;
}