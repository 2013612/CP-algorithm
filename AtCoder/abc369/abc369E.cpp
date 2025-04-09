#include<iostream>
#include<algorithm>
using namespace std;

int n, m, b[10];
pair<pair<int, int>, int> a[200006];
long long dp[403][403][403];
int q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				dp[i][j][k] = 1e18;
			}
		}
		dp[i][i][0] = 0;
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		a[i] = {{u, v}, t};
		dp[u][v][0] = min<long long>(dp[u][v][0], t);
		dp[v][u][0] = min<long long>(dp[v][u][0], t);
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
			}
		}
	}
	
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &b[j]);
		}
		
		long long ans = 4e18;
		
		do {
			long long dp2[2];
			dp2[0] = dp[1][a[b[0]].first.first][n] + a[b[0]].second;
			dp2[1] = dp[1][a[b[0]].first.second][n] + a[b[0]].second;
			for (int i = 1; i < k; i++) {
				long long temp0 = dp2[0];
				long long temp1 = dp2[1];
				dp2[0] = min(temp0 + dp[a[b[i - 1]].first.second][a[b[i]].first.first][n], temp1 + dp[a[b[i - 1]].first.first][a[b[i]].first.first][n]) + a[b[i]].second;
				dp2[1] = min(temp0 + dp[a[b[i - 1]].first.second][a[b[i]].first.second][n], temp1 + dp[a[b[i - 1]].first.first][a[b[i]].first.second][n]) + a[b[i]].second;
			}
			dp2[0] += dp[a[b[k - 1]].first.second][n][n];
			dp2[1] += dp[a[b[k - 1]].first.first][n][n];
			ans = min({ans, dp2[0], dp2[1]});
		} while (next_permutation(b, b + k));
		
		printf("%lld\n", ans);
	}
	
	return 0;
}