#include<bits/stdc++.h>
using namespace std;

int n, a[500005];
long long ans;

void solve() {
	scanf("%d", &n);
	ans = 4e18;
	int last = 1e9;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (a[i] != last) {
			ans = min(ans, 1ll * (n - cnt) * last);
			cnt = 1;
			last = a[i];
		} else {
			cnt++;
		}
	}
	
	ans = min(ans, 1ll * (n - cnt) * last);
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}