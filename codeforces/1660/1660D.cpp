#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, ans, a[200006], l, r;

void f(int st, int ed) {
	int sign = 1;
	int cnt = 0;
	for (int i = st; i < ed; i++) {
		sign *= a[i] / abs(a[i]);
		if (abs(a[i]) == 2) {
			cnt++;
		}
	}
	if (sign == -1) {
		int b1 = cnt;
		int b2 = cnt;
		for (int i = st; i < ed; i++) {
			if (abs(a[i]) == 2) {
				b1--;
			}
			if (a[i] < 0) {
				if (b1 > ans) {
					ans = b1;
					l = i + 1;
					r = n - ed;
				}
				break;
			}
		}
		for (int i = ed - 1; i >= st; i--) {
			if (abs(a[i]) == 2) {
				b2--;
			}
			if (a[i] < 0) {
				if (b2 > ans) {
					ans = b2;
					l = st;
					r = n - i;
				}
				break;
			}
		}
	} else {
		if (cnt > ans) {
			ans = cnt;
			l = st;
			r = n - ed;
		}
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 0;
	ans = 0;
	l = n;
	r = 0;
	int st = -1;
	for (int i = 0; i <= n; i++) {
		if (a[i] == 0) {
			f(st + 1, i);
			st = i;
		}
	}
	printf("%d %d\n", l, r);
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
