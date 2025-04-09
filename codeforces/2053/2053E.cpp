#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, a[200006], dis[200006];

void solve() {
	scanf("%d", &n);
	
	vector<int> g[200006];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int leaf = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
		if (g[i].size() == 1) {
			q.push(i);
			dis[i] = 0;
			leaf++;
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int x: g[cur]) {
			if (dis[x] > 1e8) {
				dis[x] = dis[cur] + 1;
				q.push(x);
			}
		}
	}
	
	long long ans = 1ll * leaf * (n - leaf);
	long long cnt1 = 0;
	long long cnt2 = 0;
	long long cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] > 0) {
			for (int j = 0; j < g[i].size(); j++) {
				if (dis[g[i][j]] > 1) {
					printf("& %d %d\n", i, g[i][j]);
					break;
				}
				
				if (j == g[i].size() - 1) {
					printf("# %d\n", i);
					if (dis[i] == 1) {
						cnt1++;
					} else {
						cnt2++;
					}
				}
			}
		}
		
		if (dis[i] <= 1) {
			cnt3++;
		}
	}
	
	printf("### %lld %lld\n", leaf, cnt2);
	ans += cnt1 * (n - cnt3) + cnt2 * (n - cnt3 - 1);
	
	printf("@ %lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}