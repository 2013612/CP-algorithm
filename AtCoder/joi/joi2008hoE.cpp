#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
 
int w, h, n, a[1004][4], imos[2010][2010], ans;
vector<int> x, y;

void bfs(int u, int v) {
	queue<pii> q;
	q.push({u, v});
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (imos[a][b] != 0) {
			continue;
		}
		imos[a][b] = -1;
		if (a > 0 && imos[a - 1][b] == 0) {
			q.push({a - 1, b});
		}
		if (b > 0 && imos[a][b - 1] == 0) {
			q.push({a, b - 1});
		}
		if (a < x.size() - 2 && imos[a + 1][b] == 0) {
			q.push({a + 1, b});
		}
		if (b < y.size() - 2 && imos[a][b + 1] == 0) {
			q.push({a, b + 1});
		}
	}
}
 
int main() {
	scanf("%d %d", &w, &h);
	scanf("%d", &n);
	x.push_back(0);
	x.push_back(w);
	y.push_back(0);
	y.push_back(h);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		x.push_back(a[i][0]);
		x.push_back(a[i][2]);
		y.push_back(a[i][1]);
		y.push_back(a[i][3]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for (int i = 0; i < n; i++) {
		int x1 = lower_bound(x.begin(), x.end(), a[i][0]) - x.begin();
		int y1 = lower_bound(y.begin(), y.end(), a[i][1]) - y.begin();
		int x2 = lower_bound(x.begin(), x.end(), a[i][2]) - x.begin();
		int y2 = lower_bound(y.begin(), y.end(), a[i][3]) - y.begin();
		imos[x1][y1]++;
		imos[x1][y2]--;
		imos[x2][y1]--;
		imos[x2][y2]++;
	}
	for (int i = 0; i < y.size(); i++) {
		for (int j = 1; j < x.size(); j++) {
			imos[j][i] += imos[j - 1][i];
		}
	}
	for (int i = 0; i < x.size(); i++) {
		for (int j = 1; j < y.size(); j++) {
			imos[i][j] += imos[i][j - 1];
		}
	}
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = 0; j < y.size() - 1; j++) {
			if (imos[i][j] == 0) {
				ans++;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
