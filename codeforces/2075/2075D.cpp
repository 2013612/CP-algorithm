#include<bits/stdc++.h>
using namespace std;

long long x, y, ans, dp[100][100][100];

void solve() {
	scanf("%lld %lld", &x, &y);
	ans = 4e18;

	for (int j = 0; j <= 60; j++) {
		for (int k = 0; k <= 60; k++) {
			if ((x >> j) == (y >> k)) {
				ans = min(ans, dp[60][j][k]);
			}
		}
	}
	
	printf("%lld\n", ans);
}

void f() {
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= 60; j++) {
			for (int k = 0; k <= 60; k++) {
				dp[i][j][k] = 1e18;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for (int i = 1; i <= 60; i++) {
		for (int j = 0; j <= 60; j++) {
			for (int k = 0; k <= 60; k++) {
				dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
				
				if (j + i <= 60) {
					dp[i][i + j][k] = min(dp[i][i + j][k], dp[i - 1][j][k] + (1ll << i));
				}
				
				if (k + i <= 60) {
					dp[i][j][k + i] = min(dp[i][j][k + i], dp[i - 1][j][k] + (1ll << i));
				}
			}
		}
	}
}

int main() {
	f();
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}