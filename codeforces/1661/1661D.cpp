#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
long long b[600006], ans, a[600006];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	long long p = 0, q = 0;
	for (int i = n - 1; i >= k - 1; i--) {
		p -= q;
		b[i] -= p;
		if (b[i] > 0) {
			a[i] = (b[i] + k - 1) / k;
			ans += a[i];
		}
		p += a[i] * k;
		q += a[i] - a[i + k];
	}
	for (int i = k - 2; i >= 0; i--) {
		p -= q;
		b[i] -= p;
		if (b[i] > 0) {
			a[i] = (b[i] + i) / (i + 1);
			ans += a[i];
		}
		p += a[i] * (i + 1);
		q += a[i] - a[i + k];
	}
	printf("%lld\n", ans);
	return 0;
}
