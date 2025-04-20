#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct FlowEdge {
	int u, v;
	long long cap, flow = 0;
	FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
	int n, m = 0;
	int s, t;
	vector<FlowEdge> edges;
	vector<int> level, unfill;
	vector<vector<int>> adj;
	
	Dinic(int n, int s, int t, vector<FlowEdge> new_edges) : n(n), s(s), t(t) {
		level.resize(n);
		unfill.resize(n);
		adj.resize(n);
		
		for (auto x: new_edges) {
			edges.emplace_back(x.u, x.v, x.cap);
			edges.emplace_back(x.v, x.u, 0);
			adj[x.u].push_back(m);
			adj[x.v].push_back(m + 1);
			m += 2;
		}
	}
	
	void build_level() {
		fill(level.begin(), level.end(), -1);
		level[s] = 0;
		queue<int> q;
		q.push(s);
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (int v: adj[u]) {
				if (edges[v].cap == edges[v].flow || level[edges[v].v] != -1) {
					continue;
				}
				
				level[edges[v].v] = level[u] + 1;
				q.push(edges[v].v);
			}
		}
	}
	
	long long flow(int node, long long maxi) {
		if (maxi == 0) {
			return 0;
		}
		
		if (node == t) {
			return maxi;
		}
		
		long long sum = 0;
		for (int &ind = unfill[node]; ind < adj[node].size(); ind++) {
			int id = adj[node][ind];
			if (edges[id].cap == edges[id].flow) {
				continue;
			}
			
			if (level[edges[id].v] != level[node] + 1) {
				continue;
			}
			
			long long real_flow = flow(edges[id].v, min(maxi - sum, edges[id].cap - edges[id].flow));
			edges[id].flow += real_flow;
			edges[id ^ 1].flow -= real_flow;
			sum += real_flow;
			
			if (sum == maxi) {
				break;
			}
		}
		
		return sum;
	}
	
	long long max_flow() {
		long long ans = 0;
		build_level();
		while (level[t] != -1) {
			fill(unfill.begin(), unfill.end(), 0);
			
			ans += flow(s, 1e18);
			build_level();
		}
		
		return ans;
	}
};

vector<FlowEdge> edges;

int main() {
	int n;
	scanf("%d", &n);
	long long a[310][2], b[310][2];
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &b[i][0], &b[i][1]);
	}
	
	int s = 2 * n;
	int t = 2 * n + 1;
	
	long double l = 0;
	long double r = 2e18;
	
	while ((r - l) / l > 1e-7) {
		long double mid = (l + r) / 2;
		edges.clear();
		
		for (int i = 0; i < n; i++) {
			edges.emplace_back(s, i, 1);
			edges.emplace_back(n + i, t, 1);
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				long double dx = a[i][0] - b[j][0];
				long double dy = a[i][1] - b[j][1];
				if (dx * dx + dy * dy <= mid * mid) {
					edges.emplace_back(i, n + j, 1);
				}
			}
		}
		
		Dinic g(t + 1, s, t, edges);
		long long f = g.max_flow();
		
		if (f == n) {
			r = mid;
		} else {
			l = mid;
		}
	}

	printf("%.9Lf\n", l);
	return 0;
}