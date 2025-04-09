#include<iostream>
using namespace std;

const int K = 1000000007;
long long a[600006], N, M, ans;

long long power(long long x, long long y) {
	if (y == 0) return 1;
	if (y % 2 == 0) {
		long long temp = power(x, y/2) % K;
		return temp * temp % K;
	} else {
		return x * power(x, y - 1) % K;
	}
}

long long inv(long long x) {
	return power(x, K - 2);
}

int main() {
	scanf("%lld %lld", &N, &M);
	a[0] = 1;
	for (int i = 1; i <= M; i++) {
		a[i] = i * a[i - 1] % K;
	}
	ans = a[M] * a[M - N] % K;
	ans = ans * ans % K;
	ans = ans / 2 % K;
	ans = (ans + K) % K;
	printf("%lld\n", ans);
	
	return 0;
}
