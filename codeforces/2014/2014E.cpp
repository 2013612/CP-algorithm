#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int n, m, h, a[400006];
set<int> s;
vector<pair<int, int>> edge[200006];
long long dis[2][200006][2], ans;
bool visited[2][200006][2];
priority_queue<pair<long long, pair<int, int>>> pq;

void dij(int p) {
	if (p == 0) {
		pq.push({0, {1, 0}});
		dis[0][1][0] = 0;
	} else {
		pq.push({0, {n, 0}});
		dis[1][n][0] = 0;
	}
	while (!pq.empty()) {
		auto [node, horse] = pq.top().second;
		
		long long d = -pq.top().first;
		
		pq.pop();
		
		if (visited[p][node][horse]) {
			continue;
		}
		
		visited[p][node][horse] = true;
		
//		printf("# %d %d %d %lld\n", p, node, horse, d);
		
		for (int i = 0; i < edge[node].size(); i++) {
			if (!horse && s.count(node)) {
				if (d + edge[node][i].second / 2 < dis[p][edge[node][i].first][1]) {
					dis[p][edge[node][i].first][1] = d + edge[node][i].second / 2;
					pq.push({-dis[p][edge[node][i].first][1], {edge[node][i].first, 1}});
				}
			}
			
			int new_dis = edge[node][i].second;
			if (horse) {
				new_dis /= 2;
			}
			
			if (d + new_dis < dis[p][edge[node][i].first][horse]) {
				dis[p][edge[node][i].first][horse] = d + new_dis;
				pq.push({-dis[p][edge[node][i].first][horse], {edge[node][i].first, horse}});
			}
		}
	}
}

void solve() {
	ans = 4e18;
	scanf("%d %d %d", &n, &m, &h);
	s.clear();
	for (int i = 1; i <= n; i++) {
		dis[0][i][0] = dis[1][i][0] = dis[0][i][1] = dis[1][i][1] = 4e18;
		visited[0][i][0] = visited[1][i][0] = visited[0][i][1] = visited[1][i][1] = false;
		edge[i].clear();
	}
	
	for (int i = 0; i < h; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	
	dij(0);
	dij(1);
	
	for (int i = 1; i <= n; i++) {
//		printf("%d %lld %lld %lld %lld\n", i, dis[0][i][0], dis[0][i][1], dis[1][i][0], dis[1][i][1]);
		ans = min(ans, max(min(dis[0][i][0], dis[0][i][1]), min(dis[1][i][0], dis[1][i][1])));
	}
	
	printf("%lld\n", ans > 1e18 ? -1 : ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}