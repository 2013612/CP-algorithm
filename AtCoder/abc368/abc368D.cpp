#include<iostream>
#include<vector>
using namespace std;

int n, k, ans;
vector<int> edge[200006];
bool visit[200006], a[200006];

bool dfs(int v) {
	visit[v] = true;
	bool yes = a[v];
	for (int i = 0; i < edge[v].size(); i++) {
		if (!visit[edge[v][i]]) {
			yes = dfs(edge[v][i]) || yes;
		}
	}
	
	if (yes) {
		ans++;
	}
	
	return yes;
}

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	int temp;
	
	for (int i = 0; i < k; i++) {
		int k;
		scanf("%d", &k);
		a[k] = true;
		temp = k;
	}
	
	dfs(temp);
	
	printf("%d\n", ans);
	return 0;
}