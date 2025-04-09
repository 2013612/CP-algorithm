#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 1e9;
	sort(a, a + n);
	
	for (int i = 0; i < n - 1; i++) {
		int ind = lower_bound(a, a + n, a[i] + a[i + 1]) - a;
		ans = min(i + n - ind, ans);
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