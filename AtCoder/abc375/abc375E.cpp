#include<iostream>
using namespace std;

int n, dp[103][503][503], a[103], b[103], sum, ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		
		sum += b[i];
	}
	
	if (sum % 3) {
		printf("-1\n");
		return 0;
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum / 3; j++) {
			for (int k = 0; k <= sum / 3; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum / 3; j++) {
			for (int k = 0; k <= sum / 3; k++) {
				if (a[i] == 1) {
					if (j + b[i] <= sum / 3) {
						dp[i + 1][j + b[i]][k] = min(dp[i + 1][j + b[i]][k], dp[i][j][k]);
					}
					if (k + b[i] <= sum / 3) {
						dp[i + 1][j][k + b[i]] = min(dp[i + 1][j][k + b[i]], dp[i][j][k] + 1);
					}
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + 1);
				} else if (a[i] == 2) {
					if (j + b[i] <= sum / 3) {
						dp[i + 1][j + b[i]][k] = min(dp[i + 1][j + b[i]][k], dp[i][j][k] + 1);
					}
					if (k + b[i] <= sum / 3) {
						dp[i + 1][j][k + b[i]] = min(dp[i + 1][j][k + b[i]], dp[i][j][k]);
					}
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + 1);
				} else {
					if (j + b[i] <= sum / 3) {
						dp[i + 1][j + b[i]][k] = min(dp[i + 1][j + b[i]][k], dp[i][j][k] + 1);
					}
					if (k + b[i] <= sum / 3) {
						dp[i + 1][j][k + b[i]] = min(dp[i + 1][j][k + b[i]], dp[i][j][k] + 1);
					}
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				}
			}
		}
	}
	
	if (dp[n][sum / 3][sum / 3] < 1e8) {
		ans = dp[n][sum / 3][sum / 3];
	} else {
		ans = -1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}