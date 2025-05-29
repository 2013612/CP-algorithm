#include<iostream>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200005][2];
map<pair<int, int>, int> rev;
vector<vector<int>> g;

struct EulerianPath {
	vector<vector<int>> graph;
	
	EulerianPath(vector<vector<int>> graph) : graph(graph) {
		
	}
	
	deque<int> findPath() {
		int st = -1, ed = -1;
		int oddCnt = 0;
		vector<unordered_set<int>> edges(graph.size());
		for (int i = 0; i < graph.size(); i++) {
			for (auto y: graph[i]) {
				edges[i].insert(y);
			}
			
			if (graph[i].size() & 1) {
				oddCnt++;
				
				if (st == -1) {
					st = i;
				} else {
					ed = i;
				}
			}
		}
		
		deque<int> path;
		
		if (oddCnt > 2) {
			return path;
		}
		
		if (oddCnt == 0) {
			st = 0;
			ed = 0;
		}
		
		path.push_back(st);
		
		int cnt = 0;
		while (path.size() < n + 1) {
			cnt = 0;
			while (edges[path.back()].empty() && cnt <= path.size()) {
				path.push_front(path.back());
				path.pop_back();
				cnt++;
			}
			
			if (cnt > path.size()) {
				break;
			}
			
			int cur = path.back();
			int next = *edges[cur].begin();			
			path.push_back(next);
			
			edges[cur].erase(next);
			edges[next].erase(cur);
		}
		
		for (int i = 0; i < path.size(); i++) {
			path.push_front(path.back());
			path.pop_back();
			if (path.front() == st && path.back() == ed) {
				break;
			}
		}
		
		return path;
	}
};

// codeforces 2110E
void solve() {
	scanf("%d", &n);
	deque<int> ans;
	
	rev.clear();
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		
		a[i][1] += 1e9;
		v.push_back(a[i][0]);
		v.push_back(a[i][1]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	unordered_map<int, int> um;
	for (int i = 0; i < v.size(); i++) {
		um[v[i]] = i;
	}
	
	g.clear();
	g.resize(v.size());
	
	for (int i = 0; i < n; i++) {
		a[i][0] = um[a[i][0]];
		a[i][1] = um[a[i][1]];
		
		rev[{a[i][0], a[i][1]}] = i + 1;
		rev[{a[i][1], a[i][0]}] = i + 1;
		
		g[a[i][0]].push_back(a[i][1]);
		g[a[i][1]].push_back(a[i][0]);
	}
	
	EulerianPath ep = EulerianPath(g);
	
	ans = ep.findPath();
	
	if (ans.size() != n + 1) {
		printf("NO\n");
		return;
	}
	
	printf("YES\n");
	for (int i = 0; i + 1 < ans.size(); i++) {
		printf("%d ", rev[{ans[i], ans[i + 1]}]);
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