#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int v, e, ans;
bool a[10005];
vector<pii> edge[10005];
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
int main() {
	scanf("%d %d", &v, &e);
	int n1, n2, len = 1e9;
	for (int i = 0; i < e; i++) {
		int s, t, w;
		scanf("%d %d %d", &s, &t, &w);
		edge[s].push_back({t, w});
		edge[t].push_back({s, w});
		if (w < len) {
			len = w;
			n1 = s;
			n2 = t;
		}
	}
	if (e == 0) {
		printf("0\n");
		return 0;
	}
	pq.push({len, {n1, n2}});
	while (!pq.empty()) {
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		int len = pq.top().first;
		pq.pop();
		if (a[n1] && a[n2]) {
			continue;
		}
		ans += len;
		if (!a[n1]) {
			for (auto x:edge[n1]) {
				if (!a[x.first]) {
					pq.push({x.second, {n1, x.first}});
				}
			}
		}
		a[n1] = true;
		if (!a[n2]) {
			for (auto x:edge[n2]) {
				if (!a[x.first]) {
					pq.push({x.second, {n2, x.first}});
				}
			}
		}
		a[n2] = true;
	}
	printf("%d\n", ans);
	return 0;
}
