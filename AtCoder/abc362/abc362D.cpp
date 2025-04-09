#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, a[200006];
vector<pair<int, int>> edge[200006];
long long dis[200006];
priority_queue<pair<long long, int>> pq;
bool v[200006];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dis[i] = 4e18;
	}
	
	dis[0] = a[0];
	
	for (int i = 0; i < m; i++) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		u--;
		v--;
		edge[u].push_back({b, v});
		edge[v].push_back({b, u});
	}
	
	pq.push({0, 0});
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (v[u]) {
			continue;
		}
		v[u] = true;
		
		for (auto [d, v]: edge[u]) {
			if (dis[u] + d + a[v] < dis[v]) {
				dis[v] = dis[u] + d + a[v];
				pq.push({-dis[v], v});
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		printf("%lld ", dis[i]);
	}
	printf("\n");
	
	return 0;
}