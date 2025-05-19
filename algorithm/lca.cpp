#include<iostream>
#include<vector>
using namespace std;

struct LCA {
	int n, l, root;
	vector<vector<int>> adj;

	int timer;
	vector<int> tin, tout;
	vector<vector<int>> up;
	
	LCA(): n(n), root(root), adj(adj) {
		tin.resize(n);
	    tout.resize(n);
	    timer = 0;
	    
	    {
	    	l = n > 1;
	    	int temp = n - 1;
	    	while (temp > 1) {
	    		l++;
	    		temp /= 2;
			}
		}
	    up.assign(n, vector<int>(l + 1));
	    dfs(root, root);
	}
	
	void dfs(int cur, int par) {
		timer++;
		tin[cur] = timer;
		up[cur][0] = par;
		for (int i = 1; i <= l; i++) {
			up[cur][i] = up[up[cur][i - 1]][i - 1];
		}
		
		for (int next: adj[cur]) {
			if (next != par) {
				dfs(next, cur);
			}
		}
		
		timer++;
		tout[cur] = timer;
	}
	
	bool is_ancestor(int u, int v) {
		return tin[u] <= tin[v] && tout[v] <= tout[u];
	}
	
	int lca(int u, int v) {
		if (is_ancestor(u, v)) {
			return u;
		}
		
		if (is_ancestor(v, u)) {
			return v;
		}
		
		for (int i = l; i >= 0; i--) {
			if (!is_ancestor(up[u][i], v)) {
				u = up[u][i];
			}
		}
		
		return up[u][0];
	}
};

int main() {
	
}