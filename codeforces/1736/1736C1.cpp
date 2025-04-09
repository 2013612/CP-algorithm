#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t = 1;
int a[200006];

void solve() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = -1e9;
	int l = 1, r = 2;
	while (l <= n) {
		while (a[r] >= (r - l + 1)) {
			r++;
		}
		ans += r - l;
		l++;
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}