#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, a[100006], ans;

void solve() {
	ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + 2 * n);
	for (int i = 0; i < n; i++) {
		ans += a[2 * i];
	}
	
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}