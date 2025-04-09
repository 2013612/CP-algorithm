#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

long long N, ans, dp[103][2];

int main() {
	scanf("%lld", &N);
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		if (s == "AND") {
			dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1];
			dp[i][1] = dp[i - 1][1];
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2;
		}
	}
	printf("%lld\n", dp[N][1]);
	return 0;
}
