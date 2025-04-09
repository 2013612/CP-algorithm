#include<iostream>
#include<algorithm>
#include<vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;
int N;
mint dp[1004][2004][10];
string S;
int main() {
	scanf("%d", &N);
	cin >> S;
	dp[0][(1 << (S[0] - 'A'))][S[0] - 'A'] = 1;
	for (int i = 1; i < S.length(); i++) {
		int cti = S[i] - 'A';
		dp[i][1 << cti][cti] = 1;
		for (int j = 0; j < (1 << 10); j++) {
			for (int k = 0; k < 10; k++) {
				if (j & (1 << cti)) {
					if (k == cti) {
						dp[i][j][k] += dp[i - 1][j][k];
					}
				} else {
					dp[i][j + (1 << cti)][cti] += dp[i - 1][j][k];
				}
				dp[i][j][k] += dp[i - 1][j][k];
			}
		}
	}
	mint ans = 0;
	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < 10; j++) {
			ans += dp[N - 1][i][j];
		}
	}
	printf("%d\n", ans.val());
}
