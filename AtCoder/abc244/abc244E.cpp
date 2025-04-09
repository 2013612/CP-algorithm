#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int n, m, k, s, t, x, a[4004], b[4004];
mint dp[2004][2004][2];
int main() {
	scanf("%d %d %d %d %d %d", &n, &m, &k, &s, &t, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[m + i] = b[i];
		b[m + i] = a[i];
	}
	dp[0][s][0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2 * m; j++) {
			if (b[j] != x) {
				dp[i + 1][b[j]][0] += dp[i][a[j]][0];
				dp[i + 1][b[j]][1] += dp[i][a[j]][1];
			} else {
				dp[i + 1][b[j]][0] += dp[i][a[j]][1];
				dp[i + 1][b[j]][1] += dp[i][a[j]][0];
			}
		}
	}
	
	printf("%d\n", dp[k][t][0].val());
	return 0;
}
