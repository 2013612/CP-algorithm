#include<iostream>
#include<unordered_map>
using namespace std;

int n, m;
long long ans, dp[5004][5004], x[5004];
unordered_map<int, long long> b;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 5004; i++) {
		for (int j = 0; j < 5004; j++) {
			dp[i][j] = -4e18;
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	for (int i = 0; i < m; i++) {
		int c, y;
		scanf("%d %d", &c, &y);
		b[c] = y;
	}
	
	dp[0][0] = 0;
	dp[0][1] = x[0] + b[1];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][0] = max(dp[i][0], dp[i - 1][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + x[i] + b[j + 1]);
		}
	}
	
	for (int i = 0; i <= n; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	printf("%lld\n", ans);
	return 0;
}