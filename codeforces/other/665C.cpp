#include<iostream>
#include<string>
using namespace std;

string ans, dp2[2][2];
char s[200006];
int dp[300006][2];
int main() {
	int k = scanf("%s", s);
	printf("%d\n", k);
	dp[0][0] = 0;
	dp[0][1] = 1;
	dp2[0][0] = s[0];
	dp2[0][1] = '0';
	int pos = 0;
	for (int i = 1; i < k; i++) {
		pos = 1 - pos;
		if (s[i] == s[i - 1]) {
			dp[i][0] = dp[i - 1][1];
			dp2[pos][0] = dp2[1 - pos][1] + s[i];
			if (dp[i - 1][0] <= dp[i - 1][1]) {
				dp[i][1] = dp[i - 1][0] + 1;
				dp2[pos][1] = dp2[1 - pos][0] + '0'; 
			} else {
				dp[i][1] = dp[i - 1][1] + 1;
				dp2[pos][1] = dp2[1 - pos][1] + '0';
			}
		} else {
			if (dp[i - 1][0] <= dp[i - 1][1]) {
				dp[i][0] = dp[i - 1][0];
				dp2[pos][0] = dp2[1 - pos][0] + s[i];
				dp[i][1] = dp[i - 1][0] + 1;
				dp2[pos][1] = dp2[1 - pos][0] + '0'; 
			} else {
				dp[i][0] = dp[i - 1][1];
				dp2[pos][0] = dp2[1 - pos][1] + s[i];
				dp[i][1] = dp[i - 1][1] + 1;
				dp2[pos][1] = dp2[1 - pos][1] + '0';
			}
		}
	}
	string temp2;
	if (dp[k - 1][0] <= dp[k - 1][1]) {
		temp2 = dp2[pos][0];
	} else {
		temp2 = dp2[pos][1];
	}
	char ans[200006];
	for (int i = 0; i < k; i++) {
		if (temp2[i] == s[i]) {
			ans[i] = s[i];
		} else {
			if (ans[i - 1] != 'a' && temp2[i + 1] != 'a') {
				ans[i] = 'a';
			} else if (ans[i - 1] != 'b' && temp2[i + 1] != 'b') {
				ans[i] = 'b';
			} else {
				ans[i] = 'c';
			}
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}
