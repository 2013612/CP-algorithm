#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[400006];

int n, in[400006], out[400006];
bool v[400006];
vector<vector<int>> adj;
vector<int> inout, pre, suf;

void dfs(int node) {
	v[node] = true;
	inout.push_back(a[node]);
	in[node] = inout.size() - 1;
	
	for (auto x: adj[node]) {
		if (!v[x]) {
			dfs(x);
		}
	}
	inout.push_back(a[node]);
	out[node] = inout.size() - 1;
}

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &a[i]);
		v[i] = false;
	}
	
	inout.clear();
	adj.clear();
	
	adj.assign(n, vector<int>());
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0);
	
	int k = inout.size();
	pre.resize(k + 1);
	suf.resize(k + 1);
	pre[0] = 0;
	suf[k] = 0;
	
	for (int i = 0; i < k; i++) {
		pre[i + 1] = max(pre[i], inout[i]);
		suf[k - i - 1] = max(suf[k - i], inout[k - i - 1]);
	}
	
	int ans = -1;
	int cur = -1;
	
	for (int i = 0; i < n; i++) {
		if (a[i] < max(pre[in[i]], suf[out[i]]) && cur < a[i]) {
			ans = i;
			cur = a[i];
		}
	}

	printf("%d\n", ans + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}