#include<iostream>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>> edge[200006];
long long sum;
int deep_node;
long long deep_depth;
bool v[200006];

void dfs(int node, long long depth) {
	if (depth > deep_depth) {
		deep_node = node;
		deep_depth = depth;
	}
	
	v[node] = true;
	
	for (int i = 0; i < edge[node].size(); i++) {
		if (!v[edge[node][i].first]) {
			dfs(edge[node][i].first, depth + edge[node][i].second);
		}
	}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
		sum += 2ll * c;
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		v[i] = false;
	}
	dfs(deep_node, 0);
	
	printf("%lld\n", sum - deep_depth);
	
	return 0;
}