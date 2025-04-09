#include<iostream>
using namespace std;

int N, K, a[100006], t[100006], dp[100006][3], b[100006];
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}
	b[0] = a[0];
	for (int i = 1; i < N; i++) {
		b[i] = b[i - 1] + a[i];
	}
	dp[0][0] = t[0] * a[0];
	dp[0][1] = a[0];
	for (int i = 1; i < K; i++) {
		dp[i][0] = dp[i - 1][0] + t[i] * a[i];
		dp[i][1] = b[i];
	}
	for (int i = K; i < N; i++) {
		dp[i][0] = dp[i - 1][0] + t[i] * a[i];
		dp[i][1] = max(dp[i - K][0] + b[i] - b[i - K], dp[i - 1][1] + t[i] * a[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}
