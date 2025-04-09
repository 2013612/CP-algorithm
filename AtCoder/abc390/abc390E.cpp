#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, dp[3][5003][5003], ans;
vector<pair<int, int>> b[3];

int main() {
	scanf("%d %d", &n, &x);
	
	for (int i = 0; i < n; i++) {
		int v, a, c;
		scanf("%d %d %d", &v, &a, &c);
		b[v - 1].push_back({c, a});
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < b[i].size(); j++) {
			for (int k = 0; k <= x; k++) {
				if (k > 0) {
					dp[i][j + 1][k] = max({dp[i][j + 1][k], dp[i][j + 1][k - 1], dp[i][j][k]});
				}
				
				if (k + b[i][j].first <= x) {
					dp[i][j + 1][k + b[i][j].first] = max(dp[i][j + 1][k + b[i][j].first], dp[i][j][k] + b[i][j].second);
				}
			}
		}
	}
	
	int l = 0, r = 1e9 + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		int t = 0;
		for (int i = 0; i < 3; i++) {
			int pos = lower_bound(dp[i][b[i].size()], dp[i][b[i].size()] + x + 1, mid) - dp[i][b[i].size()];
			
			t += pos;
		}
		
		if (t <= x) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	printf("%d\n", l);
	
	return 0;
}