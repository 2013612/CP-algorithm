#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;

string s;
int cou[5004][26];
mint ans, dp[5004][5004], fac[5004];

int main() {
	cin >> s;
	fac[0] = 1;
	for (int i = 1; i < 5004; i++) {
		fac[i] = fac[i - 1] * i;
	}
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = i; j < s.size(); j++) {
//			for (int k = i; k <= j; k++) {
//				cou[i + 1][j + 1][s[k] - 'a']++;
//			}
//		}
//	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; i + j <= s.size(); j++) {
			cou[j][s[j + i - 1] - 'a']++;
			mint t = fac[i + 1];
			for (int k = 0; k < 26; k++) {
				t *= fac[cou[j][k]].inv();
			}
			dp[j][j + i] = dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][j + i - 1] + t;
		}
	}
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= s.size(); j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", dp[1][s.size()]);
	return 0;
}
