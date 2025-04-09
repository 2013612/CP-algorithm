#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;
long long ans, x;

void solve() {
	scanf("%d %d %lld", &n, &k, &x);
	a.resize(n);
	long long sum = 0;
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	
	k -= x / sum;
	
	x %= sum;
	
	for (int i = n - 1; i >= 0 && x > 0; i--) {
		x -= a[i];
		
		ans--;
	}
	
	ans += 1ll * k * n + 1;
	
	printf("%lld\n", max(ans, 0ll));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}