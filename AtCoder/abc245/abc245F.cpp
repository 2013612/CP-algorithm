#include<iostream>
#include<vector>
using namespace std;

int n, m, color[200006], parent[200006], ans;
vector<int> edge[200006];
bool can[200006];

bool dfs(int v) {
	color[v] = 1;
	bool is_cycle = false;
	for (int u: edge[v]) {
		if (color[u] == 0) {
			is_cycle = is_cycle || dfs(u);
		} else if (color[u] == 1) {
			is_cycle = true;
		}
		if (can[u]) {
			is_cycle = true;
		}
	}
	can[v] = can[v] || is_cycle;
	color[v] = 2;
	return can[v];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (can[i]) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
