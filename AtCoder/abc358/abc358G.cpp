#include<iostream>
#include<queue>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int h, w, k, s[2], a[53][53];
bool visit[53][53][1500];
long long ans, maxi[53][53][1500];

int main() {
	scanf("%d %d %d", &h, &w, &k);
	scanf("%d %d", &s[0], &s[1]);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{s[0], s[1]}, 0});
	while (!q.empty()) {
		int u = q.front().first.first;
		int v = q.front().first.second;
		int dis = q.front().second;
		q.pop();
		if (dis > min(k, 1300)) {
			break;
		}
		ans = max(ans, maxi[u][v][dis] + 1ll * (k - dis) * a[u][v]);
		
		for (int i = 0; i < 4; i++) {
			int new_u = u + x[i];
			int new_v = v + y[i];
			if (a[new_u][new_v] == 0) {
				continue;
			}
			
			maxi[new_u][new_v][dis + 1] = max(maxi[new_u][new_v][dis + 1], maxi[u][v][dis] + a[new_u][new_v]);
			
			if (!visit[new_u][new_v][dis + 1]) {
				visit[new_u][new_v][dis + 1] = true;
				q.push({{new_u, new_v}, dis + 1});
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
