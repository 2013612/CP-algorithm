#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	if (n == -1) {
		return;
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		printf("? %d %d\n", l, mid);
		fflush(stdout);
		int cnt = 0;
		for (int i = l; i <= mid; i++) {
			scanf("%d", &a[i]);
			if (a[i] == -1) {
				return;
			}
			if (a[i] >= l && a[i] <= mid) {
				cnt++;
			}
		}
		if (cnt & 1) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("! %d\n", l);
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}