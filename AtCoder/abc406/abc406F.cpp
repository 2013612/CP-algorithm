#include<iostream>
#include<vector>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, q, edge[300005][2], tin[300005], tout[300005], par[300005], t;
vector<int> v[300005];

int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

void dfs(int cur, int p) {
	par[cur] = p;
	
	tin[cur] = t;
	t++;
	
	for (auto x: v[cur]) {
		if (x != par[cur]) {
			dfs(x, cur);
		}
	}
	
	tout[cur] = t;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &edge[i][0], &edge[i][1]);
		edge[i][0]--;
		edge[i][1]--;
		v[edge[i][0]].push_back(edge[i][1]);
		v[edge[i][1]].push_back(edge[i][0]);
	}
	
	t = 0;
	dfs(0, 0);
	
	segtree<int, f, e> seg(vector<int>(n, 1));
	
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		
		if (t == 1) {
			int x, w;
			scanf("%d %d", &x, &w);
			x--;
			
			seg.set(tin[x], seg.get(tin[x]) + w);
		} else {
			int y;
			scanf("%d", &y);
			y--;
			
			int x = edge[y][1];
			if (par[edge[y][0]] == edge[y][1]) {
				x = edge[y][0];
			}
			
			int all = seg.all_prod();
			int child = seg.prod(tin[x], tout[x]);
			printf("%d\n", abs(all - 2 * child));
		}
	}
	
	return 0;
}