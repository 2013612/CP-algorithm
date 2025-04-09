#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	int l = 0, r = n - 1, last = 0;
	while (l <= r) {
		if (a[l] <= a[r]) {
			if (a[l] >= last) {
				ans++;
				last = a[l];
			}
			l++;
		} else {
			if (a[r] >= last) {
				ans++;
				last = a[r];
			}
			r--;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
