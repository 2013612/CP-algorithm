#include<iostream>
#include<algorithm>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int N, a[3003], b[3003];
mint dp[3003][3003], pre[3003];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = a[1]; i <= b[1]; i++) {
		dp[1][i] = 1;
	}
	pre[0] = dp[1][0];
	for (int i = 1; i <= 3000; i++) {
		pre[i] = pre[i - 1] + dp[1][i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = a[i]; j <= b[i]; j++) {
			dp[i][j] = pre[j];
		}
		for (int j = 0; j <= 3000; j++) {
			if (j == 0) {
				pre[j] = dp[i][j];
			} else {
				pre[j] = pre[j - 1] + dp[i][j];
			}
		}
	}
	mint ans = 0;
	for (int i = 0; i <= 3000; i++) {
		ans += dp[N][i];
	}
	printf("%d\n", ans.val());
	return 0;
}
