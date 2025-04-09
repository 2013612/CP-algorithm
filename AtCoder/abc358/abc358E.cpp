#include<iostream>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int k, c[30];
mint dp[30][1004], fac[1004], inv[1004];

int main() {
	scanf("%d", &k);
	
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= k; i++) {
		fac[i] = fac[i - 1] * i;
		inv[i] = fac[i].inv();
	}
	
	for (int i = 0; i < 26; i++) {
		scanf("%d", &c[i]);
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= 26; i++) {
		for (int j = 0; j <= k; j++) {
			for (int u = 0; u <= min(j, c[i - 1]); u++) {
				dp[i][j] += dp[i - 1][j - u] * fac[j] * inv[u] * inv[j - u];
			}
		}
	}
	
	mint ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += dp[26][i];
	}
	
	printf("%d\n", ans.val());
	
	return 0;
}