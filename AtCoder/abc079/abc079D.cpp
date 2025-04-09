#include<iostream>
using namespace std;

int h, w, dp[20][20][20], ans;
int main() {
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &dp[i][j][0]);
		}
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				dp[j][k][i] = min(dp[j][k][i - 1], dp[j][i][i - 1] + dp[i][k][i - 1]);
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int t;
			scanf("%d", &t);
			if (t > -1) {
				ans += dp[t + 1][2][10];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
