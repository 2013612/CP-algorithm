#include<iostream>
#include<algorithm>
using namespace std;

int n, a[200006], k;
long long ans;

void solve() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	ans = 0;
	
	for (int i = 1; i < n; i += 2) {
		int diff = a[i - 1] - a[i];
		diff = min(diff, k);
		k -= diff;
		ans += a[i - 1] - a[i] - diff;
	}
	
	if (n & 1) {
		ans += a[n - 1];
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