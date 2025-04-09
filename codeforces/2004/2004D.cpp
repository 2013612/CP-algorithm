#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n, q, a[200006];
map<string, vector<int>> m;
map<string, int> m2;

void solve() {
	scanf("%d %d", &n, &q);
	m.clear();
	m2["BG"] = 1 + 2;
	m2["BR"] = 1 + 4;
	m2["BY"] = 1 + 8;
	m2["GR"] = 2 + 4;
	m2["GY"] = 2 + 8;
	m2["RY"] = 4 + 8;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i] = m2[s];
		m[s].push_back(i);
	}
	
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		x--;
		y--;
		
		if (x > y) {
			swap(x, y);
		}
		
//		printf("! %d %d %d %d\n", i, a[x], a[y], a[x] & a[y]);
		if (a[x] & a[y]) {
			printf("%d\n", y - x);
			continue;
		}
		
		int ans = 2e9;
		
		for (auto [s, k]: m2) {
			if (a[x] == k || (a[x] & k) == 0) {
				continue;
			}
			
			int pos = lower_bound(m[s].begin(), m[s].end(), x) - m[s].begin();
			if (pos != m[s].size()) {
				ans = min(ans, abs(m[s][pos] - x) + abs(m[s][pos] - y));
			}
			if (pos != 0) {
				ans = min(ans, abs(m[s][pos - 1] - x) + abs(m[s][pos - 1] - y));
			}
		}
		
		if (ans > 1e9) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}