#include<iostream>
#include<vector>
using namespace std;

int n;
long long ans;
vector<int> edge[200006];
bool visited[200006];

int dfs(int node) {
	visited[node] = true;
	
	vector<int> cnt;
	int next_2 = 0;
	for (int i = 0; i < edge[node].size(); i++) {
		if (!visited[edge[node][i]]) {
			cnt.push_back(dfs(edge[node][i]));
			if (edge[edge[node][i]].size() == 2) {
				next_2++;
			}
		}
	}
	
	if (edge[node].size() == 2) {
		for (auto x: cnt) {
			ans += x;
		}
		ans -= next_2;
		return 1;
	} else if (edge[node].size() == 3) {
		int sum = 0;
		for (auto x: cnt) {
			ans += 1ll * x * sum;
			sum += x;
		}
		return sum;
	} else {
		return 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	dfs(1);
	
	printf("%lld\n", ans);
	
	return 0;
}