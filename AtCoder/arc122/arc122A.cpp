#include<iostream>
using namespace std;

const int M = 1e9 + 7;
long long N, a[100006], dp[100006][2], num[100006][2];
int main() {
	scanf("%lld", &N);
	scanf("%lld", &a[0]);
	dp[0][0] = a[0];
	dp[0][1] = 0;
	num[0][0] = 1;
	num[0][1] = 0;
	for (int i = 1; i < N; i++) {
		scanf("%lld", &a[i]);
		long long temp = (num[i - 1][0] + num[i - 1][1]) % M;
		temp = a[i] * temp % M;
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % M;
		dp[i][0] = (dp[i][0] + temp) % M;
		num[i][0] = (num[i - 1][0] + num[i - 1][1]) % M;
		temp = a[i] * num[i - 1][0] % M;
		dp[i][1] = dp[i - 1][0] - temp;
		dp[i][1] = dp[i][1] % M;
		num[i][1] = num[i - 1][0];
	}
//	for (int i = 0; i <= N; i++) {
//		cout << dp[i][0] << " " << dp[i][1] << endl;
//	}
	printf("%lld\n", ((dp[N - 1][0] + dp[N - 1][1]) % M + M) % M);
	return 0;
}
