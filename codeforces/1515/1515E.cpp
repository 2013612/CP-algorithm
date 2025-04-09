#include<iostream>
using namespace std;

long long N, M, ans, fac[1004], mem[1004];

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return a * power(a, b - 1) % M;
	} else {
		long long temp = power(a, b / 2);
		return (temp * temp) % M;
	}
}

long long inv(long long a) {
	return power(a, M - 2) % M;
}

long long nCr(long long a, long long b) {
	return ((fac[a] * inv(fac[b]) % M) * inv(fac[a - b])) % M;
}

long long nHr(long long a, long long b) {
	return nCr(a + b - 1, a - 1) % M;
}

long long sol(long long a) {
	if (mem[a] > 0) {
		return mem[a];
	}
	//cout << a << endl;
	long long temp = 0;
	for (long long i = 2; i <= a - 1; i++) {
		long long fk = sol(i - 2) * sol(a - i) % M;
		fk = fk * nHr(a - i + 1, i - 2) % M;
		temp = (temp + fk) % M;
		fk = sol(i - 1) * sol(a - i - 1) % M;
		fk = fk * nHr(a - i, i - 1) % M;
		temp = (temp + fk) % M;
	}
	temp = (temp + (sol(a - 1) * 2) % M) % M;
	//cout << temp << endl;
	mem[a] = temp % M;
	return mem[a];
}

int main() {
	scanf("%lld %lld", &N, &M);
	fac[0] = 1;
	for (int i = 1; i <= 400; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
	mem[0] = 1;
	mem[1] = 1;
	mem[2] = 2;
	ans = sol(N);
	printf("%lld\n", ans);
}
