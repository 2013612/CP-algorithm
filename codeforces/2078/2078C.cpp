#include<bits/stdc++.h>
using namespace std;

int n, a[400005];
long long ans;

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + 2 * n);
	
	for (int i = 0; i < n - 1; i++) {
		ans -= a[i];
	}
	
	for (int i = n - 1; i < 2 * n; i++) {
		ans += a[i];
	}
	
	printf("%d %lld %d", a[2 * n - 1], ans, a[2 * n - 2]);
	for (int i = 0; i < n - 1; i++) {
		printf(" %d %d", a[i], a[n - 1 + i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}