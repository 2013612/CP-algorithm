#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	ans = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int f = -1, s = -1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			f = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == a[i - 1]) {
			s = i - 1;
			break;
		}
	}
	if (f > 0 && f == s) {
		ans = 1;
	} else {
		ans = s - f;
	}
	ans = max(ans, 0);
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
