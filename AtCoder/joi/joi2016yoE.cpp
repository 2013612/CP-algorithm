#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
typedef pair<long long, long long> pll;

int n, m, k, s, p, q;
long long dis[100006], d[100006];
bool v[100006];
vector<pll> e[100006];
priority_queue<pll, vector<pll>, greater<pll>> pq;
int main() {
	scanf("%d %d %d %d", &n, &m, &k, &s);
	scanf("%d %d", &p, &q);
	for (int i = 0; i <= n; i++) {
		d[i] = -1;
		dis[i] = 1e18;
	}
	dis[1] = 0;
	queue<int> mq;
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		d[t] = 0;
		mq.push(t);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[b].push_back({a, -1});
		e[a].push_back({b, -1});
	}
	while (!mq.empty()) {
		int t = mq.front();
		mq.pop();
		for (int i = 0; i < e[t].size(); i++) {
			if (d[e[t][i].first] == -1) {
				d[e[t][i].first] = d[t] + 1;
				mq.push(e[t][i].first);
			}
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < e[j].size(); i++) {
			if (d[e[j][i].first] == 0) {
				e[j][i].second = 1e18;
			} else if (e[j][i].first == n) {
				e[j][i].second = 0;
			} else {
				e[j][i].second = d[e[j][i].first] <= s ? q : p;
			}
		}
	}
	pq.push({0, 1});
	while (!pq.empty()) {
		long long z = pq.top().first;
		long long s = pq.top().second;
		pq.pop();
		if (v[s]) {
			continue;
		}
		v[s] = true;
		for (auto x : e[s]) {
			if (d[x.first] != 0 && !v[x.first]) {
				dis[x.first] = min(dis[x.first], z + x.second);
				pq.push({dis[x.first], x.first});
			}
		}
	}
	printf("%lld\n", dis[n]);
	return 0;
}
