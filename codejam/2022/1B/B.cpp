#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<long long, long long> pll;
typedef pair<long long, pll> plll;

void solve() {
	int n, p;
	scanf("%d %d", &n, &p);
	long long a[1004][2];
	long long ans[1004][2];
	bool visited[1004][2];
	priority_queue<plll, vector<plll>, greater<plll>> pq;
	for (int i = 0; i < n; i++) {
		a[i][0] = 1e18;
		a[i][1] = 0;
		ans[i][0] = ans[i][1] = 1e18;
		visited[i][0] = visited[i][1] = false;
		for (int j = 0; j < p; j++) {
			long long k;
			scanf("%lld", &k);
			a[i][0] = min(a[i][0], k);
			a[i][1] = max(a[i][1], k);
		}
	}
	pq.push({a[0][1], {0, 1}});
	while (ans[n - 1][0] > 1e17 && ans[n - 1][1] > 1e17) {
		auto [x, y] = pq.top();
		pq.pop();
		if (visited[y.first][y.second]) {
			continue;
		}
		visited[y.first][y.second] = true;
		ans[y.first][y.second] = x;
		if (!visited[y.first + 1][0]) {
			pq.push({x + a[y.first + 1][1] - a[y.first + 1][0] + abs(a[y.first][y.second]- a[y.first + 1][1]), {y.first + 1, 0}});
		}
		if (!visited[y.first + 1][1]) {
			pq.push({x + a[y.first + 1][1] - a[y.first + 1][0] + abs(a[y.first][y.second]- a[y.first + 1][0]), {y.first + 1, 1}});
		}
	}
	printf("%lld\n", min(ans[n - 1][0], ans[n - 1][1]));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
