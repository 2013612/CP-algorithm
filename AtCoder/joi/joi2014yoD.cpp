#include<iostream>
using namespace std;

int N, b[2000];
long long dp[2000][10], ans;
string s;
int main() {
	cin >> N >> s;
	s = " " + s;
	for (int i = 1; i <= N; i++) {
		if (s[i] == 'J') {
			b[i] = 1;
		} else if (s[i] == 'O') {
			b[i] = 2;
		} else {
			b[i] = 4;
		}
	}
	dp[0][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 7; j++) {
			if (b[i] & j) {
				for (int k = 1; k <= 7; k++) {
					if (k & j) {
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 7; i++) {
		ans = (ans + dp[N][i]) % 10007;
	}
	printf("%lld\n", ans);
	return 0;
}
