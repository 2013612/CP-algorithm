#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int n, k, c[5006], r[5006], dis[5006];
vector<int> e[5006];
bool v[5006];
vector<pii> ne[5006];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c[i], &r[i]);
		dis[i] = 1e9;
	}
	dis[1] = 0;
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int d[5006];
		for (int j = 1; j <= n; j++) {
			d[j] = -1;
		}
		d[i] = 0;
		queue<int> mq;
		mq.push(i);
		while (!mq.empty() && d[mq.front()] <= r[i]) {
			int a = mq.front();
			mq.pop();
			ne[i].push_back({a, c[i]});
			for (auto x:e[a]) {
				if (d[x] == -1) {
					d[x] = d[a] + 1;
					mq.push(x);
				}
			}
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});
	while (!pq.empty()) {
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (v[node]) {
			continue;
		}
		v[node] = true;
		for (auto x:ne[node]) {
			if (!v[x.first]) {
				if (dis[x.first] > d + x.second) {
					dis[x.first] = d + x.second;
					pq.push({dis[x.first], x.first});
				}
			}
		}
	}
	printf("%d\n", dis[n]);
	return 0;
}
