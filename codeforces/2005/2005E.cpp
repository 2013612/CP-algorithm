#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int l, n, m;
int a[200006], b[400][400], ans;
vector<pair<int, int>> v[10];
map<pair<int, pair<int, int>>, bool> dp;

bool dfs(pair<int, pair<int, int>> node) {
	if (dp.count(node)) {
		return dp[node];
	}
	
	int cur = node.first;
	int num = a[cur];
	int p = node.second.first;
	int q = node.second.second;
	
	if (cur >= l) {
		return false;
	}
	
	bool can = true;
	
	for (int i = 0; i < v[num].size(); i++) {
		if (v[num][i].first <= p || v[num][i].second <= q) {
			continue;
		}
		can = dfs({cur + 1, v[num][i]}) && can;
	}
	
	dp[node] = !can;
	
//	printf("! %d %d %d %d\n", node.first, node.second.first, node.second.second, dp[node]);
	return dp[node];
}

void solve() {
	scanf("%d %d %d", &l, &n, &m);
	
	dp.clear();
	for (int i = 1; i <= 7; i++) {
		v[i].clear();
	}
	for (int i = 0; i < l; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
			
			while (!v[b[i][j]].empty() && v[b[i][j]].back().second < j) {
				v[b[i][j]].pop_back();
			}
			
			v[b[i][j]].push_back({i, j});
		}
	}
	
	if (dfs({0, {-1, -1}})) {
		cout << "T" << endl;
	} else {
		cout << "N" << endl;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}