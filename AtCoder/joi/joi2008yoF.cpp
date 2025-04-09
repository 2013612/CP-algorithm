#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int n, k, d[103][103];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 103; i++) {
		for (int j = 0; j < 103; j++) {
			d[i][j] = 1e9;
		}
	}
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int a, b;
			scanf("%d %d", &a, &b);
			priority_queue<pii, vector<pii>, greater<pii>> pq;
			int dis[103];
			bool vis[103];
			for (int j = 0; j <= n; j++) {
				dis[j] = 2e9;
				vis[j] = false;
			}
			pq.push({0, a});
			while (!pq.empty()) {
				int e = pq.top().first;
				int s = pq.top().second;
				pq.pop();
				if (vis[s]) {
					continue;
				}
				vis[s] = true;
				for (int j = 1; j <= n; j++) {
					if (d[s][j] < 1e8) {
						dis[j] = min(dis[j], e + d[s][j]);
						pq.push({dis[j], j});
					}
				}
			}
			if (vis[b]) {
				printf("%d\n", dis[b]);
			} else {
				printf("-1\n");
			}
		} else {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			d[a][b] = min(d[a][b], c);
			d[b][a] = d[a][b];
		}
	}
	return 0;
}
