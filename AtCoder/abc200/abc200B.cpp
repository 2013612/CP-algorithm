#include<iostream>
using namespace std;

long long N, K;
int main() {
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < K; i++) {
		if (N % 200 == 0) {
			N /= 200;
		} else {
			N = N * 1000 + 200;
		}
	}
	printf("%lld\n", N);
	return 0;
}
