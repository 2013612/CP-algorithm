#include<bits/stdc++.h>
using namespace std;

int n, m, a[300005];
vector<pair<int, long long>> g[20];
long long ans;
set<int> s;

void dfs(int node, long long cur) {
//	printf("@@ %d %lld\n", node, cur);
	if (node == n) {
		ans = min(ans, cur);
		return;
	}
	
	for (auto x: g[node]) {
//		printf("!! %d %d %lld\n", node, x.first, x.second);
		if (!s.count(x.first)) {
			s.insert(x.first);
			dfs(x.first, cur ^ x.second);
			s.erase(x.first);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	ans = 4e18;
	for (int i = 0; i < m; i++) {
		int u, v;
		long long w;
		scanf("%d %d %lld", &u, &v, &w);
		
//		printf("!! %d %d %lld\n", u, v, w);
		
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	s.insert(1);
	
	dfs(1, 0);
	
	printf("%lld\n", ans);
	return 0;
}