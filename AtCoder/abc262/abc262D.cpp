#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int n, a[103], x;
mint ans, dp[103][2][103][103];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i][0][0][0] = 1;
		x = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = max(0, i + j - n - 1); k <= i; k++) {
				for (int l = 0; l < i; l++) {
					dp[i][1 - x][k][l] = 0;
				}
			}
			for (int k = max(0, i + j - n - 1); k <= i; k++) {
				for (int l = 0; l < i; l++) {
					dp[i][1 - x][k][l] += dp[i][x][k][l];
					dp[i][1 - x][k + 1][(l + a[j]) % i] += dp[i][x][k][l];
				}
			}
			x = 1 - x;
		}
		ans += dp[i][x][i][0];
	}
	printf("%d\n", ans.val());
	return 0;
}