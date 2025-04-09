#include<iostream>
using namespace std;

int n;
long long dp[403][403], m[403][403], ans, a[403], c[403];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e16;
		}
	}
	ans = 1e18;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i]--;
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
	}
	
	for (int i = 0; i < n; i++) {
		dp[i][i] = c[a[i]] + 1;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int end = (j + i) % n;
			for (int k = j; k < j + i; k++) {
				dp[j][end] = min(dp[j][end], dp[j][k % n] + dp[(k + 1) % n][end]);
			}
			if (a[j] == a[end]) {
				if (i == 1) {
					dp[j][end] = c[a[j]] + 2;
				} else {
					long long mini = dp[(j + 1) % n][(i + j - 1) % n];
					
					for (int k = j + 1; k < j + i; k++) {
						if (a[k % n] == a[j]) {
							mini = min(mini, m[(j + 1) % n][(k - 1) % n] + m[(k + 1) % n][(j + i - 1) % n]);
						}
					}
					
					m[(j + 1) % n][(i + j - 1) % n] = mini;
					dp[j][end] = min(dp[j][end], c[a[j]] + i + 1 + mini);
				}
			}
			
			if (i == n - 1) {
				ans = min(ans, dp[j][end]);
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}