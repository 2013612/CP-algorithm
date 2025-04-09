#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006], ans;

void solve() {
	int l1, r1, l2, r2;
	scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
	if (l2 <= l1 && l1 <= r2) {
		ans = l1;
	} else if (l1 <= l2 && l2 <= r1) {
		ans = l2;
	} else {
		ans = l1 + l2;
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