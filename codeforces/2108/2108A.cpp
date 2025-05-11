#include<bits/stdc++.h>
using namespace std;

int n, ans, a[300005];

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += abs(n - 2 * i + 1);
	}
	
	printf("%d\n", ans / 2 + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}