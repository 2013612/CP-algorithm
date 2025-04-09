#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, ans;
bool v[200006];
long long a[200006], b[200006], offset;
vector<int> g[200006];

long long dfs(int node) {
	v[node] = true;
	
	long long st = a[node];
	vector<long long> p;
	for (auto x: g[node]) {
		if (!v[x]) {
			long long t = dfs(x);
			st = max(st, t);
			p.push_back(t);
		}
	}
	
	st = min(st, b[node]);
	for (auto x: p) {
		if (x > st) {
			offset += x - st;
		}
	}
	
	return st;
}

void solve() {
	scanf("%d", &n);
	
	offset = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		g[i].clear();
		v[i] = false;
	}
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	printf("%lld\n", dfs(0) + offset);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}