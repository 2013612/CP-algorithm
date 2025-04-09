#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, ans, a[200006];

void solve() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] + a[i + 1]) {
			ans++;
		}
	}
	if (k == 1) {
		ans = (n - 1) / 2;
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