#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int n, m, k;
mint dp[1003][5003], ans;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int j = 1; j <= m; j++) {
		dp[1][j] = 1;
	}
	for (int i = 1; i < n; i++) {
		mint sum = 0;
		for (int j = k + 1; j <= m; j++) {
			sum += dp[i][j];
		}
		for (int j = 1; j <= m; j++) {
			dp[i + 1][j] = sum;
			sum += dp[i][max(j + 1 - k, 0)];
			sum -= dp[i][min(j + k, 5002)];
		}
	}
	for (int j = 1; j <= m; j++) {
		ans += dp[n][j];
	}
	printf("%d\n", ans.val());
	return 0;
}