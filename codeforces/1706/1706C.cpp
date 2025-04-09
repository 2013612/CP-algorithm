#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long long ans, a[200006];

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	if (n & 1) {
		for (int i = 1; i < n - 1; i += 2) {
			ans += max(0ll, max(a[i - 1], a[i + 1]) + 1 - a[i]);
		}
	} else {
		ans = 4e18;
		vector<long long> pre(n / 2, 0);
		vector<long long> suf(n / 2, 0);
		
		for (int i = 1; i < n - 1; i += 2) {
			pre[(i + 1) / 2] = pre[(i + 1) / 2 - 1] + max(0ll, max(a[i - 1], a[i + 1]) + 1 - a[i]);
		}
		
		for (int i = n - 2; i > 1; i -= 2) {
			suf[i / 2 - 1] = suf[i / 2] + max(0ll, max(a[i - 1], a[i + 1]) + 1 - a[i]);
		}
		
		for (int i = 0; i < n / 2; i++) {
			ans = min(ans, pre[i] + suf[i]);
		}
	}
	
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