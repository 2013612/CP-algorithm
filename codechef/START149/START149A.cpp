#include<iostream>
#include<algorithm>
using namespace std;

int n, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i += 2) {
		if (i == n - 1) {
			ans += a[i];
			continue;
		}
		if (a[i] < 0 && a[i + 1] <= 0) {
			ans += -(a[i] + a[i + 1]);
		} else if (a[i] < 0 && a[i] + a[i + 1] < 0) {
			ans += -(a[i] + a[i + 1]);
		} else {
			ans += a[i] + a[i + 1];
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