#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int n, m, a[200005], b[200005], ans;
set<int> edge[200005], c;
map<pair<int, int>, int> edge_ind;
vector<int> can;
bool v[200005];

void dfs(int cur, int prev) {
	v[cur] = true;
	
	for (auto x: edge[cur]) {
		if (x == prev) {
			continue;
		}
		if (v[x]) {
			pair<int, int> y = {min(cur, x), max(cur, x)};
			if (edge_ind.count(y)) {
				can.push_back(edge_ind[y]);
				edge_ind.erase(y);
			}
		} else {
			dfs(x, cur);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
//	n = 2e5;
//	m = 2e5 - 1;
	
	dsu d = dsu(n + 1);
	
	for (int i = 1; i <= m; i++) {
//		a[i] = i + 1;
//		b[i] = i + 2;
		scanf("%d %d", &a[i], &b[i]);
		
		if (b[i] < a[i]) {
			swap(a[i], b[i]);
		}
		
		d.merge(a[i], b[i]);
		
		if (!edge[a[i]].count(b[i]) && a[i] != b[i]) {
			edge_ind[{a[i], b[i]}] = i;
			edge[a[i]].insert(b[i]);
			edge[b[i]].insert(a[i]);
		} else {
			can.push_back(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			c.insert(d.leader(i));
			dfs(i, -1);
		}
	}
	
	ans = c.size() - 1;
	printf("%d\n", ans);
	
	for (int i = 0; i < ans; i++) {
		int ind = can[i];
		int x = d.leader(a[ind]);
		int y = *c.begin();
		if (d.leader(y) == x) {
			y = *c.rbegin();
		}
		
		printf("%d %d %d\n", ind, a[ind], y);
		
		d.merge(x, y);
		c.erase(y);
	}
	
	
	return 0;
}