#include<iostream>
using namespace std;

long long N, K, ans;

long long cal(long long x) {
	int a[10];
	for (int i = 0; i <= 9; i++) {
		a[i] = 0;
	}
	long long temp = x;
	while (temp > 0) {
		a[temp % 10]++;
		temp /= 10;
	}
	long long g1 = 0;
	long long g2 = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j < a[i]; j++) {
			g2 = g2 * 10 + i;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) {
			g1 = g1 * 10 + i;
		}
	}
	return g1 - g2;
}

int main() {
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < K; i++) {
		N = cal(N);
	}
	printf("%lld\n", N);
	return 0;
}
