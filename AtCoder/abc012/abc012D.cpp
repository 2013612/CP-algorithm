#include<iostream>
using namespace std;

int n, m, dp[303][303][303];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j][0] = 1e9;
		}
		dp[i][i][0] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		dp[a][b][0] = t;
		dp[b][a][0] = t;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[j][k][i] = min(dp[j][k][i - 1], dp[j][i][i - 1] + dp[i][k][i - 1]);
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		int maxi = 0;
		for (int j = 1; j <= n; j++) {
			maxi = max(maxi, dp[i][j][n]);
		}
		ans = min(ans, maxi);
	}
	printf("%d\n", ans);
	return 0;
}
