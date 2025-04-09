#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int N, M, ans;
vector<int> path[2004];
bool reach[2004][2004], visit[2004];

void dfs(int node) {
	visit[node] = true;
	ans++;
	for (auto x:path[node]) {
		if (!visit[x]) {
			dfs(x);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		path[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		for (int i = 1; i <= N; i++) {
			visit[i] = false;
		}
		dfs(i);
	}
	printf("%d\n", ans);
	return 0;
}
