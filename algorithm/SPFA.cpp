#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct SPFA {
	int n;
	vector<vector<pair<int, long long>>> g;
	vector<long long> dis, pre, fre;
	
	SPFA(int n, vector<vector<pair<int, long long>>> g): n(n), g(g) {
		dis.resize(n);
		pre.resize(n);
		fre.resize(n);
	}
	
	bool find(int start) {
		for (int i = 0; i < n; i++) {
			dis[i] = 1e18;
			pre[i] = -1;
			fre[i] = 0;
		}
		
		dis[start] = 0;
		unordered_set<int> us;
		us.insert(start);
		
		while (us.size()) {
			int u = *us.begin();
			us.erase(u);
			
			fre[u]++;
			
			if (fre[u] >= n) {
				return false;
			}
			
			for (auto [v, w]: g[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					pre[v] = u;
					us.insert(v);
				}
			}
		}
		
		return true;
	}
};

// abc404G
int n, m;
vector<vector<pair<int, long long>>> g;

int main() {
	scanf("%d %d", &n, &m);
	
	g.resize(n + 1);
	
	for (int i = 0; i < n; i++) {
		g[i + 1].push_back({i, -1});
	}
	
	for (int i = 0; i < m; i++) {
		int l, r, s;
		scanf("%d %d %d", &l, &r, &s);
		
		g[l - 1].push_back({r, s});
		g[r].push_back({l - 1, -s});
	}
	
	SPFA spfa = SPFA(n + 1, g);
	
	if (spfa.find(n)) {
		printf("%lld\n", -spfa.dis[0]);
	} else {
		printf("-1\n");
	}
	
	return 0;
}