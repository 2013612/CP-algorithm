#include<iostream>
using namespace std;

long long N, K;
int main() {
	scanf("%d %d", &N, &K);
	if (K * (K - 1) < N) {
		printf("NO\n");
		return 0;
	} else {
		printf("YES\n");
		for (long long i = 0; i < N; i++) {
			long long temp1 = i % K + 1;
			long long temp2 = (temp1 + i/K) % K + 1;
			printf("%lld %lld\n", temp1, temp2);
		}
	}
	return 0;
}
