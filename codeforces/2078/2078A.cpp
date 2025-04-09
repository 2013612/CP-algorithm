#include<bits/stdc++.h>
using namespace std;

int n, x, ans, a[300005];

void solve() {
	scanf("%d %d", &n, &x);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	
	if (ans == x * n) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}