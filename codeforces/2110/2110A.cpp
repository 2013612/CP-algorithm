#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;

void solve() {
	scanf("%d", &n);
	
	ans = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		if ((a[i] + a[n - 1]) % 2 == 0) {
			ans = i;
			break;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if ((a[i] + a[0]) % 2 == 0) {
			ans = min(ans, n - i - 1);
			break;
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}