#include<bits/stdc++.h>
using namespace std;

int n, a[300005];
long long ans;

void solve() {
	scanf("%d", &n);
	
	ans = 0;
	int cur = 0;
	
	while (cur < n) {
		cur = cur * 2 + 1;
		ans++;
	}
	
	printf("%lld\n", ans * 2 + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}