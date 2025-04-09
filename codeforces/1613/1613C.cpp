#include<iostream>
using namespace std;

int t, n;
long long h, a[103];

bool can(long long d) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += min(a[i] - a[i - 1], d);
	}
	return sum >= h;
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %lld", &n, &h);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		a[n] = 2e18;
		long long left = 1;
		long long right = 2e18;
		while (left < right) {
			long long mid = (left + right) / 2;
			if (can(mid)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		printf("%lld\n", left);
	}
	return 0;
}
