#include<iostream>
using namespace std;
const int M = 1000000007;

int n, q, a[200006], c[200006], pre[200006];
long long ans;

long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return a * pow(a, b - 1) % M;
	} else {
		long long t = pow(a, b / 2);
		return t * t % M;
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 2; i <= n; i++) {
		pre[i] = (pre[i - 1] + pow(a[i - 1], a[i])) % M;
	}
	c[0] = c[q + 1] = 1;
	for (int i = 1; i <= q + 1; i++) {
		ans = (ans + pre[max(c[i - 1], c[i])] - pre[min(c[i - 1], c[i])]) % M;
	}
	printf("%lld\n", (ans + M) % M);
	return 0;
}
