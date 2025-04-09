#include<iostream>
using namespace std;
const int M = 1e9 + 7;

int n, k;
long long fac[200006];

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
	return (fac[n] * inv(fac[r])) % M * inv(fac[n - r]) % M;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 200003; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	scanf("%d %d", &n, &k);
	printf("%lld\n", ncr(n + k - 1, n - 1));
	return 0;
}
