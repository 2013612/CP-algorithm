#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int n, p;
int main() {
	scanf("%d %d", &n, &p);
	modint::set_mod(p);
	modint dp[2][3003], ans;
	dp[1][2] = 26;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[(i + 1) % 2][j] = 0;
		}
		for (int j = 1; j < n; j++) {
			//printf("%d ", dp[i % 2][j]);
			dp[(i + 1) % 2][j + 2] += dp[i % 2][j] * 25;
			dp[(i + 1) % 2][j] += dp[i % 2][j];
		}
		//printf("\n");
	}
	for (int j = 1; j < n; j++) {
		ans += dp[n % 2][j];
	}
	printf("%d\n", ans.val());
	return 0;
}
