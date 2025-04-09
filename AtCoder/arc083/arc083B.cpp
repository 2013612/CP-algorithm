#include<iostream>
using namespace std;

int n, dp[303][303][303];
long long ans;
bool can = true;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &dp[i][j][n]);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][i + 1][i + 1] == 0 || dp[i + 1][k][i + 1] == 0) {
					dp[j][k][i] = dp[j][k][i + 1];
					continue;
				}
				if (dp[j][i + 1][i + 1] + dp[i + 1][k][i + 1] > dp[j][k][i + 1]) {
					dp[j][k][i] = dp[j][k][i + 1];
				} else if (dp[j][i + 1][i + 1] + dp[i + 1][k][i + 1] == dp[j][k][i + 1]) {
					dp[j][k][i] = 0;
				} else {
					dp[j][k][i] = -1;
					can = false;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += dp[i][j][0];
		}
	}
	if (!can) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans / 2);
	}
	return 0;
}
