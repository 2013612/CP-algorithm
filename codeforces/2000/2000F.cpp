#include<iostream>
using namespace std;

int n, k, dp[1003][103];
void solve() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 1e9;
		}
		{
			int cnt = 0;
			while (cnt < k && (a > 1 || b > 1)) {
				cnt++;
				dp[i][cnt] = dp[i][cnt - 1] + min(a, b);
				if (a > b) {
					a--;
				} else {
					b--;
				}
			}
			
			if (cnt < k) {
				dp[i][min(cnt + 2, k)] = dp[i][cnt] + 1;
			}
		}
	}
	
	for (int l = 2; l <= n; l++) {
		for (int i = k - 1; i >= 0; i--) {
			for (int j = k; j >= 0; j--) {
				dp[l][min(i + j, k)] = min(dp[l][min(i + j, k)], dp[l - 1][j] + dp[l][i]);
			}
		}
	}
	
	if (dp[n][k] > 1e8) {
		printf("-1\n");
	} else {
		printf("%d\n", dp[n][k]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}