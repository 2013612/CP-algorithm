#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, x;
long long ans[300005][2];
vector<int> v[200005][2];
priority_queue<pair<long long, pair<int, int>>> pq;

int main() {
	scanf("%d %d %d", &n, &m, &x);
	
	for (int i = 1; i <= n; i++) {
		ans[i][0] = 2e18;
		ans[i][1] = 2e18;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a][0].push_back(b);
		v[b][1].push_back(a);
	}
	
	pq.push({0, {1, 0}});
	pq.push({-x, {1, 1}});
	
	while (!pq.empty()) {
		auto tp = pq.top();
		pq.pop();
		
		long long len = -tp.first;
		int node = tp.second.first;
		int rev = tp.second.second;
		
		if (ans[node][rev] < 1e18) {
			continue;
		}
		
		ans[node][rev] = len;
		
		for (auto q: v[node][rev]) {
			if (ans[q][rev] < 1e18) {
				continue;
			}
			pq.push({-(len + 1), {q, rev}});
		}
		
		for (auto q: v[node][1 - rev]) {
			if (ans[q][1 - rev] < 1e18) {
				continue;
			}
			pq.push({-(len + x + 1), {q, 1 - rev}});
		}
	}
	
	printf("%lld\n", min(ans[n][0], ans[n][1]));
	return 0;
}