#include<iostream>
using namespace std;

long long N, K, a[300006];

bool can(long long num) {
	long long sum = 0;
	for (int i = 1; i <= 300000; i++) {
		sum += (num - i % num) % num * a[i];
	}
	return sum <= K;
}

int main() {
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%lld", &temp);
		a[temp]++;
	}
	long long l = 1;
	long long r = 2e18;
	while (l < r) {
		long long mid = (l + r + 1) / 2;
		if (can(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}
