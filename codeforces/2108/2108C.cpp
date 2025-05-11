#include<bits/stdc++.h>
using namespace std;

int n, ans, a[300005];
bool vis[200005];
priority_queue<pair<int, int>> pq, can;

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		vis[i] = false;
		scanf("%d", &a[i]);
		pq.push({a[i], i});
	}
	
	while (!pq.empty()) {
		auto [x, y] = pq.top();
		pq.pop();
		
		if (vis[y]) {
			continue;
		}
		
		while (!can.empty() && can.top().first == x) {
			auto [u, v] = can.top();
			can.pop();
			
			vis[v] = true;
			
			if (v - 1 >= 0 && !vis[v - 1]) {
				can.push({a[v - 1], v - 1});
			}
			
			if (v + 1 < n && !vis[v + 1]) {
				can.push({a[v + 1], v + 1});
			}
		}
		
		if (!vis[y]) {
			ans++;
			
			if (y - 1 >= 0 && !vis[y - 1]) {
				can.push({a[y - 1], y - 1});
			}
			
			if (y + 1 < n && !vis[y + 1]) {
				can.push({a[y + 1], y + 1});
			}
		}
		
		vis[y] = true;
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}