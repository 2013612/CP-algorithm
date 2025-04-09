#include<iostream>
#include<queue>
using namespace std;

const int u[4] = {1, 0, -1, 0};
const int v[4] = {0, 1, 0, -1};

int h, w, dis[1003][1003], x1, y1, x2, y2;
bool vis[1003][1003];
string s[1003];

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

int main() {
	scanf("%d %d", &h, &w);
	
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dis[i][j] = 1e9;
		}
	}
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	
	dis[x1][y1] = 0;
	
	deque<pair<int, int>> q;
	q.push_back({x1, y1});
	
	while (!vis[x2][y2]) {
		auto [x, y] = q.front();
		q.pop_front();
		
		if (vis[x][y]) {
			continue;
		}
		
		vis[x][y] = true;
		
		for (int i = 0; i < 4; i++) {
			int new_u = x + u[i];
			int new_v = y + v[i];
			
			if (!check(new_u, new_v)) {
				continue;
			}
			
			if (s[new_u][new_v] == '.') {
				if (vis[new_u][new_v] || dis[new_u][new_v] <= dis[x][y]) {
					continue;
				}
				
				dis[new_u][new_v] = dis[x][y];
				q.push_front({new_u, new_v});
				continue;
			}
			
			if (!vis[new_u][new_v] && dis[new_u][new_v] > dis[x][y] + 1) {
				dis[new_u][new_v] = dis[x][y] + 1;
				q.push_back({new_u, new_v});
			}
			
			new_u += u[i];
			new_v += v[i];
			if (!check(new_u, new_v)) {
				continue;
			}
			
			if (!vis[new_u][new_v] && dis[new_u][new_v] > dis[x][y] + 1) {
				dis[new_u][new_v] = dis[x][y] + 1;
				q.push_back({new_u, new_v});
			}
		}
	}
	
	printf("%d\n", dis[x2][y2]);
	
	return 0;
}