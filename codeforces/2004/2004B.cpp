#include<iostream>
using namespace std;

int l, r, L, R;

void solve() {
	scanf("%d %d", &l, &r);
	scanf("%d %d", &L, &R);
	if (l > L) {
		swap(l, L);
		swap(r, R);
	}
	int ans = 0;
	if (r + 1 < L) {
		ans = 1;
	} else if (r + 1 == L) {
		ans = 1;
	} else if (L > l && R > r) {
		ans = r - L + 2;
	} else if (L > l && R == r) {
		ans = R - L + 1;
	} else if (L > l && R < r) {
		ans = R - L + 2;
	} else if (L == l && R > r) {
		ans = r - L + 1;
	} else if (L == l && R == r) {
		ans = R - L;
	} else {
		ans = R - L + 1;
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