#include<iostream>
using namespace std;

long long n, k, l, a[200006];

void solve() {
	scanf("%lld %lld %lld", &n, &k, &l);
	k *= 2;
	l *= 2;
	
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i] *= 2;
	}
	
	long long ans = a[0];
	long long cur = k;
	
	for (int i = 1; i < n; i++) {
		if (a[i] >= cur) {
			long long diff = max(a[i] - cur - ans, 0ll);
			ans += diff / 2;
			cur += diff / 2 + k;
		} else {
			long long pos = min(a[i] + ans, cur);
			cur = pos + k;
		}
	}
	
	printf("%lld\n", ans + max(l - cur, 0ll));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}