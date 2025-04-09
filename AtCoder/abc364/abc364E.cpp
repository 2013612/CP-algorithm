#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, x, y, ans, dp[103][103][10005];
pii a[103];

bool f(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	scanf("%d %d %d", &n, &x, &y);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= 10000; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= y; k++) {
				if (dp[i][j][k] <= x) {
					if (k + a[i].second <= y) {
						dp[i + 1][j + 1][k + a[i].second] = min(dp[i + 1][j + 1][k + a[i].second], dp[i][j][k] + a[i].first);
					}
					ans = max(ans, j + 1);
				}
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	
	sort(a, a + n, f);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= 10000; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= x; k++) {
				if (dp[i][j][k] <= y) {
					if (k + a[i].first <= x) {
						dp[i + 1][j + 1][k + a[i].first] = min(dp[i + 1][j + 1][k + a[i].first], dp[i][j][k] + a[i].second);
					}
					ans = max(ans, j + 1);
				}
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}