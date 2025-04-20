#include<bits/stdc++.h>
using namespace std;

int n[2], dia[2], cur_g, cur_v;
vector<int> d[2], g[2][200005], v[2];
vector<long long> pre;
long long ans;

void dfs(int node) {
	for (auto x: g[cur_g][node]) {
		if (v[cur_v][x] > 1e8) {
			v[cur_v][x] = v[cur_v][node] + 1;
			dfs(x);
		}
	}
}

void find1(int f) {
	cur_g = f;
	
	scanf("%d", &n[f]);
	d[f].resize(n[f] + 1);
	for (int i = 0; i < n[f] - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[f][u].push_back(v);
		g[f][v].push_back(u);
	}
	
	int a = 1, b = 1;
	{
		cur_v = 0;
		v[0] = vector<int>(d[f].size(), 1e9);
		v[0][1] = 0;
		
		dfs(1);
		
		for (int i = 1; i < v[0].size(); i++) {
			if (v[0][i] > v[0][a]) {
				a = i;
			}
		}
	}
	
	{
		v[0] = vector<int>(d[f].size(), 1e9);
	
		v[0][a] = 0;
		dfs(a);
		
		for (int i = 1; i < d[f].size(); i++) {
			if (v[0][i] > v[0][b]) {
				b = i;
			}
		}
		
		cur_v = 1;
		v[1] = vector<int>(d[f].size(), 1e9);
		v[1][b] = 0;
		dfs(b);
		
		for (int i = 1; i < d[f].size(); i++) {
			d[f][i] = max(v[0][i], v[1][i]);
			dia[f] = max(dia[f], d[f][i]);
		}
	}
}

int main() {	
	find1(0);
	find1(1);
	
	pre.resize(n[1] + 1);
	int max_dia = max(dia[0], dia[1]);
	
	sort(d[1].begin(), d[1].end());
	
	for (int i = 1; i <= n[1]; i++) {
		pre[i] = pre[i - 1] + d[1][i];
	}
	
	for (int i = 1; i <= n[0]; i++) {
		int pos = lower_bound(d[1].begin() + 1, d[1].end(), max_dia - d[0][i] - 1) - d[1].begin();
		ans += 1ll * (pos - 1) * max_dia + pre[n[1]] - pre[pos - 1] + 1ll * (n[1] - pos + 1) * (d[0][i] + 1);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}