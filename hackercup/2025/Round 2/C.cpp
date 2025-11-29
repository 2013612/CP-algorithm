#include<bits/stdc++.h>
using namespace std;

int n, k, m, dis[500005];
vector<int> route[500005];
set<int> ind[500005];
map<int, int> rev[500005];
set<int> station_have_route[500005];

void solve(bool show) {
	scanf("%d %d %d", &n, &k, &m);

	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
		station_have_route[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int cnt = 0;
		scanf("%d", &cnt);
		ind[i].clear();
		route[i].clear();
		rev[i].clear();
		for (int j = 0; j < cnt; j++) {
			int p;
			scanf("%d", &p);
			route[i].push_back(p);
			ind[i].insert(j);
			rev[i][p] = j;
			station_have_route[p].insert(i);
		}
	}

	// if (!show) {
	// 	return;
	// }

	// printf("%d %d %d\n", n, k, m);

	queue<int> q;
	q.push(1);
	dis[1] = 0;

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		// printf("!! %d\n", p);

		for (auto x: station_have_route[p]) {
			int station_ind = rev[x][p];
			auto u = ind[x].lower_bound(station_ind);
			vector<int> temp;
			while (u != ind[x].end() && *u <= station_ind + k) {
				// printf("@ %d %d\n", x, *u);
				int next_station = route[x][*u];
				if (dis[next_station] == -1) {
					dis[next_station] = dis[p] + 1;
					q.push(next_station);
				}

				temp.push_back(*u);
				u++;
			}

			for (auto y: temp) {
				ind[x].erase(y);
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1ll * dis[i] * i;
	}

	printf("%lld\n", ans);
}

int main() {
	time_t start = std::time(0);
	freopen("designing_paths_input (1).txt", "r", stdin);
	freopen("designing_paths_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve(i == 48 || i == 58 || i == 66 || i == 68);
	}

	time_t end = std::time(0);

	printf("%d\n", end - start);
	return 0;
}