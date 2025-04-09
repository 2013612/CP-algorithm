#include<bits/stdc++.h>
using namespace std;

int n, ans, a[300005], dp[103][103][103];
set<pair<int, int>> s;

int main() {
	scanf("%d", &n);
	
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j][k] = 1e8;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i][i][0] = 0;
	}
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		dp[u][v][0] = 1;
		dp[v][u][0] = 1;
	}
	
	
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dp[i][j][n] != 1 && (dp[i][j][n] & 1)) {
				s.insert({i, j});
			}
		}
	}
	
	if (s.size() & 1) {
		cout << "First" << endl;
		
		auto x = *(s.begin());
		
		cout << x.first << " " << x.second << endl;
		
		s.erase(x);
		
	} else {
		cout << "Second" << endl;
	}
	
	while (true) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		if (x == -1 && y == -1) {
			break;
		}
		
		if (x > y) {
			swap(x, y);
		}
		
		s.erase({x, y});
		
		auto z = *(s.begin());
		
		cout << z.first << " " << z.second << endl;
		
		s.erase(z);
	}
	
	return 0;
}