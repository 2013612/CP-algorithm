#include<iostream>
#include<queue>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
string p = "^<v>";

int h, w;
string g[1003];

bool in(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
	scanf("%d %d", &h, &w);
	
	for (int i = 0; i < h; i++) {
		cin >> g[i];
	}
	
	queue<pair<int, int>> q;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (g[i][j] == 'E') {
				q.push({i, j});
			}
		}
	}
	
	while (!q.empty()) {
		auto [u, v] = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nu = u + x[i];
			int nv = v + y[i];
			if (in(nu, nv) && g[nu][nv] == '.') {
				g[nu][nv] = p[i];
				q.push({nu, nv});
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		cout << g[i] << endl;
	}
	
	return 0;
}