#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, q, parent[20][100006], depth[100006];
vector<int> g[100006];

int f(int node, int num) {
	for (int i = 0; num > 0; i++) {
		if (num & 1) {
			node = parent[i][node];
		}
		num >>= 1;
	}
	return node;
}

int main() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 100006; j++) {
			parent[i][j] = -1;
			depth[j] = -1;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<int> qu;
	qu.push(1);
	depth[1] = 0;
	while (!qu.empty()) {
		int t = qu.front();
		qu.pop();
		for (auto x : g[t]) {
			if (depth[x] == -1) {
				depth[x] = depth[t] + 1;
				parent[0][x] = t;
				qu.push(x);
			}
		}
	}
	
	for (int i = 1; (1 << i) < n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][max(parent[i - 1][j], 1)];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		int ans = 0;
		int d = depth[v] - depth[u];
		for (int i = 0; d > 0; i++) {
			if (d & 1) {
				v = parent[i][v];
				ans += 1 << i;
			}
			d >>= 1;
		}
		
		for (int j = 19; j >= 0; j--) {
			if (parent[j][u] != parent[j][v]) {
				u = parent[j][u];
				v = parent[j][v];
				ans += 1 << (j + 1);
			}
		}
		
		printf("%d\n", u == v ? ans + 1 : ans + 3);
	}
	return 0;
}