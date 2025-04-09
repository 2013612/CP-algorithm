#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int M = 998244353;

int t, n, a[500006];
long long dp[500006][2];
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		if (a[0] == 0) {
			dp[0][0] = 0;
			dp[0][1] = 1;
		} else if (a[0] == 1) {
			dp[0][0] = 1;
			dp[0][1] = 0;
		} else {
			dp[0][0] = 0;
			dp[0][1] = 0;
		}
		for (int i = 1; i < n; i++) {
			if (a[i] == 0) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2 + 1;
			} else if (a[i] == 1) {
				dp[i][0] = dp[i - 1][0] * 2 + 1;
				dp[i][1] = dp[i - 1][1];
			} else if (a[i] = 2){
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1] * 2;
			}
			dp[i][0] %= M;
			dp[i][1] %= M;
		}
		for (int i = 0; i < n; i++) {
			printf("%lld %lld\n", dp[i][0], dp[i][1]);
		}
		printf("\n");
		printf("%lld\n", (dp[n - 1][0] + dp[n - 1][1]) % M);
	}
	return 0;
}
