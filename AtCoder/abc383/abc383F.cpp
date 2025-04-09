#include<iostream>
#include<algorithm>
using namespace std;

int n, x, k;
pair<int, pair<int, int>> p[503];
long long dp[503][50004][2], ans;

int main() {
	scanf("%d %d %d", &n, &x, &k);
	
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		p[i] = {c, {a, b}};
	}
	
	sort(p + 1, p + n + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {	
			if (p[i].first == p[i - 1].first) {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j][0]);
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j][1]);
				
				if (j + p[i].second.first <= x) {
					dp[i][j + p[i].second.first][1] = max({dp[i][j][1], dp[i - 1][j][0] + p[i].second.second + k, dp[i - 1][j][1] + p[i].second.second});
				}
			} else {
				dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i][j][0]});
				
				if (j + p[i].second.first <= x) {
					dp[i][j + p[i].second.first][1] = max({dp[i][j][1], dp[i - 1][j][0] + p[i].second.second + k, dp[i - 1][j][1] + p[i].second.second + k});
				}
			}
			
			ans = max(dp[i][j][0], dp[i][j][1]);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}