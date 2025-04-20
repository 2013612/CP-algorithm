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
	int n, m;
	scanf("%d %d", &n, &m);
	string p[103];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	int s = n * m;
	int t = n * m + 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int node = i * m + j;
			if ((i + j) & 1) {
				edges.emplace_back(node, t, 1);
			} else {
				edges.emplace_back(s, node, 1);
			}
			
			if (i + 1 < n) {
				if (p[i][j] == '.' && p[i + 1][j] == '.') {
					if ((i + j) & 1) {
						edges.emplace_back(node + m, node, 1);
					} else {
						edges.emplace_back(node, node + m, 1);
					}
				}
			}
			
			if (j + 1 < m) {
				if (p[i][j] == '.' && p[i][j + 1] == '.') {
					if ((i + j) & 1) {
						edges.emplace_back(node + 1, node, 1);
					} else {
						edges.emplace_back(node, node + 1, 1);
					}
				}
			}
		}
	}
	
	Dinic g(n * m + 100, s, t, edges);
	g.max_flow();
	int cnt = 0;
	for (auto x: g.edges) {
		if (x.u == s || x.v == t || x.flow != 1) {
			continue;
		}
		
		int ui = x.u / m;
		int uj = x.u % m;
		int vi = x.v / m;
		int vj = x.v % m;
		
		if (ui > vi) {
			swap(ui, vi);
		}
		
		if (uj > vj) {
			swap(uj, vj);
		}
		
		if (ui == vi) {
			p[ui][uj] = '>';
			p[vi][vj] = '<';
		} else {
			p[ui][uj] = 'v';
			p[vi][vj] = '^';
		}
		cnt++;
	}
	
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		cout << p[i] << endl;
	}
}