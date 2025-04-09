#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
typedef pair<int, int> pii;

int n, x[100006], q;
bool v[100006];
unordered_map<int, vector<int>> um;
vector<int> graph[100006];

void dfs(int node) {
	v[node] = true;
	vector<pii> pos;
	for (auto a : graph[node]) {
		if (!v[a]) {
			dfs(a);
			pos.push_back({a, 0});
		}
	}
	vector<int> p;
	int cnt = 20;
	bool used = false;
	for (int i = 0; i < 20; i++) {
		int k = -1;
		int l = -1;
		if (!used) {
			k = x[node];
		}
		for (int j = 0; j < pos.size(); j++) {
			if (pos[j].second >= um[pos[j].first].size()) {
				continue;
			}
			if (um[pos[j].first][pos[j].second] > k) {
				l = j;
				k = um[pos[j].first][pos[j].second];
			}
		}
		if (k < 0) {
			break;
		}
		p.push_back(k);
		if (l < 0) {
			used = true;
		} else {
			pos[l].second++;
		}
	}
	um[node] = p;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", um[a][b - 1]);
	}
	return 0;
}
