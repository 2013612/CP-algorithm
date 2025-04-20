#include<bits/stdc++.h>
using namespace std;

int n, m, d[200005];
vector<int> g[200005];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	priority_queue<int> pq;
	pq.push(-1);
	d[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		d[i] = 1e9;
	}
	
	while (!pq.empty()) {
		int cur = -pq.top();
		pq.pop();
		
		for (auto x: g[cur]) {
			if (d[x] > 1e8) {
				d[x] = max(d[cur], x);
				pq.push(-x);
			}
		}
	}
	
	set<int> s;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		s.erase(i);
		for (auto x: g[i]) {
			if (x > i) {
				s.insert(x);
			}
		}
		
		cur = max(cur, d[i]);
		
		if (cur <= i) {
			printf("%d\n", s.size());
		} else {
			printf("-1\n");
		}
	}
	return 0;
}