#include<iostream>
using namespace std;

const int M = 998244353;

long long a, b, c, d, ans, fac[6000006];

long long pow(long long a, long long x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return a * pow(a, x - 1) % M;
	} else {
		long long p = pow(a, x / 2);
		return p * p % M;
	}
}

long long inv(long long a) {
	return pow(a, M - 2);
}

long long ncr(long long n, long long r) {
	if (n <= 0 || r <= 0) {
		return 1;
	}
	
	return (fac[n] * inv(fac[n - r]) % M) * inv(fac[r]) % M;
}

int main() {
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	
	fac[0] = 1;
	for (int i = 1; i <= 6e6; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	
	for (int i = 0; i <= b; i++) {
		long long s = ncr(a + i - 1, a - 1);
		
		s *= ncr(b + c + d - i, c);
		s %= M;
		
		ans += s;
		ans %= M;
	}
	
	printf("%lld\n", ans);
	return 0;
}