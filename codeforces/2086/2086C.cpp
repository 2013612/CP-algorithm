#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> a, b, c;

void solve() {
	scanf("%d", &n);
	a.resize(n + 1);
	b.resize(n + 1);
	c.resize(n + 1);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		c[i] = 0;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		
		int cur = b[i];
		
		while (c[cur] != cur) {
			c[cur] = cur;
			cur = a[cur];
			ans++;
		}
		
		printf("%d ", ans);
	}
	
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}