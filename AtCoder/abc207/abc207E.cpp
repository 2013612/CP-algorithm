#include<iostream>
using namespace std;

const int M = 1e9 + 7;
int N;
long long a[3004], pre[3004];
long long dp[3004][3004];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &a[i]);
		if (i == 0) {
			pre[0] = a[0];
		} else {
			pre[i] = pre[i - 1] + a[i];
		}
	}
	for (int i = 0; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			for (int k = j; k <= i; k++) {
				if ((pre[i] - pre[k]) % j == 0) {
					dp[i][j] = (dp[i][j] + dp[k][j - 1]) % M;
				}
			}
			if (a[i] % j == 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = (ans + dp[N][i]) % M;
	}
	printf("%lld\n", ans);
	return 0;
}
