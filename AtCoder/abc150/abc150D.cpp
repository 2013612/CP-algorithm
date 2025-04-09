#include<iostream>
using namespace std;

long long n, m, a[100006];

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main() {
	scanf("%lld %lld", &n, &m);
	long long l = 1;
	long long g = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i] /= 2;
		g = gcd(g, a[i]);
		l = lcm(l, a[i]);
	}
	long long k = l / g;
	if (k % 2 == 0) {
		printf("0\n");
	} else {
		printf("%lld\n", m / l - m / (2 * l));
	}
	return 0;
}
