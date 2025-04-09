#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;

long long dp[100005][2];

long long pow(int a, int x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return a * pow(a, x - 1) % M;
	} else {
		long long t = pow(a, x / 2);
		return t * t % M;
	}
}

long long inv(int a) {
	return pow(a, M - 2);
}

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	
	reverse(s.begin(), s.end());
	
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = dp[i + 1][1] = 0;
	}
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '0') {
			dp[i + 1][0] = dp[i][0] + dp[i][1] * inv(2) % M;
			dp[i + 1][1] = dp[i][1] * inv(2) % M;
			
		} else {
			dp[i + 1][0] = dp[i][0] * inv(2) % M;
			dp[i + 1][1] = dp[i][0] * inv(2) % M + dp[i][1];

		}
		
		dp[i + 1][0] %= M;
		dp[i + 1][1] %= M;
	}
	
	printf("%lld\n", (dp[n - 1][0] * (n - 1) % M + dp[n - 1][1] * n % M) % M);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}