#include<iostream>
#include<string>
using namespace std;

int dp[100006][3];
long long k;
const int M = 1000000007;
string S;
int main() {
	cin >> S;
	k = 1;
	for (int i = 1; i <= S.length(); i++){
		if (S[i-1] == 'A'){
			dp[i][0] = (dp[i-1][0] + k) % M;
			dp[i][1] = dp[i-1][1];
			dp[i][2] = dp[i-1][2];
		} else if (S[i-1] == 'B') {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % M;
			dp[i][2] = dp[i-1][2];
		} else if (S[i-1] == 'C') {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
			dp[i][2] = (dp[i-1][2] + dp[i-1][1]) % M;
		} else if (S[i-1] == '?') {
			dp[i][2] = (((dp[i-1][2] + dp[i-1][2]) % M + dp[i-1][2]) % M + dp[i-1][1]) % M;
			dp[i][1] = (((dp[i-1][1] + dp[i-1][1]) % M + dp[i-1][1]) % M + dp[i-1][0]) % M;
			dp[i][0] = (((2*dp[i-1][0]) % M + dp[i-1][0]) % M + k) % M;
			k = (k*3) % M;
		}
	}
	cout << dp[S.length()][2] << endl;
	return 0;
}
