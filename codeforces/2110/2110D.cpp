#include<bits/stdc++.h>
using namespace std;

int n, m, b[300005];
vector<pair<int, int>> g[300005];

bool f(long long maxi) {
	vector<long long> v(n, -1);
	v[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] == -1) {
			continue;
		}
		
		long long cur = v[i];
		cur += b[i];
		cur = min(cur, maxi);
		
		for (auto [next, w]: g[i]) {
			if (w > cur) {
				continue;
			}
			
			v[next] = max(v[next], cur);
		}
	}
	
	return v[n - 1] >= 0;
}

void solve() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		g[i].clear();
	}
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;
		
		g[u].push_back({v, w});
	}
	
	long long l = 0, r = 1e10;
	
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		
		if (f(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	if (r > 2e9) {
		r = -1;
	}
	
	printf("%lld\n", r);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}