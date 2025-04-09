#include<iostream>
using namespace std;
const int M = 1e9 + 7;

int x, y, a, b;
long long fac[2000007];

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

long long inv(long long a) {
	return pow(a, M - 2);
}

long long ncr(long long n, long long r) {
	if (r == 0) {
		return 1;
	}
	return (fac[n] * inv(fac[r])) % M * inv(fac[n - r]) % M;
}

int main() {
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= 2000000; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	scanf("%d %d", &x, &y);
	a = (x + y) / 3;
	b = y - a;
	a = a - b;
	if (a < 0 || b < 0 || 2 * a + b != x || a + 2 * b != y) {
		printf("0\n");
		return 0;
	}
	printf("%lld\n", ncr(a + b, a));
	return 0;
}
