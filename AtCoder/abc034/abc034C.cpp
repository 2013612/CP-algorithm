#include<iostream>
using namespace std;
const int M = 1000000007;

int w, h;
long long fac[200006];

long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return a * pow(a, b - 1) % M;
	} else {
		long long temp = pow(a, b / 2);
		return temp * temp % M;
	}
}

long long inv(long long a) {
	return pow(a, M - 2);
}

long long ncr(long long n, long long r) {
	return (fac[n] * inv(fac[r])) % M * inv(fac[n - r]) % M;
}

int main() {
	fac[1] = 1;
	for (int i = 2; i <= 200003; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	scanf("%d %d", &w, &h);
	printf("%lld\n", ncr(w + h - 2, w - 1));
}
