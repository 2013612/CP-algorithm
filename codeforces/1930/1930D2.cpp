#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
long long ans = 0;
long long dp[1000007];

void solve() {
	scanf("%d", &n);
	string s;
	ans = 0;
	cin >> s;
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	
	if (n == 1) {
		for (int i = 0; i < n; i++) {
			int one = 0;
			int sum = 0;
			for (int j = i; j < n; j++) {
				if (s[j] == '1' && one <= 0) {
					one = 3;
					sum++;
				}
				
				one--;
				
				ans += sum;
			}
		}
		printf("%lld\n", ans);
		return;
	}
	
	if (s[n - 1] == '1') {
		dp[n - 3] = dp[n - 2] = dp[n - 1] = 1;
	}
	if (s[n - 2] == '1') {
		dp[n - 3] = dp[n - 2] = 2;
	}
	if (s[n - 3] == '1') {
		dp[n - 3] = 3;
	}
	
	for (int i = n - 4; i >= 0; i--) {
		if (s[i] == '1') {
			dp[i] = dp[i + 3] + n - (i + 3) + 3;
		} else {
			dp[i] = dp[i + 1];
		}
	}
	
	for (int i = 0; i < n; i++) {
		ans += dp[i];
	}
	
//	printf("! %lld %lld %lld\n", dp[0], dp[1], dp[2]);
	
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}