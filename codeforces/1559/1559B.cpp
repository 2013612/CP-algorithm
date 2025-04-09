#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans;
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		string S;
		cin >> S;
		int dp[103][2];
		string s[103][2];
		if (S[0] == 'R') {
			dp[0][0] = 0;
			dp[0][1] = 2e9;
			s[0][0] = "R";
			s[0][1] = "R";
		} else if (S[0] == 'B') {
			dp[0][0] = 2e9;
			dp[0][1] = 0;
			s[0][0] = "B";
			s[0][1] = "B";
		} else {
			dp[0][0] = 0;
			dp[0][1] = 0;
			s[0][0] = "R";
			s[0][1] = "B";
		}
		for (int i = 1; i < N; i++) {
			if (S[i] == 'R') {
				if (dp[i - 1][0] + 1 < dp[i - 1][1]) {
					s[i][0] = s[i - 1][0] + "R";
				} else {
					s[i][0] = s[i - 1][1] + "R";
				}
				dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
				dp[i][1] = 2e9;
			} else if (S[i] == 'B') {
				if (dp[i - 1][1] + 1 < dp[i - 1][0]) {
					s[i][1] = s[i - 1][1] + "B";
				} else {
					s[i][1] = s[i - 1][0] + "B";
				}
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1);
				dp[i][0] = 2e9;
			} else {
				if (dp[i - 1][0] + 1 < dp[i - 1][1]) {
					s[i][0] = s[i - 1][0] + "R";
				} else {
					s[i][0] = s[i - 1][1] + "R";
				}
				if (dp[i - 1][1] + 1 < dp[i - 1][0]) {
					s[i][1] = s[i - 1][1] + "B";
				} else {
					s[i][1] = s[i - 1][0] + "B";
				}
				dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1);
			}
		}
		if (dp[N - 1][0] < dp[N - 1][1]) {
			cout << s[N - 1][0] << endl;
		} else {
			cout << s[N - 1][1] << endl;
		}
	}
	return 0;
}
