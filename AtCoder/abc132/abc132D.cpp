#include<iostream>
using namespace std;

const int M = 1000000007;

long long N, K, ans, fac[5004];

long long mod(long long a, long long pow, long long m) {
	if (pow == 0) {
		return 1;
	}
	if (pow % 2 == 0) {
		long long temp = mod(a, pow/2, m);
		return temp * temp % m;
	} else {
		return a * mod(a, pow - 1, m) % m;
	}
}

long long inv(long long a) {
	return mod(a, M - 2, M);
}

long long com(long long n, long long r) {
	//cout << n << " " << r << endl;
	if (r > n) {
		return 0;
	}
	long long value = fac[n]*inv(fac[r]) % M;
	//printf("!%lld %lld\n", fac[n], inv(fac[r]));
	value = value * inv(fac[n - r]) % M;
	//printf("@%lld\n", value);
	return value;
}

int main() {
	scanf("%lld %lld", &N, &K);
	long long blue = K;
	long long red = N - K;
	fac[0] = 1;
	for (int i = 1; i < 5000; i++) {
		fac[i] = fac[i - 1] * i % M;
		//cout << fac[i] << endl;
	}
	/*for (int i = blue; i >= 1; i--) {
		ans = com(red + 1, i) * mod(i, blue - i, M) % M;
		ans = (ans + M) % M;
		printf("%lld\n", ans);
	}*/
	for (int i = 1; i <= blue; i++) {
		//printf("%lld %lld\n", com(red + 1, i), mod(i, blue - i, M));
		ans = com(red + 1, i) * mod(i, blue - i, M) % M;
		ans = ans * inv(fac[blue - i]) % M;
		ans = (ans + M) % M;
		printf("%lld\n", ans);
	}
	return 0;
}
