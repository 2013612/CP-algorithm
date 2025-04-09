#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pii;

int N, M, K, a[1004];
vector<int> edge[1004];
long long ans;
map<pii, int> m;
unordered_map<long long, long long> um[3004];
bool visited[1004];

bool dfs(int node, int start, int end) {
	if (node == end) {
		return true;
	}
	visited[node] = true;
	bool path = false;
	for (auto x:edge[node]) {
		if (!visited[x]) {
			bool temp = dfs(x, start, end);
			if (temp) {
				m[{min(node, x), max(node, x)}]++;
			}
			path = path || temp;
		}
	}
	return path;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i < M; i++) {
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		dfs(a[i - 1], a[i - 1], a[i]);
	}
	um[0][15000] = 1;
	int cnt = 1;
	for (auto x:m) {
		for (auto y:um[cnt - 1]) {
			um[cnt][y.first + x.second] = (um[cnt][y.first + x.second] + y.second) % 998244353;
			um[cnt][y.first - x.second] = (um[cnt][y.first - x.second] + y.second) % 998244353;
		}
		cnt++;
	}
	ans = um[cnt - 1][15000 + K];
	for (int i = 0; i < (N - 1) - m.size(); i++) {
		ans = (ans * 2) % 998244353;
	}
	printf("%lld\n", ans);
	return 0;
}
