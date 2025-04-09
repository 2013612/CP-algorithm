#include<iostream>
#include<vector>
using namespace std;

int t, n;
long long f[100006], ans;
vector<int> edge[100006];

long long dfs(int node) {
	if (edge[node].empty()) {
		ans += f[node];
		return f[node];
	}
	
	long long mini = 1e15;
	for (auto x : edge[node]) {
		long long temp = dfs(x);
		mini = min(mini, temp);
	}
	
	ans += max(f[node] - mini, 0ll);
	return max(mini, f[node]);
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &f[j]);
		}
		for (int j = 0; j <= n; j++) {
			edge[j].clear();
		}
		for (int j = 1; j <= n; j++) {
			int p;
			scanf("%d", &p);
			edge[p].push_back(j);
		}
		ans = 0;
		dfs(0);
		printf("Case #%d: %lld\n", i, ans);
	}
}
