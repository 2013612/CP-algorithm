#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int x[4] = {1, 0, -1, 0};
const int y[4] = {0, 1, 0, -1};

int n, m, a[1003][1003], ans, b[600005];

void solve() {
	scanf("%d %d", &n, &m);
	ans = 0;
	
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			a[i][j] = 0;
		}
	}
	
	int maxi = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			maxi = max(maxi, a[i][j]);
		}
	}
	
	for (int i = 1; i <= maxi; i++) {
		b[i] = 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[a[i][j]] = 1;
		}
	}
	
	bool can = false;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				if (a[i + x[k]][j + y[k]] == a[i][j]) {
					b[a[i][j]] = 2;
					can = true;
				}
			}
		}
	}
	
	for (int i = 1; i <= maxi; i++) {
		ans += b[i];
	}
	
	ans--;
	
	if (can) {
		ans--;
	}
	
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}