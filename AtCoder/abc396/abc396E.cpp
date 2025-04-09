#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

int n, m, a[300005], x[200005], y[200005], z[200005];
int v[200005][2];
bool v2[200005];
vector<int> g[200005];
unordered_map<int, vector<int>> gps;
long long ans;

dsu d;

int dfs(int node, int cur, int st) {
	int cnt = 0;
	if (cur) {
//		printf("@ %d %d %d %d\n", node, cur, st, d.size(node));
		cnt += d.size(node);
	}
	
	v[node][st] = cur;
	
	for (auto x: g[node]) {
		if (v[x][st] == -1) {
			cnt += dfs(x, 1 - cur, st);
		} else if (v[x][st] != 1 - cur) {
			ans = -1;
			return 0;
		}
	}
	
	return cnt;
}

void dfs2(int node, int cur, int bit) {
//	printf("# dfs2 %d %d %d %d\n", node, cur, gps[node].size(), d.size(node));
	if (cur) {
		for (auto x: gps[node]) {
			a[x] += bit;
		}
	}
	
	v2[node] = true;
	
	for (auto x: g[node]) {
//		printf("# %d %d %d\n", node, v2[x], x);
		if (!v2[x]) {
			dfs2(x, 1 - cur, bit);
		}
	}
}

void solve(int bit) {
	d = dsu(n);
	
	for (int i = 0; i < n; i++) {
		g[i].clear();
		v[i][0] = v[i][1] = -1;
		v2[i] = false;
		gps = unordered_map<int, vector<int>>();
	}
	for (int i = 0; i < m; i++) {
		if (!(z[i] & bit)) {
			d.merge(x[i], y[i]);
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (z[i] & bit) {
			int dx = d.leader(x[i]);
			int dy = d.leader(y[i]);
			
			if (dx == dy) {
				ans = -1;
				return;
			}
			
			g[dx].push_back(dy);
			g[dy].push_back(dx);
		}
	}
	
	auto x = d.groups();
	
	for (auto y: x) {
		gps[d.leader(y[0])] = y;
	}
	
	for (int i = 0; i < n; i++) {
		if (d.leader(i) != i) {
			continue;
		}
		if (v[i][0] == -1) {
			int k0 = dfs(i, 0, 0);
			int k1 = dfs(i, 1, 1);
			
//			printf("$ %d %d %d\n", i, k0, k1);
			
			if (k0 <= k1) {
				dfs2(i, 0, bit);
			} else {
				dfs2(i, 1, bit);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		x[i]--;
		y[i]--;
	}
	
	for (int i = 0; i < 31; i++) {
		solve(1 << i);
	}
	
	if (ans == -1) {
		printf("-1\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
	printf("\n");
	return 0;
}