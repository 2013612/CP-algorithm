#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, a[300006], b[300006], m, k;
priority_queue<pair<long long, int>> pq;

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	pq = priority_queue<pair<long long, int>>();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pq.push({-a[i], i});
		b[i] = 0;
	}
	
	int cnt = k;
	
	while (cnt > 0) {
		auto [x, y] = pq.top();
		pq.pop();
		b[y] = min(cnt, m);
		cnt -= b[y];
	}
	
	long long ans = 0;
	cnt = k;
	for (int i = 0; i < n; i++) {
		if (b[i] > 0) {
//			printf("%lld %d %d %d %d\n", ans, i, a[i], b[i], cnt);
			ans += 1ll * b[i] * a[i] + 1ll * (cnt - b[i]) * b[i];
			cnt -= b[i];
			
		}
		
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}