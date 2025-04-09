#include<iostream>
using namespace std;

int T;
int main() {
	freopen("consistency_chapter_2_input.txt", "r", stdin);
	freopen("consistency_chapter_2_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		string s;
		cin >> s;
		int N;
		scanf("%d", &N);
		int dp[30][30][30];
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k < 30; k++) {
				dp[j][k][0] = 1e6;
			}
			dp[j][j][0] = 0;
		}
		for (int j = 0; j < N; j++) {
			string s1;
			cin >> s1;
			dp[s1[0] - 'A' + 1][s1[1] - 'A' + 1][0] = 1;
		}
		for (int j = 1; j <= 26; j++) {
			for (int k = 1; k <= 26; k++) {
				for (int l = 1; l <= 26; l++) {
					dp[k][l][j] = min(dp[k][l][j - 1], dp[k][j][j - 1] + dp[j][l][j - 1]);
				}
			}
		}
		int ans = 1e9;
		for (int j = 1; j <= 26; j++) {
			bool can = true;
			int len = 0;
			for (auto x:s) {
				len += dp[x - 'A' + 1][j][26];
				if (dp[x - 'A' + 1][j][26] > 1e4) {
					can = false;
					break;
				}
			}
			if (can) {
				ans = min(ans, len);
			}
		}
		if (ans > 1e8) {
			ans = -1;
		}
		printf("Case #%d: %d\n", i, ans);
	}
}
