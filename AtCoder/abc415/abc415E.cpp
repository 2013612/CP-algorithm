#include<bits/stdc++.h>
using namespace std;

int h, w, p[300005], ans;
vector<vector<long long>> v;
queue<pair<int, int>> q;

bool f(long long x) {
	vector<vector<long long>> g(h, vector<long long>(w, -1ll));
	g[0][0] = x + v[0][0] - p[0];
	
	for (int i = 0; i < h + w - 2; i++) {
		for (int j = max(0, i - w + 1); j <= min(h - 1, i); j++) {
//			printf("%d %d\n", j, i - j);
			if (g[j][i - j] < 0) {
				continue;
			}
			
			if (j + 1 < h) {
				g[j + 1][i - j] = max(g[j + 1][i - j], g[j][i - j] + v[j + 1][i - j] - p[i + 1]);
			}
			
			if (i - j + 1 < w) {
				g[j][i - j + 1] = max(g[j][i - j + 1], g[j][i - j] + v[j][i - j + 1] - p[i + 1]);
			}
		}
	}
	
	return g[h - 1][w - 1] >= 0;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		v.push_back(vector<long long>(w, 0ll));
		for (int j = 0; j < w; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	
	for (int i = 0; i < h + w - 1; i++) {
		scanf("%d", &p[i]);
	}
	
	long long l = -1, r = 1e15;
	
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		
//		printf("%lld\n", mid);
		if (f(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	printf("%lld\n", r);
	
	return 0;
}