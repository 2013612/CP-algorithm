#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int v, e, r, ans[100006];
bool vis[100006];
vector<pii> g[100006];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
	scanf("%d %d %d", &v, &e, &r);
	for (int i = 0; i < v; i++) {
		ans[i] = 2e9;
	}
	for (int i = 0; i < e; i++) {
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		g[s].push_back({t, d});
	}
	ans[r] = 0;
	pq.push({0, r});
	while (!pq.empty()) {
		int d = pq.top().first;
		int s = pq.top().second;
		pq.pop();
		if (vis[s]) {
			continue;
		}
		vis[s] = true;
		for (auto x : g[s]) {
			ans[x.first] = min(ans[x.first], d + x.second);
			pq.push({ans[x.first], x.first});
		}
	}
	for (int i = 0; i < v; i++) {
		if (!vis[i]) {
			printf("INF\n");
		} else {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}

