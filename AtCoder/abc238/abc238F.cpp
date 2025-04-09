#include<iostream>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef pair<int, int> pii;

int n, k;
mint dp[303][303][303], ans;
pii a[303];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].second);
	}
	sort(a + 1, a + n + 1, greater<pii>());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == 1) {
				for (int l = 1; l <= n; l++) {
					if (l <= a[i].second) {
						dp[i][j][l] += dp[i - 1][j][l];
					}
				}
				dp[i][j][a[i].second]++;
				continue;
			}
			for (int l = 1; l <= n; l++) {
				if (l > a[i].second) {
					dp[i][j][l] += dp[i - 1][j - 1][l];
				} else {
					dp[i][j][l] += dp[i - 1][j][l];
					dp[i][j][a[i].second] += dp[i - 1][j - 1][l];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		ans += dp[n][k][i];
	}
	printf("%d\n", ans);
	return 0;
}
