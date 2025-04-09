#include<iostream>
#include<string>
using namespace std;

int a[1000007], dp[1000007][3];
string n;
int main(){
	cin >> n;
	for (int i = 1; i <= n.length(); i++) {
		a[i] = n[i - 1] - '0';
	}
	dp[0][1] = dp[0][2] = -10000;
	for (int i = 1; i <= n.length(); i++) {
		if (a[i] % 3 == 0) {
			dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + 1;
			dp[i][1] = dp[i-1][1];
			dp[i][2] = dp[i-1][2];
		} else if (a[i] % 3 == 1) {
			dp[i][0] = dp[i-1][2] + 1;
			dp[i][1] = dp[i-1][0];
			dp[i][2] = dp[i-1][1];
		} else {
			dp[i][0] = dp[i-1][1] + 1;
			dp[i][1] = dp[i-1][2];
			dp[i][2] = dp[i-1][0];
		}
	}
	printf("%d\n", max(max(dp[n.length()][0], dp[n.length()][1]), dp[n.length()][2]));
	return 0;
}
