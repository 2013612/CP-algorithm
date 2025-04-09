#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, t[100006], ans[100006];

long long f(long long x, long long y) {
	long long temp = x * (1ll << (y + 1)) + (1ll << y);
	//printf("@%lld %lld %lld\n", x, y, temp);
	return temp;
}

int main() {
	scanf("%lld", &n);
//	n = 100000;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
//		if (i & 1) {
//			t[i] = 0;
//		} else {
//			t[i] = 40;
//		}
		long long l = 0, r = (1ll << (41 - t[i])) * (i + 1);
		while (l < r) {
			//printf("$%lld %lld\n", l, r);
			long long mid = (l + r) / 2;
			if (f(mid, t[i]) > ans[i - 1]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans[i] = f(l, t[i]);
	}
	printf("%lld\n", ans[n - 1]);
	return 0;
}
