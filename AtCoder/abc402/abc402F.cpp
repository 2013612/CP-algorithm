#include<bits/stdc++.h>
using namespace std;

int n, m, a[30][30], ans, ten[50];
set<int> st[30], ed[30];

void f(int x, int y, int cur) {
	cur = (1ll * cur * 10 + a[x][y]) % m;
	
	if (x + y == n - 1) {
		int k = 1ll * cur * ten[n - 1] % m;
//		printf("%d %d %d %d\n", x, y, cur, k);
		st[x].insert(k);
		return;
	}
	
	if (x + 1 < n) {
		f(x + 1, y, cur);
	}
	
	if (y + 1 < n) {
		f(x, y + 1, cur);
	}
}

void g(int x, int y, int cur) {
	if (x + y == n - 1) {
//		printf("%d %d %d\n", x, y, cur);
		ed[x].insert(cur);
		return;
	}
	
	cur = (1ll * cur + 1ll * a[x][y] * ten[2 * (n - 1) - x - y]) % m;
	
	if (x - 1 >= 0) {
		g(x - 1, y, cur);
	}
	
	if (y - 1 >= 0) {
		g(x, y - 1, cur);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
//			a[i][j] = (i + j) % 10;
		}
	}
	
	ten[0] = 1;
	for (int i = 1; i <= 40; i++) {
		ten[i] = 1ll * ten[i - 1] * 10 % m;
	}
	
	f(0, 0, 0);
	g(n - 1, n - 1, 0);
	
	for (int i = 0; i < n; i++) {
//		printf("%d\n", i);
		for (auto x: st[i]) {
//			printf("%d\n", x);
			auto ptr = ed[i].upper_bound(m - x - 1);
			
			if (ptr == ed[i].begin()) {
				ptr = ed[i].end();
			}
			
			ptr--;
			
			ans = max(ans, (x + *ptr) % m);
//			printf("%d %d\n", x, *ptr);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}