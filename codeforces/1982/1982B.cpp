#include<iostream>
using namespace std;

void solve() {
	long long x, k, y;
	scanf("%lld %lld %lld", &x, &y, &k);
	while (x > 1) {
		int r = y - x % y;
		if (k < r) {
			x += k;
			k = 0;
			break;
		}
		x += r;
		while (x % y == 0) {
			x /= y;
		}
		k -= r;
	}
	long long temp = k % (y - 1);
	printf("%lld\n", x + temp);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}