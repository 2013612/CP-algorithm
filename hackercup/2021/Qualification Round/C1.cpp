#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans, m[100];
vector<int> edge[100];
bool visited[100];

int dfs(int node, int sum) {
	visited[node] = true;
	vector<int> num = {0, 0};
	for (auto x:edge[node]) {
		if (!visited[x]) {
			int temp = dfs(x, sum + m[node]);
			num.push_back(temp);
		}
	}
	sort(num.begin(), num.end(), greater<int>());
	if (node == 1) {
		ans = max(ans, sum + m[node] + num[0] + num[1]);
	}
	
	return m[node] + num[0];
}

int main() {
	freopen("gold_mine_chapter_1_input.txt", "r", stdin);
	freopen("gold_mine_chapter_1_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		ans = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[j]);
			edge[j].clear();
			visited[j] = false;
		}
		for (int j = 0; j < N - 1; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		dfs(1, 0);
		printf("Case #%d: %d\n", i, ans);
	}
}
