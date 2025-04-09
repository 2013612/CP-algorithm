#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long t, n, a, b, x, y, z, ans;

long long cal(long long x_cnt, long long y_cnt) {
	return x_cnt * x + y_cnt * y;
}

long long cal(long long x_cnt, long long y_cnt, long long z_cnt) {
	return cal(x_cnt, y_cnt) + z_cnt * z;
}

long long find(long long b_cnt) {
	long long q = (n - b * b_cnt);
	if (x * a <= y) {
		return cal(q, 0, b_cnt);
	} else {
		long long p = q / a;
		return cal(q - p * a, p, b_cnt);
	}
}

int main() {
	scanf("%lld", &t);
	while (t-- > 0) {
		scanf("%lld %lld %lld %lld %lld %lld", &n, &a, &b, &x, &y, &z);
		ans = 4e18;
		if (a > b) {
			swap(a, b);
			swap(y, z);
		}
		if (n < a) {
			ans = n * x;
			printf("%lld\n", ans);
			continue;
		} else if (n < b) {
			if (x * a <= y) {
				ans = cal(n, 0, 0);
			} else {
				long long p = n / a;
				ans = cal(n - p * a, p, 0);
			}
			printf("%lld\n", ans);
			continue;
		}
		long long l = 0, r = n / b;
		while (l < r) {
			long long mid = (l + r + 1) / 2;
			long long k1 = find(mid);
			long long k2 = find(mid - 1);
			if (k1 <= k2) {
				l = mid;
				ans = min(ans, k1);
			} else {
				r = mid - 1;
				ans = min(ans, k2);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
