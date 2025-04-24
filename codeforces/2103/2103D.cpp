#include<bits/stdc++.h>
using namespace std;

int n, a[300005];
unordered_set<int> us[300005];
vector<int> g[300005];
vector<pair<int, int>> v, v2;

vector<bool> visited;
vector<int> ans, res;

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    res.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    res.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
//    reverse(res.begin(), res.end());
}

void add_edge(int i, int j) {
	if (i & 1) {
		if (j == 0) {
			if (v[j].first == i) {
				us[v[j].second].insert(v[j + 1].second);
			} else {
				us[v[j + 1].second].insert(v[j].second);
			}
		} else if (j + 1 == v.size()) {
			if (v[j].first == i) {
				us[v[j].second].insert(v[j - 1].second);
			} else {
				us[v[j - 1].second].insert(v[j].second);
			}
		} else {
			if (v[j].first == i) {
				if (us[v[j - 1].second].count(v[j].second)) {
					us[v[j].second].insert(v[j + 1].second);
				}
			} else {
				us[v[j + 1].second].insert(v[j].second);
				us[v[j - 1].second].insert(v[j].second);
			}
		}
	} else {
		if (j == 0) {
			if (v[j].first == i) {
				us[v[j + 1].second].insert(v[j].second);
			} else {
				us[v[j].second].insert(v[j + 1].second);
			}
		} else if (j + 1 == v.size()) {
			if (v[j].first == i) {
				us[v[j - 1].second].insert(v[j].second);
			} else {
				us[v[j].second].insert(v[j - 1].second);
			}
		} else {
			if (v[j].first == i) {
				if (us[v[j].second].count(v[j - 1].second)) {
					us[v[j + 1].second].insert(v[j].second);
				}
			} else {
				us[v[j].second].insert(v[j + 1].second);
				us[v[j].second].insert(v[j - 1].second);
			}
		}
	}
}

void add_edge_rev(int i, int j) {
	if (i & 1) {
		if (us[v[j + 1].second].count(v[j].second)) {
			us[v[j].second].insert(v[j - 1].second);
		}
	} else {
		if (us[v[j].second].count(v[j + 1].second)) {
			us[v[j - 1].second].insert(v[j].second);
		}
	}
}

void solve() {
	scanf("%d", &n);
	ans.resize(n);
	
	v.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		g[i].clear();
		us[i].clear();
		v.push_back({a[i], i});
	}
	
	
	for (int i = 1; v.size() > 1; i++) {
		v2.clear();
		for (int j = 0; j < v.size(); j++) {
			add_edge(i, j);
			
			if (v[j].first != i) {
				v2.push_back(v[j]);
			}
		}
		for (int j = v.size() - 2; j >= 1; j--) {
			if (v[j].first == i) {
				add_edge_rev(i, j);
			}
		}
		
		for (int j = 1; j + 1 < v.size(); j++) {
			if (v[j].first == i) {
				if (i & 1) {
					if (!us[v[j].second].count(v[j - 1].second) && !us[v[j].second].count(v[j + 1].second)) {
						us[v[j].second].insert(v[j + 1].second);
					}
				} else {
					if (!us[v[j - 1].second].count(v[j].second) && !us[v[j + 1].second].count(v[j].second)) {
						us[v[j + 1].second].insert(v[j].second);
					}
				}
			}
		}
		
		v = v2;
	}
	
	for (int i = 0; i < n; i++) {
		for (auto x: us[i]) {
			g[i].push_back(x);
		}
	}
	
	topological_sort();
	
	for (int i = 0; i < n; i++) {
		ans[res[i]] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}