#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;
string S;
char c[10] = {'q', 'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
long long dp[100005][10];
int main() {
	cin >> S;
	if (S[0] == 'c') {
		dp[0][1] = 1;
	}
	dp[0][0] = 1;
	for (int i = 1; i < S.length(); i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 9; j++) {
			dp[i][j] = dp[i - 1][j];
			if (S[i] == c[j]) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			dp[i][j] %= M;
		}
	}
	printf("%lld\n", dp[S.length() - 1][8]);
	return 0;
}
