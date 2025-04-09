#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<long long> a[200006];
long long dp[200006][2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, c;
		scanf("%d %d", &x, &c);
		a[c].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	long long pos[2] = {0, 0};
	for (int i = 1; i <= n; i++) {
		if (a[i].empty()) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			continue;
		}
		if (pos[0] < a[i][0]) {
			dp[i][0] = dp[i - 1][0] + a[i].back() * 2 - pos[0] - a[i][0];
			dp[i][1] = dp[i - 1][0] + a[i].back() - pos[0];
		} else if (pos[0] > a[i].back()) {
			dp[i][0] = dp[i - 1][0] + pos[0] - a[i][0];
			dp[i][1] = dp[i - 1][0] + pos[0] + a[i].back() - a[i][0] * 2;
		} else {
			dp[i][0] = dp[i - 1][0] + a[i].back() * 2 - pos[0] - a[i][0];
			dp[i][1] = dp[i - 1][0] + pos[0] + a[i].back() - a[i][0] * 2;
		}
		if (pos[1] < a[i][0]) {
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i].back() * 2 - pos[1] - a[i][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i].back() - pos[1]);
		} else if (pos[1] > a[i].back()) {
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + pos[1] - a[i][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + pos[1] + a[i].back() - a[i][0] * 2);
		} else {
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i].back() * 2 - pos[1] - a[i][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + pos[1] + a[i].back() - a[i][0] * 2);
		}
		pos[0] = a[i][0];
		pos[1] = a[i].back();
	}
	printf("%lld\n", min(dp[n][0] + abs(pos[0]), dp[n][1] + abs(pos[1])));
	return 0;
}
