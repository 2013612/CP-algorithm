#include<iostream>
using namespace std;

const int K = 998244353;
int N, M;
long long a[200006][50], fac[200006], ans;

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 1) {
		return a * power(a, b - 1) % K;
	} else {
		long long temp = power(a, b / 2);
		return temp * temp % K;
	}
}

long long inv(long long a) {
	return power(a, K - 2);
}

int main() {
	scanf("%d %d", &N, &M);
	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = (fac[i - 1] * i) % K;
	}
	for (int i = 1; i <= M; i++) {
		a[i][1] = 1;
	}
	for (int i = M / 2; i >= 1; i--) {
		for (int j = 2; j <= 20; j++) {
			for (int k = 2; i * k <= M; k++) {
				a[i][j] = (a[i][j] + a[i * k][j - 1]) % K;
			}
		}
	}
	for (int i = 1; i <= 20; i++) {
		long long sum = 0;
		for (int j = 1; j <= M; j++) {
			sum = (sum + a[j][i]) % K;
		}
		long long com = (fac[N - 1] * inv(fac[i - 1]) % K) * inv(fac[N - i]) % K;
		ans = (ans + com * sum % K) % K;
	}
	printf("%lld\n", ans);
	return 0;
}
