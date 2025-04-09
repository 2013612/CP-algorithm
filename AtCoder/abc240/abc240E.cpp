#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> graph[200006];
bool v[200006];
pii ans[200006];
int now = 1;

pii dfs(int node) {
	v[node] = true;
	int mini = 1e9;
	int maxi = -1;
	for (auto x : graph[node]) {
		if (!v[x]) {
			pii t = dfs(x);
			mini = min(mini, t.first);
			maxi = max(maxi, t.second);
		}
	}
	if (maxi == -1) {
		mini = maxi = now;
		now++;
	}
	ans[node] = {mini, maxi};
	return ans[node];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
