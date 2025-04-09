#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint;

int n, p;
int main() {
	scanf("%d %d", &n, &p);
	modint::set_mod(p);
	mint dp[2][9003];
	for (int i = 1; i <= 3 * n - 2; i++) {
		dp[1][i] = 1;
	}
	printf("%d ", 3 * n - 2);
	for (int i = 2; i < n; i++) {
		mint ans;
		mint sum = 0;
		for (int j = 1; j <= 3 * n - 2; j++) {
			dp[i % 2][j] += sum;
			sum += dp[(i - 1) % 2][j];
			if (j % 3 == 0 || j == 2) {
				dp[i % 2][j] -= dp[(i - 1) % 2][j - 1];
			}
			if (j == 3) {
				dp[i % 2][j] -= dp[(i - 1) % 2][j - 2];
			}
			if (j == 3 * n - 2) {
				dp[i % 2][j] -= dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j - 2];
			}
			ans += dp[i % 2][j];
			//printf("!%d ", ans);
		}
		//printf("\n");
		printf("%d ", ans.val());
	}
	printf("\n");
	return 0;
}
