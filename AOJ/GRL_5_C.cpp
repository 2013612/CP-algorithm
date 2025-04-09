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
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int c;
			scanf("%d", &c);
			g[i].push_back(c);
			parent[0][c] = i;
		}
	}
	queue<int> qu;
	qu.push(0);
	depth[0] = 0;
	while (!qu.empty()) {
		int t = qu.front();
		qu.pop();
		for (auto x : g[t]) {
			if (depth[x] == -1) {
				depth[x] = depth[t] + 1;
				qu.push(x);
			}
		}
	}
	
	for (int i = 1; (1 << i) < n; i++) {
		for (int j = 0; j < n; j++) {
			parent[i][j] = parent[i - 1][max(parent[i - 1][j], 0)];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		int d = depth[v] - depth[u];
		v = f(v, d);
		
		for (int j = 19; j >= 0; j--) {
			if (parent[j][u] != parent[j][v]) {
				u = parent[j][u];
				v = parent[j][v];
			}
		}
		
		printf("%d\n", u == v ? u : parent[0][u]);
	}
	return 0;
}